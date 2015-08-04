
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct free_list {
  struct free_list *next;
  struct free_list *previous;
  int block_size;
  int is_alloc;
  int reqnumb;
};

typedef struct free_list mylist;

int main(int argc, char * argv[]) {
  int freenumb = -1;
  int request, policy, flag, printflg;
  int tempbest, maxfree, largfree;
  int addr = 0;
  int x = 0;
  int y = 0;

  char f_name[9];
  char *command = NULL;

  long int givenspace; 
  long int reqsize = 0;

  mylist *head, *current, *temp;

  policy = atoi(argv[1]); /*policy requested --> first fit or best fit*/
  givenspace = atoi(argv[2]); /*total space for allocs*/
    
  FILE * frtfile = fopen("a5_data.txt", "r+"); /*opens data file*/
  FILE * alloutfile = fopen("allout.txt", "w+"); /*opens full output file*/
  FILE * outfile = fopen("output.txt", "w+"); /*opens output for just 
					       * best or first*/

  head = malloc(sizeof (mylist)); 
  current = malloc(sizeof (mylist));

  /*inits the head of the list*/
  head->next = NULL;
  head->previous = NULL;
  head->is_alloc = 0;
  head->reqnumb = freenumb;
  head->block_size = givenspace;
  /*inits current and sets our current spot to the head*/
  current = head;

  /*begin reading file*/
  while (!feof(frtfile)) {
    /*read in data line by line*/
    fscanf(frtfile, "%d%s%li \n", &request, &command, &reqsize);
    current = head;
    flag = 0;
    addr = 0;

    /*if command is an alloc*/
    if (!(strcmp((char *) &command, "alloc"))) {
      temp = malloc(sizeof (mylist)); /*holds data to pass between 
				       * free_list bodies*/
      /*temp is set up to be the current request*/
      temp->block_size = reqsize; /*inits temp list*/
      temp->is_alloc = 1;
      temp->reqnumb = request;
      printflg = 1; /*intis printing flag*/
      current = head; /*sets current position as head*/

      /*first fit*/
      if (policy == 1) {
	do {
	  /*checks to see is the current is alloced and has enough room*/
	  if ((current->is_alloc == 0) && (current->block_size >= reqsize)) {
	    /*if current is not head*/
	    if (current->previous != NULL) {
	      temp->previous = current->previous;
	      current->previous->next = temp;
	      current->previous = temp;
	      current->block_size = current->block_size - reqsize;
	      temp->next = current;
	      flag = 1;
	      printflg = 0;
	      /*if current is head*/
	    } else if (current->previous == NULL) {
	      temp->previous = NULL;
	      temp->next = current;
	      current->previous = temp;
	      current->block_size = current->block_size - reqsize;
	      head = temp;
	      flag = 1;
	      printflg = 0;
	    }
	    /*if there is not enough room for alloc*/
	  } else {
	    addr = addr + current->block_size;
	    current = current->next;
	  }
	  /*loop ends when current becomes NULL or when flag = 0*/
	} while ((current != NULL) && (flag == 0));
	/*this will trigger when there is no room for the current
	  current request, prints the req number and size of the request*/
	if (printflg == 1) {
	  x++;
	  fprintf(outfile, "%d) Req#: %d Size: %d\n", x, request, reqsize);
	}
      } /*end of first fit*/

      /*best fit*/
      if (policy == 2) {
	tempbest = givenspace + 1;
                
	/*traverse the list to find the closest fit for the request*/
	do {
	  if ((current->is_alloc == 0) && (current->block_size >= reqsize)) {
	    if (current->block_size == reqsize) {
	      tempbest = current->block_size;
	      break;
	    }
	    if (current->block_size < tempbest) {
	      tempbest = current->block_size;
	    }
	  }
	  current = current->next;
	} while (current != NULL);
	current = head;
	/*same idea as first fit except we check against the block size 
	  we found*/
	do {
	  if (current->block_size == tempbest) {
	    if (current->previous != NULL) {
	      temp->previous = current->previous;
	      current->previous->next = temp;
	      current->previous = temp;
	      current->block_size = current->block_size - reqsize;
	      temp->next = current;
	      flag = 1;
	      printflg = 0;
	    } else if (current->previous == NULL) {
	      temp->previous = NULL;
	      temp->next = current;
	      current->previous = temp;
	      current->block_size = current->block_size - reqsize;
	      head = temp;
	      flag = 1;
	      printflg = 0;
	    }
	  } else {
	    addr = addr + current->block_size;
	    current = current->next;
	  }
	} while ((current != NULL) && (flag == 0));

	if (printflg == 1) {
	  y++;
	  fprintf(outfile, "%d)Req#: %d Size: %d\n", y, request, reqsize);
	}
      } /*end of best fit*/
    } /*end if alloc*/

    /*if command is a free*/
    if (!(strcmp((char *) &command, "free"))) {
      addr = -1;
      flag = 0;
      current = head;
      freenumb--;

      do {
	/*moves through to find what we want to free
	  the case of a free our "reqsize" is the reqnumb
	  of what we want to free*/
	if ((current->reqnumb) == ((int) reqsize)) {
	  current->is_alloc = 0;
	  current->reqnumb = freenumb;
	  flag = 1;
	} else {
	  current = current->next;
	}
      } while ((current != NULL) && (flag == 0));
      current = head;
      flag = 0;

      do {
	/*move through finding which one we set is_alloc to 0*/
	if (current->is_alloc == 0) {
	  /*if current is not head*/
	  if (current->previous != NULL) {
	    if (current->next != NULL) {
	      if (current->next->is_alloc == 0) {
		current->next->previous = current->previous;
		current->previous->next = current->next;
		current->next->block_size = current->next->block_size + current->block_size;
		current = current->next;
	      } else {
		current = current->next;
	      }
	    }
	    /*if current is head*/
	  } else if (current->previous == NULL) {
	    if (current->next != NULL) {
	      if (current->next->is_alloc == 0) {
		current->next->block_size = current->next->block_size + current->block_size;
		head = current->next;
		current->next->previous = NULL;
	      } else {
		current = current->next;
	      }
	    }
	  }
	}
	current = current->next;
      } while (current != NULL);
    }
    current = head;
    maxfree = 0;
    largfree = 0;
    /*next couple of things print data as we move through
      the file printing the request number, the command, the 
      size of the request or reqnumb of the free, the current 
      amount of total free space, the largest free space and
      the address of any alloc made*/
    do {
      if (current->is_alloc == 0) {
	maxfree = maxfree + current->block_size;
	if (current->block_size > largfree) {
	  largfree = current->block_size;
	}
      }
      current = current->next;
    } while (current != NULL);

    current = head;
    if (printflg == 1) {
      addr = -1;
    }
    fprintf(alloutfile, "%d\t%s\t%d\t%d\t\t%li\t\t%d\n", request, &command,
	    reqsize, maxfree, largfree, addr);
  }/*end of file read*/
  return 0;
}
