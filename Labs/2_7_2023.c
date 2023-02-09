#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>

complex newCoef[100], secondCoef[100];

complex synthDiv(complex root, int degree, complex coef[], bool second) {
	complex remainder = coef[0];
	
	for (int i=0; i<degree; i++) {
		if (second) {secondCoef[i] = remainder;}
		else {newCoef[i] = remainder;}
		remainder *= root;
		remainder += coef[i+1];
		printf("%lf + %lf*I ",creal(coef[i+1]),cimag(coef[i+1]));
	}
	printf("\n");
	return remainder;
}

complex newtonsMethod(int degree, complex coef[]) {

  double x, y;
  x = 1;
  y = 1;
  complex n, top, bottom;
  bool second;
  n = x+y*I;
  
  for (int i = 0; i < 15; i++) {
    second = false;
    top = synthDiv(n, degree, coef, second);
    second = true;
    bottom = synthDiv(n, degree-1, newCoef, second);
    n = n - top/bottom;
    //printf("%lf + %lfI \n", creal(n), cimag(n));
  }
  return n;
}

int main() {
  	double realCoef;
	complex startCoef[100], roots[100], remainder;
	int degree;
	
	printf("\nWhat degree polynomial? \n");
	scanf("%d", &degree);
	for (int i = 0; i<=degree; i++) {
		printf("\nType coeffecient: \n");
		scanf("%lf", &realCoef);
		startCoef[i] = realCoef + 0*I;
	}
	
	for (int i = 0; i<degree; i++) {
		roots[i] = newtonsMethod(degree-i, startCoef);
		printf("%.3lf + %.3lf*I\n\n", creal(roots[i]), cimag(roots[i]));
		for (int j = 0; j<degree-i; j++) {
			startCoef[j] = newCoef[j];
		}
	}
	
}


