/* do not modify the following */
#include <stdio.h>
#include <stdlib.h>
#define BRICK 0
#define SPACE 1
#define EXIT  2
#define START 3
#define OUTSIDE 4
/* until here */

/* You need to modify the following function */
int checkLocation(int row, int col /* add the needed rguments*/)
{
  /* This function returns one of the following options */
  /* BRICK, SPACE, EXIT, START, OUTSIDE */

  /* As an example: */
  return BRICK;
}

/* do not modify the following */
void printLocation(int loc)
{
  switch (loc)
    {
    case BRICK:
      printf("It is brick.\n");
      break;
    case SPACE:
      printf("It is space.\n");
      break;
    case EXIT:
      printf("It is exit.\n");
      break;
    case START:
      printf("It is start.\n");
      break;
    case OUTSIDE:
      printf("It is outside.\n");
      break;
    }
}
/* until here */

int main(int argc, char * argv[])
{
  /* do not modify the following */
  int exitRow, exitCol;
  int startRow, startCol;
  int numRow, numCol;
  int loc1, loc2;
  /* until here */
  
  /* check whether there is an argument for the file */
  if (argc) /* need to modify this line */
    {
      /* do not modify the following */
      printf("need a file name\n"); 
      return EXIT_FAILURE;
      /* until here */
    }

  /* check whether opening the file is successful */
  if (1) /* need to modify this line */
    {
      /* do not modify the following */
      printf("open file fail\n"); 
      return EXIT_FAILURE;
      /* until here */      
    }


  /* read the file and update the variables */

  /* close the file */
  
  /* do not modify the following */
  printf("The maze has %d rows.\n", numRow);
  printf("The maze has %d columns.\n", numCol);
  printf("The exit is at %d %d.\n", exitRow, exitCol);
  printf("The starting point is at %d %d.\n", startRow, startCol);
  loc1 = checkLocation(6, 6);
  printLocation(loc1);
  loc2 = checkLocation(17, 13);
  printLocation(loc2);
  return EXIT_SUCCESS;
}
