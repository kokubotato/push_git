#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gx(int x_delay,int *val);
int Fx(int x_delay,double Tx,int M,int *val);
int count_p(int p,int Fx);
int state_trans_x(int x,int p,int Fx,int N);

int main(void) {
  FILE *fp;  /* ファイルポインタの宣言 */
  //int x;
  int line = 0;//ファイルの行数
  int i = 0;//イテレータ
  int x;
  char buf[20];
  int data_count;
  int read_size;
  int *val;
  if ((fp = fopen("dt_data.txt","r")) == NULL) {  /* ファイルのオープン */
    printf("file open error!!\n");
    return 1;
  }
  //freadは引数に格納先のデータのポインタ、指定バイト数読み込み、戻り値は読み込んだ
  while ((read_size = fread(buf,1,20, fp)) > 0) {
    for (int j = 0; j < read_size; j++) {//intでもsize_tでもOK!!
      if (buf[j] == '\n') line++;
    }
  }
  printf("%d\n", line);
  fclose(fp);  /* ファイルのクローズ */

  //メモリの動的確保
  val = (int*)malloc(sizeof(int)*line);

  if ((fp = fopen("dt_data.txt","r")) == NULL) {  /* ファイルのオープン */
    printf("file open error!!\n");
    return 1;
  }
  i = 0;
  while (fscanf(fp, "%d",val+i) != EOF){
    //printf("%d\n",*(val+i));
    //val++;
    i++;
  }
  fclose(fp);  /* ファイルのクローズ */
  //表示
  data_count = i;
  for(x=0;x<data_count;x++){
    printf("gx = %d\n",gx(x,val));
  }
  free(val);//メモリ解放
  return 0;
}

int gx(int x_delay,int *val){
  return *(val+x_delay);
}

int  Fx(int x_delay,double Tx,int M,int *val){
  double Fx_r;
  int Fx_i;
  int gamma = 500;

  Fx_r = gamma / (gx(x_delay,val) * Tx);
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
