/*

The interval bisection method works iff 
the function is continuous and you can 
establish an initial left & right guess, 
such that:
   f(left) and f(right) have different signs
(i.e.: one is positive and the other negative)

COMPILE THIS CODE BY RUNNING:

gcc interval_bisection04_lab.c -lm

The -lm links with the math library

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f1 (double x)
{
  double y ;
  y = x*x - 2 ;
  return y ;
}


double f2 (double x)
//  three roots,
//  -3 - sqrt(3) = -4.732050,
//  -3 + sqrt(3) = -1.267949,
//   6
{
  double y ;
  y = x*x*x - 30*x - 36 ;
  return y ;
}


// f points at a function with one double input and a double output 
int interval_bisection(double (*f)(double x), 
		       double left, double right,
		       double epsilon, int maxreps,
		       double results[2])
// return 0 failure, else 'numreps' (>= 1)
// 'maxreps' is the maximum iterations through the loop
{
  double average, interval;
  int numreps = 0;
  while (maxreps > numreps) {
    numreps++;
    average = (left+right)/2;
    interval = right - average;
    if ((interval < epsilon) || (f(average) == 0.0)) {
      results[0] = average;
      results[1] = f(average);
      return numreps;
    }
    if ((f(right) > 0) && (f(left) < 0)) {
      if (f(average) > 0) {
	right = average;
      } else {
	left = average;
      }
    }
    if ((f(right) < 0) && (f(left) > 0)) {
      if (f(average) > 0) {
	left = average;
      } else {
	right = average;
      }
    }
    
  }

  return 0;
  // example of a valid function call to f:
  // double fl ;
  // fl = f(left) ;

  // The algorithm should continue until 'maxreps' iterations have been
  // performed or the width of the interval is within 'epsilon'

  // your code goes here!
}




int main()
{
  int maxreps,numr ;
  double left_guess,right_guess,res[2] ;

  // test #1:
  
  left_guess  = 1 ;
  right_guess = 2 ;

  maxreps = 100 ;
  numr = interval_bisection(f1, left_guess,right_guess,  1e-12, maxreps,  res) ;
  if (numr == 0) {
    printf("Failure to find a root.\n") ;
  } else {
    printf("f(%lf) = %lf, numreps/maxreps = %d/%d\n",res[0],res[1],numr,maxreps) ;
    
    // res[0] is our approximation to a root.
    // res[1] is the function evaluated at res[0],
    // which should be close to 0 if we came close to finding a root.
    
    // NOTE: numreps equals maxreps, if the algorithm performed maxreps repititions
  }

  //////////////////////////////////////////////////////////////


  // test #2 :

  numr = interval_bisection(sin, 3,4,  1e-12, 50,  res) ;
  // for this test the function is the sin(x)
  
  if (numr == 0) {
    printf("Failure to find a root.\n") ;
  } else {
    printf("f(%lf) = %lf, numreps/maxreps = %d/%d\n",res[0],res[1],numr,maxreps) ;
  }

  /////////////////////////////////////////////////////////////
  
  // test #3:
  
  printf("Enter left,right for root search : ") ;
  scanf("%lf %lf",&left_guess,&right_guess) ;

  maxreps = 100 ;
  numr = interval_bisection(f2, left_guess,right_guess,  1e-12, maxreps,  res) ;
  
  if (numr == 0) {
    printf("Failure to find a root.\n") ;
  } else {
    printf("f(%lf) = %lf, numreps/maxreps = %d/%d\n",res[0],res[1],numr,maxreps) ;
  }
  
}
