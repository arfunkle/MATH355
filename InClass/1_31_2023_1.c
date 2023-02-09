#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

// Newton's method for complex numbers
// Doesn't work when initialized with only real numbers

int main() {
  int degree;
  double coef[100];
  scanf("%d", &degree);
  for (int i=degree; i>=0; i--) {
    scanf("%lf", &coef[i]);
  }
  
  double x, y;
  complex n, top, bottom;
  scanf("%lf", &x);
  scanf("%lf", &y);
  n = x+y*I;
  
  for (int i = 0; i < 15; i++) {
    top = 0;
    for (int j=0; j<= degree; j++) {
      top += coef[j]*cpow(n,j);
    }
    bottom = 0;
    for (int j=1; j<=degree; j++) {
      bottom += coef[j]*(j)*cpow(n,j-1);
    }
    n = n - top/bottom;
    printf("%lf + %lfI \n", creal(n), cimag(n));
  }
  
}
