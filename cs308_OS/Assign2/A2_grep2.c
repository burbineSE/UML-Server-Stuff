/*included libs*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <sys/resource.h>
#include <wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

void sigfunc(int signum){
  char buf[512];
  sprintf(buf, "\nThat goes around comes around\n");
  write(1, buf, strlen(buf)+1);
  exit(1);
}

int main(void){
  FILE *par_infile;
  int pfdout[2], pfdin[2], fd, nread, fst_num, sec_num, thd_num;
  int count = 0;
  int total_count = 0;
  char buf[512];

  sigset_t mask, proc_mask;
  struct sigaction new;

  sigemptyset(&proc_mask);
  sigprocmask(SIG_SETMASK, &proc_mask, NULL);

  sigemptyset(&mask);
  new.sa_mask = mask;
  new.sa_handler = sigfunc;
  new.sa_flags = 0;

  if(sigaction(SIGPIPE, &new, NULL) == -1){
    perror("failed in sigaction");
    exit(2);
  }

  if(pipe(pfdout) == -1 || pipe(pfdin) == -1){
    perror("pipe");
    exit(1);
  }
  switch(fork()){
  case -1:
    perror("fork");
    exit(2);
  case 0:
    if(close(0) == -1){
      perror("pipe");
      exit(1);
    }
    if(dup(pfdout[0]) != 0){
      perror("dup");
      exit(1);
    }
    if(close(1) == -1){
      perror("pipe");
      exit(1);
    }
    if(dup(pfdin[1]) != 1){
      perror("dup");
      exit(1);
    }
    if(close(pfdout[0]) == -1 ||
       close(pfdout[1]) == -1 ||
       close(pfdin[0]) == -1 ||
       close(pfdin[1]) == -1){
      perror("close");
      exit(1);
    }
    execlp("grep", "grep", "123", NULL);
    perror("execlp");
    exit(1);
  }
  if(close(pfdout[0]) == -1 || close(pfdin[1]) == -1){
    perror("close");
    exit(1);
  }

  if((fd = open("cs308a2_grep_data_2", O_RDONLY, 0)) == -1){
    perror("cannot open");
    exit(1);
  }
  printf("\n");
  fflush(stdout);
  while((nread = read(fd, buf, 80)) != 0){
    if(nread == -1){
      perror("read");
      exit(1);
    }
    if(write(pfdout[1], buf, nread) == -1){
      perror("write");
      exit(1);
    }
    if((count += nread) < 4096){
      write(1, "*" , 1);
    } else {
      total_count += count;
      count = 0;
      sprintf(buf, " %d bytes\n", total_count);
      write(1, buf, strlen(buf)+1);
    }
  }
  if(close(fd) == -1 || close(pfdout[1]) == -1){
    perror("close");
    exit(1);
  }
  write(1, "\nThrough All Data\n", 18);
  par_infile = fdopen(pfdin[0], "r");
  sprintf(buf, "\nThe following lines had the number 123 somewhere in them: \n\n\
");
  write(1, buf, strlen(buf)+1);
  count = 0;
  while(fscanf(par_infile, "%d %d %d", &fst_num, &sec_num, &thd_num) != EOF){
    sprintf(buf, "%d %d %d\n", fst_num, sec_num, thd_num);
    write(1, buf, strlen(buf)+1);
    ++count;
  }
  printf("\nA total of %d lines had the number 123 in them.\n\n", count);
  fflush(stdout);
  return(0);
}
