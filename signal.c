#include <stdio.h>
#include <stdlib.h> // exit
#include <unistd.h> // sleep
#include <signal.h> // signal

void (*signal(int signum, void (*sighandler)(int signum)))(int signum);
// 同じ intをとる
#define SIG_ERR ((void (*)(int))-1) // SIG_ERR

void Input(void){

  while(1) {
    printf("実行中!!\n");
    sleep(2); }
}

/* シグナル受信/処理 */
void SigHandler(int p_signame){
  static int   sig_cnt = 0;
  ++sig_cnt;

  if (sig_cnt <= 2) {
    printf(" %d回目の割り込みです。無視します\n",sig_cnt);
  }else{printf("%d回目の割り込みです。終了します\n",sig_cnt);
    exit(0); }
}

/* シグナルの設定 */
void SetSignal(int p_signame){
 sig_t old; // ヘッダーで定義 typedef void (*sig_t)(int);
   old = signal( p_signame, SigHandler ); // signal関数
    if (old == ((void (*)(int))-1)){
//    if( old == SIG_ERR ) {
/* シグナル設定エラー シグナル処理関数 SIG_ERR */
    printf("シグナルの設定が出来ませんでした。終了します\n");
    exit(1); }
}

int main(void){
  SetSignal(SIGINT);
//signal(SIGINT,SigHandler); // signal関数
  Input();
  return 0;
}
