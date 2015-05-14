/*included libs*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <sys/resource.h>
#include <wait.h>
#include <stdlib.h>

int counter = 0, counter_2G = 0;

/*union for the exit statuses of the child*/
typedef union{
  int exit_status;
  struct{
    unsigned sig_num:7;
    unsigned core_dmp:1;
    unsigned exit_num:8;
  }parts;
}LE_Wait_Status;

/*function called by the child process when kill with the SIGTERM signal 
  is called  by the parent; used excel to run the Prof. prog*/
void sigfunc(int signum){
  printf("\nCHILD PROG: Signal number %d called after %d loops.  Will now execl prof program.\n", signum, counter);
  fflush(stdout);
  execl("./Assign1", "Assign1", NULL);
  perror("excel call failed: ");
  exit(1);
}

int main(void){

  pid_t pid, ppid;
  int ruid, rgid, euid, egid;
  int priority;
  char msg_buf[10];
  int msg_pipe[2];

  sigset_t mask, proc_mask;
  struct sigaction new;

  LE_Wait_Status exit_wait;

  /*creates a pipe prog exits if pipe fails to create */
  if(pipe(msg_pipe) == -1){
    perror("Failed in parent pipe creation: ");
    exit(7);
  }

  /*parent prints its info*/
  printf("\nThis is the Parent process report:\n");
  pid  = getpid();
  ppid = getppid();
  ruid = getuid();
  euid = geteuid();
  rgid = getgid();
  egid = getegid();
  priority = getpriority(PRIO_PROCESS, 0);

  printf("\nPARENT PROG: Process ID is:\t\t%d\n", pid);
  printf("PARENT PROG: Process parent ID is:\t%d\n", ppid);
  printf("PARENT PROG: Real UID is:\t\t%d\n", ruid);
  printf("PARENT PROG: Real GID is:\t\t%d\n", rgid);
  printf("PARENT PROG: Effective UID is:\t\t%d\n", euid);
  printf("PARENT PROG: Effective GID is:\t\t%d\n", egid);
  printf("PARENT PROG: Process priority is:\t%d\n", priority);

  printf("\nThe parent will now create the child process, read from pipe, send kill command, and wait for obiturary.\n");
  fflush(stdout);

  /*switch calles a fork to create a child process*/
  switch(pid = fork() ){
  case -1:
    perror("Fork call failed\n");
    exit(4);
    /*the "parent process section" unused here parent's actions are below*/
  default:
    break;
    /*child process section*/
  case 0:
    /*Lines 63-76 barrowed from Prof. program*/
    sigemptyset(&proc_mask);/** clear signal mask **/
    sigprocmask(SIG_SETMASK, &proc_mask, NULL);

    sigemptyset(&mask);
    new.sa_mask = mask;
    new.sa_handler = sigfunc;
    new.sa_flags = 0;

    /*waits for a SIGTERM signal fomr the parent, calls sigfunc when it 
      arrives*/
    if(sigaction(SIGTERM, &new, NULL) == -1){
      perror("failed in sigaction:");
      exit(2);
    }

    /*child prints its info*/
    printf("\nThis is the Child process report:\n");
    pid  = getpid();
    ppid = getppid();
    ruid = getuid();
    euid = geteuid();
    rgid = getgid();
    egid = getegid();
    priority = getpriority(PRIO_PROCESS, 0);

    printf("\nCHILD PROG: Process ID is:\t\t%d\n", pid);
    printf("CHILD PROG: Process parent ID is:\t%d\n", ppid);
    printf("CHILD PROG: Real UID is:\t\t%d\n", ruid);
    printf("CHILD PROG: Real GID is:\t\t%d\n", rgid);
    printf("CHILD PROG: Effective UID is:\t\t%d\n", euid);
    printf("CHILD PROG: Effective GID is:\t\t%d\n", egid);
    printf("CHILD PROG: Process priority is:\t%d\n", priority);

    printf("\nChild will now write to pipe and go into an infinite loop.\n");
    fflush(stdout);

    /*child writes to pipe to wake parent from read block*/
    write(msg_pipe[1], "z", 1);

    /*child infinite loop counts how many loops it makes until kill is called*/
    while(counter_2G < 10){
      counter++;
    }
  }
  /*parent reads on empty pipe, blocks and waits for child to write*/
  if(read(msg_pipe[0], msg_buf, 1) == -1){
    perror("Read failed");
    exit(7);
  }
  /*after it wakes called kill with SIGTERM, the signal the chile is waiting 
    for*/
  if(kill(pid, SIGTERM) == -1){
    perror("Kill failed");
    exit(8);
  }
  /*parent waits for child to die*/
  if((pid = wait(&exit_wait.exit_status)) == -1){
    perror("Wait call failed: ");
    exit(6);
  }

  /*parent then prints out info about child's death with signal number, whether
    it was a signal call or an exit, the exit of signal number, and whethe 
    there was a core dump or not*/
  printf("PARENT PROG: Child exited with: %s%d %s\n", (exit_wait.parts.sig_num == 0)? "exit " : "signal ", (exit_wait.parts.sig_num == 0)? exit_wait.parts.exit_num : exit_wait.parts.sig_num, (exit_wait.parts.core_dmp == 1)? "and a core dump\n" : "\0");

  exit(0);

}
