/* 
 * Do not modify this file.
 */
#include "pa03.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINLENGTH 3
#define SETLENGTH 8
int main(int argc, char * * argv)
{
  char set[] ={'A', 'B', 'C', 'D', 
	       'E', 'F', 'G', 'H'};
  if (argc != 2) 
    {
      printf("usage: pa03 <number>\n");
      return EXIT_FAILURE;
    }
  int val = (int) strtol(argv[1], NULL, 10);;
  if ((val < MINLENGTH) || (val > SETLENGTH))
    {
      printf("usage: pa03 <number>, number must be between %d and %d\n",
	     MINLENGTH, SETLENGTH);
      return EXIT_FAILURE;
    }
  partition(val);
  subset(set, val);
  permute(set, val);
  return EXIT_SUCCESS;
}
