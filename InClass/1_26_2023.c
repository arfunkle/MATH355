#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*

  Newton's method:
  x(n+1) = x(n) - f(x(n))/f'(x(n))

 */

// Newton's method vs. fixed point iteration (n & f, R = Root)
// Errors: Interval Bisection f(x) = 0:
//			      e(n+1) <= 0.5*e(n)
//	   Fixed-Point Iteration x = g(x)
//				 e(n+1) ~ g'(R)*e(n)
//	   Newton's Method f(x) = 0
//			   e(n+1) ~ (f"(R)/(2*f'(R)))*e(n)^2
//         root of order 2,3,4 (f'(x) = 0) (from linear error)
//                         e(n+1) = 0.5*e(n), 0.666*e(n), 0.75*e(n)

int main() {
	double x, f, n;
	scanf("%lf", &x);
	f = n = x;
	for (int i = 1; i <= 15; i++) {
		
	  n = n-(3*pow(n,4)-29*pow(n,3)+60*pow(n,2)+144*n-448)/(12*pow(n,3)-87*n*n+120*n+144);
		printf("%20.16lf \n", n);
	}
}
