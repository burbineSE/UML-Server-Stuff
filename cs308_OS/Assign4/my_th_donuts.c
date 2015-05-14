#include "project_header.h"

struct donut_ring shared_ring;
pthread_mutex_t   prod [NUMFLAVORS];
pthread_mutex_t   cons [NUMFLAVORS];
pthread_cond_t    prod_cond [NUMFLAVORS];
pthread_cond_t    cons_cond [NUMFLAVORS];
pthread_t         thread_id [NUMCONSUMERS+1], sig_wait_id;

int  main ( int argc, char *argv[] )
{
  int                 i, j, k, nsigs;
  struct timeval      randtime, first_time, last_time;
  struct sigaction    new_act;
  int                 arg_array[NUMCONSUMERS];
  sigset_t            all_signals;
  int                 sigs[] = { SIGBUS, SIGSEGV, SIGFPE };

  pthread_attr_t      thread_attr;
  struct sched_param  sched_struct;

  /**********************************************************************/
  /* INITIAL TIMESTAMP VALUE FOR PERFORMANCE MEASURE                    */
  /**********************************************************************/

  gettimeofday (&first_time, (struct timezone *) 0 );
  for ( i = 0; i < NUMCONSUMERS + 1; i++ ) {
    arg_array [i] = i;/** SET ARRAY OF ARGUMENT VALUES **/
  }

  /**********************************************************************/
  /* GENERAL PTHREAD MUTEX AND CONDITION INIT AND GLOBAL INIT           */
  /**********************************************************************/

  for ( i = 0; i < NUMFLAVORS; i++ ) {
    pthread_mutex_init ( &prod [i], NULL );
    pthread_mutex_init ( &cons [i], NULL );
    pthread_cond_init ( &prod_cond [i],  NULL );
    pthread_cond_init ( &cons_cond [i],  NULL );
    shared_ring.outptr [i] = 0;
    shared_ring.in_ptr [i] = 0;
    shared_ring.serial [i] = 0;
    shared_ring.spaces [i] = NUMSLOTS;
    shared_ring.donuts [i] = 0;
  }

  /**********************************************************************/
  /* SETUP FOR MANAGING THE SIGTERM SIGNAL, BLOCK ALL SIGNALS           */
  /**********************************************************************/

  sigfillset (&all_signals );
  nsigs = sizeof ( sigs ) / sizeof ( int );
  for ( i = 0; i < nsigs; i++ )
    sigdelset ( &all_signals, sigs [i] );
  sigprocmask ( SIG_BLOCK, &all_signals, NULL );
  sigfillset (&all_signals );
  for( i = 0; i <  nsigs; i++ ) {
    new_act.sa_handler = sig_handler;
    new_act.sa_mask = all_signals;
    new_act.sa_flags = 0;
    if ( sigaction ( sigs[i], &new_act, NULL ) == -1 ){
      perror("can't set signals: ");
      exit(1);
    }
  }
  printf ( "just before threads created\n" );

  /*********************************************************************/
  /* CREATE SIGNAL HANDLER THREAD, PRODUCER AND CONSUMERS              */
  /*********************************************************************/

  if ( pthread_create (&sig_wait_id, NULL, sig_waiter, NULL) != 0 ){
    printf ( "pthread_create failed " );
    exit ( 3 );
  }

  pthread_attr_init ( &thread_attr );
  pthread_attr_setinheritsched ( &thread_attr, PTHREAD_INHERIT_SCHED );

#ifdef  GLOBAL
  sched_struct.sched_priority = sched_get_priority_max(SCHED_OTHER);
  pthread_attr_setinheritsched ( &thread_attr, PTHREAD_EXPLICIT_SCHED );
  pthread_attr_setschedpolicy ( &thread_attr, SCHED_OTHER );
  pthread_attr_setschedparam ( &thread_attr, &sched_struct );  
  pthread_attr_setscope ( &thread_attr, PTHREAD_SCOPE_SYSTEM );
#endif

  if ( pthread_create (&thread_id[0], &thread_attr, producer, NULL ) != 0 ) {
    printf ( "pthread_create failed " );
    exit ( 3 );
  }

  for ( i = 1; i < NUMCONSUMERS + 1; i++ ) {
    if ( pthread_create ( &thread_id [i], &thread_attr, 
			  consumer, ( void * )&arg_array [i]) != 0 ){
      printf ( "pthread_create failed" );
      exit ( 3 );
    }
  }
  printf ( "just after threads created\n" );

  /*********************************************************************/
  /* WAIT FOR ALL CONSUMERS TO FINISH, SIGNAL WAITER WILL              */
  /* NOT FINISH UNLESS A SIGTERM ARRIVES AND WILL THEN EXIT            */
  /* THE ENTIRE PROCESS....OTHERWISE MAIN THREAD WILL EXIT             */
  /* THE PROCESS WHEN ALL CONSUMERS ARE FINISHED                       */
  /*********************************************************************/

  for ( i = 1; i < NUMCONSUMERS + 1; i++ ) 
    pthread_join ( thread_id [i], NULL ); 

  /*****************************************************************/
  /* GET FINAL TIMESTAMP, CALCULATE ELAPSED SEC AND USEC           */
  /*****************************************************************/
  
  gettimeofday (&last_time, ( struct timezone * ) 0 );
  if ( ( i = last_time.tv_sec - first_time.tv_sec) == 0 )
    j = last_time.tv_usec - first_time.tv_usec;
  else{
    if ( last_time.tv_usec - first_time.tv_usec < 0 ) {
      i--;
      j = 1000000 + 
	( last_time.tv_usec - first_time.tv_usec );
    } else {
      j = last_time.tv_usec - first_time.tv_usec; }
  }
  printf ( "Elapsed consumer time is %d sec and %d usec\n", i, j );

  printf ( "\n\n ALL CONSUMERS FINISHED, KILLING  PROCESS\n\n" );
  exit ( 0 );
}

void *producer ( void *arg )
{
  int i, j, k;
  unsigned short xsub [3];
  struct timeval randtime;

  gettimeofday ( &randtime, ( struct timezone * ) 0 );
  xsub [0] = ( ushort )randtime.tv_usec;
  xsub [1] = ( ushort ) ( randtime.tv_usec >> 16 );
  xsub [2] = ( ushort ) ( pthread_self );

  while( 1 ){
    j = nrand48 ( xsub ) & 3;
    pthread_mutex_lock ( &prod [j] );
    while ( shared_ring.spaces [j] == 0 ) {
      pthread_cond_wait ( &prod_cond [j], &prod [j] );
    }
    
    /*when there is room, place a donut in queue*/
    shared_ring.flavor[j][shared_ring.in_ptr[j]] = 
      shared_ring.serial[j]++;
    shared_ring.in_ptr[j] = (shared_ring.in_ptr[j] + 1) % NUMSLOTS;

    /*decrement count to account for the new donut*/
    shared_ring.spaces[j]--;

    /*unlock prod mutex*/
    pthread_mutex_unlock ( &prod [j] );

    /*get cons mutex*/
    pthread_mutex_lock( &cons [j] );

    /*increment dount count*/
    shared_ring.donuts[j]++;

    /*unlock cons mutex*/
    pthread_mutex_unlock( &cons [j] );

    /*signal cons_condx_var*/
    pthread_cond_signal( &cons_cond [j] );
  }
  return NULL;
}

void *consumer ( void *arg )
{
  int     i, j, k, m, id;
  unsigned short xsub [3];
  struct timeval randtime;
  /*containor for dount dozens and type, used in printing*/
  int donuts_cons[4][12];
  /*index keeps trank of the current slot in dounts_cons
   we should place a donut, again this is uded for printing*/
  int index[4];
  id = *( int * ) arg;
  FILE* output;
  gettimeofday ( &randtime, ( struct timezone * ) 0 );
  xsub [0] = ( ushort )randtime.tv_usec;
  xsub [1] = ( ushort ) ( randtime.tv_usec >> 16 );
  xsub [2] = ( ushort ) ( pthread_self );

  output = fopen("output.txt", "a");
  
  for( i = 0; i < 200; i++){
    /*inits/resets index and dounts_cons*/
    for( j = 0; j < 4; j++){
      index[j] = 0;
      
      for( m = 0; m < 12; m++)
	donuts_cons[j][m] = -1;
    }
    for( m = 0; m < 12; m++){
      j = nrand48( xsub ) & 3;
      
      /*get cons mutex*/
      pthread_mutex_lock(&cons[j]);
      
      while(shared_ring.donuts[j] == 0){
	pthread_cond_wait(&cons_cond[j], &cons[j]);
      }
      
      /*take donut from queue*/
      k = shared_ring.serial[j] = shared_ring.flavor[j][shared_ring.outptr[j]];
      shared_ring.outptr[j] = (shared_ring.outptr[j] + 1) % NUMSLOTS;

      /*dec donut count*/
      shared_ring.donuts[j]--;

      /*unlock cons mutex*/
      pthread_mutex_unlock(&cons[j]);
      
      /*get prod mutex*/
      pthread_mutex_lock(&prod[j]);

      /*inc space count*/
      shared_ring.spaces[j]++;

      /*unlock prod mutex*/
      pthread_mutex_unlock(&prod[j]);

      /*signal prod_condx_var*/
      pthread_cond_signal(&prod_cond[j]);

      donuts_cons[j][index[j]] = k;
      index[j]++;
    }
    fprintf(output, "Consumer thread #: %d \ttime: %d:%d:%d.%d\tdozen #: %d\n",
	    id, ((randtime.tv_sec / 360) - 2) % 24, (randtime.tv_sec / 60) % 60,
	    randtime.tv_sec % 60, randtime.tv_usec, i);
    /*Format for printing is going to be slightly different,
     found this way to be easier*/
    
    fprintf(output, "\nGlazed\n");
    /*sets j = 0 so we just deal with the "Glazed" slot*/
    j = 0;
    for(k = 0; k < 12; k++){
      /*we loop until we hit a -1, inited above to know when we are
       empty*/
      if(donuts_cons[j][k] == -1)
	break;

      fprintf(output, "\t%d", donuts_cons[j][k]);
    }
    
    fprintf(output, "\nJelly\n");
    j = 1;
    for(k = 0; k < 12; k++){
      if(donuts_cons[j][k] == -1)
        break;

      fprintf(output, "\t%d", donuts_cons[j][k]);
    }

    fprintf(output, "\nCruller\n");
    j = 2;
    for(k = 0; k < 12; k++){
      if(donuts_cons[j][k] == -1)
        break;

      fprintf(output, "\t%d", donuts_cons[j][k]);
    }
    
    fprintf(output, "\nChocolate Dip\n");
    j = 3;
    for(k = 0; k < 12; k++){
      if(donuts_cons[j][k] == -1)
        break;

      fprintf(output, "\t%d", donuts_cons[j][k]);
    }

    fprintf(output, "\n_______________________________________\n");

    /*****************************************************************/
    /* USING A MICRO-SLEEP AFTER EACH DOZEN WILL ALLOW ANOTHER       */
    /* CONSUMER TO START RUNNING, PROVIDING DESIRED RANDOM BEHVIOR   */
    /*****************************************************************/
    
    usleep(100); /* sleep 1 ms */
  }
  
  return NULL;
}

/***********************************************************/
/* PTHREAD ASYNCH SIGNAL HANDLER ROUTINE...                */
/***********************************************************/

void *sig_waiter ( void *arg )
{
  sigset_t sigterm_signal;
  int signo;

  sigemptyset ( &sigterm_signal );
  sigaddset ( &sigterm_signal, SIGTERM );
  sigaddset ( &sigterm_signal, SIGINT );

  if (sigwait ( &sigterm_signal, & signo)  != 0 ) {
    printf ( "\n  sigwait ( ) failed, exiting \n");
    exit(2);
  }
  printf ( "process going down on SIGNAL (number %d)\n\n", signo );
  exit ( 1 );
  return NULL;
}

/**********************************************************/
/* PTHREAD SYNCH SIGNAL HANDLER ROUTINE...                */
/**********************************************************/

void sig_handler ( int sig )
{
  pthread_t signaled_thread_id;
  int i, thread_index;

  signaled_thread_id = pthread_self ( );
  for ( i = 0; i < (NUMCONSUMERS + 1 ); i++) {
    if ( signaled_thread_id == thread_id [i] )  {
      thread_index = i;
      break;
    }
  }
  printf ( "\nThread %d took signal # %d, PROCESS HALT\n", 
	   thread_index, sig );
  exit ( 1 );
}
