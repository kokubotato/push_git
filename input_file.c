#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  FILE *fp;  /* ファイルポインタの宣言 */
  double x[200];
  int line = 0;
  int i = 0;
  char buf[20];
  int data_count;
  int read_size;
  int *val;
  if ((fp = fopen("dt_data.txt","r")) == NULL) {  /* ファイルのオープン */
    printf("file open error!!\n");
    return 1;
  }
  //freadは引数に格納先のデータのポインタ、指定バイト数読み込み、か戻り値は読み込んだ
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
    //printf("i = %d\n",i);
    printf("%d\n",*(val+i));
    //val++;
    i++;
  }
  fclose(fp);  /* ファイルのクローズ */
  //表示
  data_count = i;
  for(i = 0;i<data_count;i++){
    //printf("%f\n",*(val+i));
    //printf("%d,%lf\n",gx_fun[i].x,gx_fun[i].gx);
  }
  free(val);//メモリ解放
  return 0;
}
