#include "donuts.h"
int shmid, semid[3];
void sig_handler (int); 

void sig_handler(int sig)
{
  int i,j,k;

  printf("In signal handler with signal # %d\n",sig);

  if(shmctl(shmid, IPC_RMID, 0) == -1){
    perror("handler failed shm RMID: ");
  }
  for(i = 0; i < NUMSEMIDS; i++){
    if(semctl (semid[i], 0, 
	       IPC_RMID, (union semun)0) == -1){
      perror("handler failed sem RMID: ");
    }
  }
  exit(5);
}
int main(int argc, char *argv[])
{
  int in_ptr [NUMFLAVORS];
  int serial [NUMFLAVORS];
  int i, j, k, l, nsigs;
  struct donut_ring *shared_ring;
  struct timeval randtime;
  struct sigaction new;

  void sig_handler(int);  /* declare signal handler function */
  sigset_t mask_sigs;

  /* producer initializes serial counters and in-pointers  */
  for(i = 0; i < NUMFLAVORS; i++){
    in_ptr [i] = 0;
    serial [i]  = 0;
  }

  int sigs [] = {SIGHUP, SIGINT, SIGQUIT, SIGBUS, 
		 SIGTERM, SIGSEGV, SIGFPE};

  nsigs = sizeof (sigs) / sizeof (int);
    sigemptyset (&mask_sigs);
  for(i=0; i< nsigs; i++)
    sigaddset (&mask_sigs, sigs [i]);       
  for(i = 0; i <  nsigs; i++){
    new.sa_handler = sig_handler;
    new.sa_mask = mask_sigs;
    new.sa_flags = 0;
    if(sigaction (sigs [i], &new, NULL) == -1){
      perror("can't set signals: ");
      exit(1);
    }
  }

    if((shmid = shmget (MEMKEY, sizeof(struct donut_ring),
			IPC_CREAT | 0600)) == -1){
      perror("PROD: shared get failed: ");
      exit(1);
    }

    if((shared_ring = (struct donut_ring *) 
	shmat (shmid, NULL, 0)) == -1){
      perror("shared attach failed: ");
      sig_handler(-1);
    }

    for(i=0; i<NUMSEMIDS; i++)
      if ((semid[i] = semget (SEMKEY+i, NUMFLAVORS, 
			      IPC_CREAT | 0600)) == -1){
	perror("semaphore allocation failed: ");
	sig_handler(-1);
      }

    gettimeofday (&randtime, (struct timezone *)0);
    
    /* use microsecond component for uniqueness */
    unsigned short xsub1[3];
    xsub1[0] = (ushort) randtime.tv_usec;
    xsub1[1] = (ushort)(randtime.tv_usec >> 16);
    xsub1[2] = (ushort)(getpid());

    /* use nrand48 with xsub1 to get 32 bit random number */
    j=nrand48(xsub1) & 3;

    /* use the semsetall utility to set initial semaphore values */
    if(semsetall (semid [PROD], 
		  NUMFLAVORS, NUMSLOTS) == -1){
      perror("semsetsall failed: ");
      sig_handler(-1);
    }
    if(semsetall (semid [CONSUMER], 
		  NUMFLAVORS, 0) == -1){
      perror("semsetsall failed: ");
      sig_handler(-1);
    }
    if(semsetall (semid [OUTPTR], 
		  NUMFLAVORS, 1) == -1){
      perror("semsetsall failed: ");
	sig_handler(-1);
    }
    while(1){
       
      j = nrand48(xsub1) & 3;
      l = serial[j]++;
      if(p(semid[PROD], j) == -1){
	perror("p operation failed:");
	sig_handler(-1);
      }
      shared_ring->flavor[j][in_ptr[j]]=l;
      in_ptr[j] = (in_ptr[j]+1) % NUMSLOTS;
      printf("A donut of type %d number %d produced in slot %d.\n", 
	     j, l, in_ptr[j]-1);
      if(v(semid[CONSUMER], j) == -1){
	perror("v operation failed: ");
	sig_handler(-1);
      }
    }
    return(0);
}
