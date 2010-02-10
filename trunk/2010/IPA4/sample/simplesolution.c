/* example of a timer */
/* sets a timer that triggers every 10 seconds for 4 times */
#include <sys/time.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
int handleCounter = 0;
struct itimerval tval;
void handleTimer(int v)
{
  /* printf("handleTimer\n"); */
  handleCounter ++;
  if (handleCounter < 5) 
    { 
      setitimer(ITIMER_REAL, &tval,0);
      signal(SIGALRM, handleTimer); 
    }
}

int main(int argc, char * argv [])
{
  FILE * fptr = NULL;
  int curX = 0;
  int curY = 0;
  int width = 0;
  int height = 0;
  char oneLine[1024]; /* should be long enough */
  if (argc < 2)
    {
      printf("need the input file\n");
      return -1;
    }
  fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      printf("cannot open file\n");
      return -1;
    }
  while (feof(fptr) == 0)
    {
      /* reset */
      if (fscanf(fptr, "%d %d", & width, & height) == 2)
	{
	  /* ignore area */
	  printf("%d %d 0\n", curX, curY); 
	  /* never rotate */
	  curX += width;
	  curY += height;
	}
    }
  fclose (fptr);
  tval.it_interval.tv_sec = 0;
  tval.it_interval.tv_usec = 0;
  tval.it_value.tv_sec = 1;  /* wait for 1 seconds */
  tval.it_value.tv_usec = 0;
  setitimer(ITIMER_REAL, &tval,0);
  signal(SIGALRM, handleTimer);
  while (handleCounter < 5)
    {
      /* wait for the timer */
    }
  return 0;
}
