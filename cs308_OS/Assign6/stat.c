#include <dirent.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char* argv[]){
  char*          dirc = ".";
  DIR*           dir;
  struct stat    ent;
  struct dirent *dir_ent;

  dir = opendir(dirc);

  while(dir_ent = readdir(dir)){
    if(lstat(dir_ent->d_name, &ent) == -1){
      perror("lstat");
      exit(EXIT_FAILURE);
    }
    
    //if(!strcmp(dir_ent->d_name, argv[1])) printf("!!!HIT!!!\n");
    if(argc == 1) {
      printf("FILENAME:\t\t\t%s\n", dir_ent->d_name);
      
      printf("FILE_TYPE:\t\t\t");
      switch(ent.st_mode & S_IFMT){
      case S_IFBLK: printf("block device\n");     break;
      case S_IFCHR: printf("character device\n"); break;
      case S_IFDIR: printf("directory\n");        break;
      case S_IFLNK: printf("symbolic link\n");    break;
      case S_IFREG: printf("ordinary\n");         break;
      default:      printf("unknown?\n");         break;
      }
      
      printf("PERMISSIONS:\t\t\t");
      printf( (S_ISDIR(ent.st_mode)) ? "d" : "-");
      printf( (ent.st_mode & S_IRUSR) ? "r" : "-");
      printf( (ent.st_mode & S_IWUSR) ? "w" : "-");
      printf( (ent.st_mode & S_IXUSR) ? "x" : "-");
      printf( (ent.st_mode & S_IRGRP) ? "r" : "-");
      printf( (ent.st_mode & S_IWGRP) ? "w" : "-");
      printf( (ent.st_mode & S_IXGRP) ? "x" : "-");
      printf( (ent.st_mode & S_IROTH) ? "r" : "-");
      printf( (ent.st_mode & S_IWOTH) ? "w" : "-");
      printf( (ent.st_mode & S_IXOTH) ? "x" : "-");
      printf("\n");
    
      struct passwd *pw = getpwuid(ent.st_uid);
      printf("OWNER_NAME:\t\t\t%s\n", pw->pw_name);
    
      struct group  *gr = getgrgid(ent.st_gid);
      printf("GROUP_NAME:\t\t\t%s\n", gr->gr_name);
      
      printf("DATE_OF_LAST_MODIFICATION:\t%s",ctime(&ent.st_mtime));
      
      printf("LINK_COUNT:\t\t\t%ld\n", (long) ent.st_nlink);
    
      printf("SIZE_IN_BYTES:\t\t\t%lld bytes\n", (long long) ent.st_blksize);

      printf("INODE_NUMBER:\t\t\t%ld\n", (long)ent.st_ino);
      
      printf("\n");
    } else {
      int i;
      for(i = 0; i < argc; i++){
	if(!strcmp(dir_ent->d_name, argv[i])) {

	  printf("FILENAME:\t\t\t%s\n", dir_ent->d_name);

	  printf("FILE_TYPE:\t\t\t");
	  switch(ent.st_mode & S_IFMT){
	  case S_IFBLK: printf("block device\n");     break;
	  case S_IFCHR: printf("character device\n"); break;
	  case S_IFDIR: printf("directory\n");        break;
	  case S_IFLNK: printf("symbolic link\n");    break;
	  case S_IFREG: printf("ordinary\n");         break;
	  default:      printf("unknown?\n");         break;
	  }

	  printf("PERMISSIONS:\t\t\t");
	  printf( (S_ISDIR(ent.st_mode)) ? "d" : "-");
	  printf( (ent.st_mode & S_IRUSR) ? "r" : "-");
	  printf( (ent.st_mode & S_IWUSR) ? "w" : "-");
	  printf( (ent.st_mode & S_IXUSR) ? "x" : "-");
	  printf( (ent.st_mode & S_IRGRP) ? "r" : "-");
	  printf( (ent.st_mode & S_IWGRP) ? "w" : "-");
	  printf( (ent.st_mode & S_IXGRP) ? "x" : "-");
	  printf( (ent.st_mode & S_IROTH) ? "r" : "-");
	  printf( (ent.st_mode & S_IWOTH) ? "w" : "-");
	  printf( (ent.st_mode & S_IXOTH) ? "x" : "-");
	  printf("\n");

	  struct passwd *pw = getpwuid(ent.st_uid);
	  printf("OWNER_NAME:\t\t\t%s\n", pw->pw_name);

	  struct group  *gr = getgrgid(ent.st_gid);
	  printf("GROUP_NAME:\t\t\t%s\n", gr->gr_name);

	  printf("DATE_OF_LAST_MODIFICATION:\t%s",ctime(&ent.st_mtime));

	  printf("LINK_COUNT:\t\t\t%ld\n", (long) ent.st_nlink);

	  printf("SIZE_IN_BYTES:\t\t\t%lld bytes\n", (long long) ent.st_blksize);

	  printf("INODE_NUMBER:\t\t\t%ld\n", (long)ent.st_ino);

	  printf("\n");

	}	
      }
    }
  }
  exit(EXIT_SUCCESS);
}
