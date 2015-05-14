#include "donuts.h"
int shmid, semid[3];
void sig_handler (int);

void sig_handler (int sig){
  exit(5);
}

/*struct for donuts taken by consumers*/
typedef struct cons_donuts{
  int total_flv;                                  
  int place[12];                                   
}cons_donuts;

cons_donuts d_nut[4];

int main(int argc, char *argv[]){

  int out_ptr[NUMFLAVORS];
  int serial[NUMFLAVORS];
  int i, j, k, l;
  int num_dozens = 10;
  int most_flv;
  struct sigaction new;
  struct donut_ring *shared_ring;
  struct timeval randtime;
  FILE *out_file;
  time_t out_time;

  /* producer initializes serial counters and in-pointers  */
  for(i=0; i < NUMFLAVORS; i++){
    out_ptr[i] = 0;
    serial[i] = 0;
  }

  void sighandler(int);
  sigset_t mask_sigs;
  int nsigs;
  int sigs[] = {SIGHUP, SIGINT, SIGQUIT, SIGBUS, SIGTERM, SIGSEGV, SIGFPE};

  nsigs = sizeof(sigs)/sizeof(int);
  sigemptyset(&mask_sigs);
  for(i=0; i < nsigs; i++)
    sigaddset(&mask_sigs, sigs[i]);
  for(i = 0; i < nsigs; i++){
    new.sa_handler = sig_handler;
    new.sa_mask = mask_sigs;
    new.sa_flags = 0;
    if(sigaction(sigs[i], &new, NULL) == -1){
      perror("can't set signals: ");
      exit(1);
    }
  }
  if((shmid = shmget (MEMKEY, sizeof(struct donut_ring), 
		      IPC_CREAT | 0600)) == -1){
    perror("CONS: shared get failed: ");
    exit(1);
  }

  if((shared_ring = (struct donut_ring *) 
      shmat(shmid, NULL, 0)) == -1){
    perror("shared attach failed: ");
    sig_handler(-1);
  }

  for(i = 0; i < NUMSEMIDS; i++)
    if((semid[i] = semget(SEMKEY + i, NUMFLAVORS, 
			  IPC_CREAT | 0600)) == -1){
      perror("semaphore attachment failed: ");
      sig_handler(-1);
    }

  gettimeofday(&randtime, (struct timezone *)0);

  /* use microsecond component for uniqueness */

  unsigned short xsub1[3];
  xsub1[0] = (ushort) randtime.tv_usec;
  xsub1[1] = (ushort) (randtime.tv_usec>>16);
  xsub1[2] = (ushort)(getpid());

  k = 1;
  while(k <= num_dozens){
    for (i = 0; i < 4; i++){
      d_nut[i].total_flv = 0;
    }
    i = 0;

    while(i < 12){
      i++;
      j = nrand48(xsub1) & 3; 

      if(p(semid[CONSUMER], j) == -1){
          sig_handler(sigs[2]);
      }

      if(p(semid[OUTPTR], j) == -1){
        sig_handler(sigs[2]);
      }
      /*if(p(semid[CONSUMER], j) == -1){
        sig_handler(sigs[2]);
	}*/
      l = shared_ring->flavor[j][shared_ring->outptr[j]];
      shared_ring->outptr[j] = (shared_ring->outptr[j] + 1) % NUMSLOTS;

      /*if(v(semid[PROD], j) == -1){
        sig_handler(sigs[2]);
	}*/
      if(v(semid[OUTPTR], j) == -1){
        sig_handler(sigs[2]);
      }
      if(v(semid[PROD], j) == -1){
          sig_handler(sigs[2]);
      }
                                   
      d_nut[j].place[d_nut[j].total_flv] = l;
      d_nut[j].total_flv++;
    }

    out_file = fopen("output.txt", "a");
    out_time = time(NULL);

    fprintf(out_file, "process PID: %d\tdozen#: %d\tTime: %s", getpid() 
	    , k, asctime(localtime(&out_time)));
    fprintf(out_file, "\n");
    fprintf(out_file, "Glazed\tJelly\tCuller\tChocolate Dip\n");

    /*get the flavor with the most to cover all donuts*/
    most_flv = d_nut[0].total_flv;
    if (most_flv < d_nut[1].total_flv)
      most_flv = d_nut[1].total_flv;
    else if(most_flv < d_nut[2].total_flv)
      most_flv = d_nut[2].total_flv;
    else if(most_flv < d_nut[3].total_flv)
      most_flv = d_nut[3].total_flv;

    for(i = 0; i < most_flv; i++){
      for(j = 0; j < 4; j++){
	/*if theres is an entry at this "level"*/
	if(d_nut[j].total_flv > i)
          fprintf(out_file, "%d\t", d_nut[j].place[i]);
	/*if there is no entry at this "level"*/
        else
          fprintf(out_file, " \t");
      }
      fprintf(out_file, "\n");
    }
    fprintf(out_file, "\n");
    fclose(out_file);
    k++;
  }
  printf("Consumer %s has finished.\n", argv[1]);
  return 0;
}
