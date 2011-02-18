/* 
   read rectangles
 */
#include <stdio.h>
int main(int argc, char * argv[])
{
  FILE * fhd;
  int numRect = 0;
  if (argc < 2)
    {
      fprintf(stderr, "need a file name\n");
      return -1;
    }
  fhd = fopen(argv[1], "rb");
  if (fhd == 0)
    {
      fprintf(stderr, "fopen fail\n");
      return -1;
    }
  while (! feof(fhd))
    {
      int width;
      int height;
      int sz = 0;
      sz = fread(& width, sizeof(int), 1, fhd);
      sz += fread(& height, sizeof(int), 1, fhd);
      if (sz == 2)
	{
	  printf("%d %d\n", width, height);
	  numRect ++;
	}
    }
  fclose (fhd);
  printf("There are %d rectangles\n", numRect);
  return 0;
}
