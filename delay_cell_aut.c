//1変数のセルオートマトン

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//ODE dv/dt = kx(t-τ) k = -1

double g(double x_delay);
double f(double x_delay);
int Fx(double x_delay,double Tx,int M);
int count_p(int p,int Fx);
int state_trans_x(int x,int p,int Fx,int N);
//int clock_flag(double t,double dt);
// ディレイ時間 = (刻み幅) × (データの個数)
int main(){
  int M = 2000;//分解能
  int N = 2000;//分解能
  double t;
  double Tx = 0.01;//刻み幅
  double cx;//クロック
  double x;//状態変数
  int int_x;//整数型に直した状態変数
  //double n;
  double x_delay[100];
  int  p;//補助変数

  //x_delayの初期化
  for(int i = 0;i<100;i++){
    x_delay[i] = 0.0;
  }

  for(t = 0.0; t < 100;t = t + Tx){
    x_tau[0] = x;
    dx = Tx * f(x_tau[99]);
    x = x + dx;
    printf("%f",x);
    printf("\n");
    for(i=99;i>=1;i--){
      x_tau[i] = x_tau[i-1];
    }
  }
  /**
  x_delay[0] = 1.0;
  printf("Fx(1.0,0.01,2000) = %d\n",Fx(x_delay[0],Tx,M));
  **/
  return 0;
}

double f(double x_delay){
  double k = -1;
  return k * x_delay;
}

double g(double x_delay){
  double g;
  double gamma = 500;
  g = gamma * f(x_delay);
  return g;
}

int  Fx(double x_delay,double Tx,int M){
  double Fx_r;
  int Fx_i;
  int gamma = 500;
  Fx_r = gamma / (g(x_delay) * Tx);
  Fx_i = (int)Fx_r;
  if(Fx_i > (M - 1)){
    return M - 1;
  }else if (Fx_i < - (M-1)){
    return - (M-1);
  } else{
    return Fx_i;
  }
}

int count_p(int p,int Fx){
  if(p < abs(Fx)){
    return p = p + 1;
  }else if (p >= abs(Fx)){
    return p = 0;
  }else{
    return 0;
  }
}

int state_trans_x(int x,int p,int Fx,int N){
  if((x =! (N-1)) && (Fx>=0)){
    x = x + 1;
  }else if((x =! 0) && (Fx < 0)){
    x = x - 1;
  }else{
    x = x;
  }
  return x;
}

//分岐解析をするなら、malloc()で配列を動的確保しないといけないかも・・・・
//x(double)の更新をしないと、
/**
int clock_flag(double t,double dt){
  int flag = 0;
  return flag;
}
**/
