
/* need these include files */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <string.h>

/* need just a main function, no args */

int main(void)
{

  /* some local variables  */

  pid_t   pid, ppid;
  int     ruid, rgid, euid, egid;
  int     priority;
  char    msg_buf[100];
  char    msg_buf2[100];
  int     msg_pipe[2];

  /* use the pipe() system call to create the pipe*/

  if(pipe(msg_pipe) == -1){
    perror("failed in Parent pipe creation:");
    exit(7);
  }

  /*use various system calls to collect and print process details*/

  printf("\nThis is the Parent process report:\n");
  pid  = getpid();
  ppid = getppid();
  ruid = getuid();
  euid = geteuid();
  rgid = getgid();
  egid = getegid();
  priority = getpriority(PRIO_PROCESS, 0);

  printf("\nPARENT PROC: Process ID is:\t\t%d\n", pid);
  printf("PARENT PROC: Process parent ID is:\t%d\n", ppid);
  printf("PARENT PROC: Real UID is:\t\t%d\n", ruid);
  printf("PARENT PROC: Real GID is:\t\t%d\n", rgid);
  printf("PARENT PROC: Effective UID is:\t\t%d\n", euid);
  printf("PARENT PROC: Effective GID is:\t\t%d\n", egid);
  printf("PARENT PROC: Process priority is:\t%d\n", priority);

  printf("\nPARENT PROC: will now create child, write to pipe,\n and do a normal termination.\n");

  sprintf(msg_buf, "This is a pipe message from the parent with PID %d", pid);

  switch(pid = fork() ){
  case -1: 
    perror("Fork call failed\n");
    exit(4);
  default:
    printf("\nPARENT PROC: created Child with %d PID\n", pid);
    /*write(msg_pipe[1], msg_buf, strlen(msg_buf));*/
    /*printf("\n\n!!!!!!!\n\n");*/
    break;
  case 0:
    printf("\nThis is the Child process report:\n");
    pid  = getpid();
    ppid = getppid();
    ruid = getuid();
    euid = geteuid();
    rgid = getgid();
    egid = getegid();
    priority = getpriority(PRIO_PROCESS, 0);

    printf("\nCHILD PROC: Process ID is:\t\t%d\n", pid);
    printf("CHILD PROC: Process parent ID is:\t%d\n", ppid);
    printf("CHILD PROC: Real UID is:\t\t%d\n", ruid);
    printf("CHILD PROC: Real GID is:\t\t%d\n", rgid);
    printf("CHILD PROC: Effective UID is:\t\t%d\n", euid);
    printf("CHILD PROC: Effective GID is:\t\t%d\n", egid);
    printf("CHILD PROC: Process priority is:\t%d\n", priority);

    printf("\nCHILD PROC: about to read pipe and report message from parent:\n\n");

    read(msg_pipe[0], msg_buf2, 100);
    printf("CHILD PROC: parent's message is \n\t%s\n", msg_buf2);
    usleep(100);
    printf("\nCHILD PROC: new parent has PID %d\n", getppid());
    printf("CHILD PROC: ### Goodbye ###\n");
    exit(0);
  }
  write( msg_pipe[1], msg_buf, strlen(msg_buf));
  
  exit(0);
}
