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

int main(void){

  FILE *par_infile;
  int pfdout[2], pfdin[2], fd, nread,  area_code, mid_code, last_code;
  int previ_code = 0;
  int cd_count = 0;
  int total_count = 0;
  int count = 0;
  char buf[512], firstname[25], lastname[25];

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
    execlp("sort", "sort", "-k 3.3n", "-k 1.1", "-k 2.2", NULL);
    perror("execlp");
    exit(1);
  }
  
  if(close(pfdout[0]) == -1 || close(pfdin[1]) == -1){
    perror("close");
    exit(1);
  }

  if((fd = open("cs308a2_sort_data", O_RDONLY, 0)) == -1){
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
      /*printf(" ");
	fflush(stdout);*/
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

  fscanf(par_infile, "%s %s %d %d %d", lastname, firstname,
	 &area_code, &mid_code, &last_code);

  sprintf(buf, "\nFirst entry: %s %s %d %d %d\n\n", lastname, firstname,
	  area_code, mid_code, last_code);
  write(1, buf, strlen(buf)+1);

  ++cd_count;
  previ_code = area_code;
  /* printf("\n%d %d\n", area_code, cd_count);
  fflush(stdout);*/

  while(fscanf(par_infile, "%s %s %d %d %d", lastname, firstname, 
	       &area_code, &mid_code, &last_code) != EOF ){
    if(area_code != previ_code){
      sprintf(buf, "Area code %d appeared %d times.\n", previ_code, cd_count);
      write(1, buf, strlen(buf)+1);
      previ_code = area_code;
      cd_count = 0;
    } else {
      /*if(area_code == 103){
	printf("here\n");
	fflush(stdout);
	}*/
      ++cd_count;
    }
  }
  printf("Area code %d appeared %d times.\n\n", area_code, cd_count);
  fflush(stdout);
  fclose(par_infile);
  return(0);
}
