/* example of a timer */
/* sets a timer that triggers every 5 seconds for 5 times */
#include <sys/time.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
int handleCounter = 0;
struct itimerval tval;
void handleTimer(int v)
{
  printf("handleTimer %d\n", handleCounter); 
  handleCounter ++;
  if (handleCounter < 5) 
    { 
      setitimer(ITIMER_REAL, &tval,0);
      signal(SIGALRM, handleTimer); 
    }
}

int main(int argc, char * argv [])
{
  tval.it_interval.tv_sec = 0;
  tval.it_interval.tv_usec = 0;
  tval.it_value.tv_sec = 5;  /* wait for 1 seconds */
  tval.it_value.tv_usec = 0;
  setitimer(ITIMER_REAL, &tval,0);
  signal(SIGALRM, handleTimer);
  while (handleCounter < 5)
    {
      /* wait for the timer */
    }
  return 0;
}
