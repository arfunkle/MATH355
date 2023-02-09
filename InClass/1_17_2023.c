#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  int i;
  double x,y,third;

  x = -1.41421356237;
  // "uninitialized variables are in league with the devil"

  for (i = 1; i <= 30; i++) {
    
    x = (x+2)/(x+1);
    printf("%20.16lf\n", x);
  }
  y = x*x - 2;
  printf("%lf\n", y);
  
  // fixed point iteration: reaching a point where the function converges
  // not always going to work

  // root attracts when |g'(r)| < 1, repels when |g'(r)| > 1
}
