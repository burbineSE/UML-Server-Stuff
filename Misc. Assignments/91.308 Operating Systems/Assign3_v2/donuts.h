#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/signal.h>

#define SEMKEY       (key_t)78462644
#define MEMKEY       (key_t)78462644
#define NUMFLAVORS   4
#define NUMSLOTS     50
#define NUMSEMIDS    3
#define PROD         0
#define CONSUMER     1
#define OUTPTR       2

struct donut_ring{
  int flavor  [NUMFLAVORS] [NUMSLOTS];
  int outptr  [NUMFLAVORS];
};

extern int p         (int, int);
extern int v         (int, int);
extern int semsetall (int, int, int);

union semun{
  int val;
  struct semid_ds *buf;
  unsigned short int *array;
};

