#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
/* 
   arguments:
   number_of_rectangle (must be a power of 2) output_file_name

   example:
   ./generate 256 output1

   This program does not always succeed. The program ensures that
   every rectangle has with and height at least one.  If this cannot
   be achived, the program will not terminate.  This occurs when the
   widht (or height) is too small.

   If the program does not terminate, just stop it (CTRL-C) and 
   run it again.  We won't be that unlucky, right?
 */

int isPower2(int num)
{
  /* if num is 2 power n, return log2.
     otherwise, return -1 */
  if (num <= 0) { return -1; }
  int lg = (int) log2(num);
  int n = 1;
  n <<= lg;
  if (n == num)
    {
      return lg;
    }
  return -1;
}

/*
  lower left (ll) corner and upper right (ur) corner 
*/

void divide(int xll, int yll, int xur, int yur, int num, FILE * fhd)
{
  if (num == 1)
    {
      int width = xur - xll;
      int height = yur - yll;
      if (rand() % 2) 
	{ 
	  /* do not rotate */
	  /* printf("%d %d\n", width, height);  */
	  fwrite(& width, sizeof(int), 1, fhd);
	  fwrite(& height, sizeof(int), 1, fhd);
	}
      else 
	{
	  /* rotate */
	  /* printf("rotate\n"); */
	  /* printf("%d %d\n", height, width); */
	  fwrite(& height, sizeof(int), 1, fhd);
	  fwrite(& width, sizeof(int), 1, fhd);
	}
      return;
    }
  if (num == 0)
    {
      fprintf(stderr, "num == 0 should not happen\n");
      return;
    }
  /* printf("divide(%d, %d, %d)\n", xur - xll, yur - yll, num); */
  int horizontal = rand() % 2; /* divide vertically or horizonally */
  if (horizontal == 0)
    {
      /* printf("divide vertically\n"); */
      int newx;
      do
	{
	  newx = rand() % (xur - xll) + xll;
	} while (newx == xll);
      divide(xll, yll, newx, yur, num / 2, fhd);
      divide(newx, yll, xur, yur, num / 2, fhd);
    }
  else
    {
      /* printf("divide horizontally\n"); */
      int newy;
      do
	{
	  newy = rand() % (yur - yll) + yll;
	} while (newy == yll);
      divide(xll, yll, xur, newy, num / 2, fhd);
      divide(xll, newy, xur, yur, num / 2, fhd);
    }
}
int main(int argc, char * argv[])
{
  if (argc < 3)
    {
      fprintf(stderr, "need 2 arguments: number file\n");
      return -1;
    }
  int number = (int)strtol(argv[1], (char **)NULL, 10);
  FILE * fhd = fopen(argv[2], "wb");
  int pw = isPower2(number);
  if ((number <= 0) || (pw <= 0))
    {
      fprintf(stderr, "number must be power of 2\n");
      return -1;      
    }
  if (fhd == 0)
    {
      fprintf(stderr, "fopen fail\n");
      return -1;
    }
  srand(time(0)); /* initialize random number seed */
  int minSide = number * 16;
  int width = minSide  + (rand() % ((rand() % 10000) + 1));  
  int height = minSide + (rand() % ((rand() % 10000) + 1));  
  /* printf("num = %d, width = %d, height = %d\n", number, width, height); */
  divide(0, 0, width, height, number, fhd); 
  fclose (fhd);
  return 0;
}
