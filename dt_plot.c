//dxを求めて、x引数でdxを返すプログラム

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double k = 1.0;

double f(int x);
int gx(int x,int omega);

int main(){
  double x_data[1000];
  double dx = 0.01;
  double x_tau[100];
  double t;
  double dt = 0.01;

  for(int x = 0;x < 100;x++){
    printf("%f\n",gx(x,500));
  }
  return 0;
}

double f(int x){
  return (-1)*k*x;
}

int gx(int x,int omega){
  return omega*f(x);
}
