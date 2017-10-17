#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//レンジ 1~-0.5

double k = 1.0;
double tau = 1.0;

double f(double x);

int main(){
  double x = 1.0;//x(t)の変数
  double t = 0.0;
  double dt = 0.01;
  double dx;
  double x_tau[100];
  int i;
  int gamma = 500;

  for(i=0;i<100;i++){
    x_tau[i] = 0.0;
  }

  //x = x * gamma;//初期値
  for(t = 0; t < 100;t=t+dt){
    x_tau[0] = x;
    dx =  dt * f(x_tau[99]);
    x = x + dx;
    printf("%f",x*500);
    printf("\n");
    for(i=99;i>=1;i--){
      x_tau[i] = x_tau[i-1];
    }
  }
  return 0;
}


double f(double x){
  return (-1)*k*x;
}
