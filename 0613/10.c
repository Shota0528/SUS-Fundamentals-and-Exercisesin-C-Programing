#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int usr_hand, com_hand; //ユーザの手とコンピュータの手
    int usr_win = 0, draw = 0; //ユーザの勝ち, 分けの数
    int com_win = 0; //コンピュータの勝ちの数

    while(draw < 3 && usr_win < 5 && com_win < 5){ //あいこが3連続か勝ちが5回になるまで勝負を続ける
        //乱数の種を決める
        srand((unsigned int)time(NULL));

        //ユーザに手を入力してもらう
        printf("グー: 0, チョキ: 1, パー:2\n");
        printf("あなたの手を入力してください\n");
        scanf("%d", &usr_hand);
        //0, 1, 2のいずれかでない場合はプログラムを終了
        if(!(usr_hand == 0 || usr_hand == 1 || usr_hand == 2)){
            printf("[ERROR!]0, 1, 2のいずれかを入力してください\n");
            exit(1);
        }

        //コンピュータの手を決める
        com_hand = rand() % 3;

        //勝敗を決定する
        if(usr_hand == com_hand){ //引き分けの場合
            printf("引き分け\n");
            draw++;
        }else if((usr_hand == 0 && com_hand == 1) || (usr_hand == 1 && com_hand == 2) || (usr_hand == 2 && com_hand == 0)){ //ユーザの勝ちの場合
            printf("あなたの勝ち\n");
            usr_win++; //ユーザの勝ちなのでインクリメント
            draw = 0; //引き分けではないのでカウントをリセット
        }else{ //負けの時
            printf("あなたの負け\n");
            draw = 0; //引き分けではないのでカウントをリセット
            com_win++; //コンピュータが勝ったのでインクリメント
        }

        printf("あなたが勝った数: %d, 負けた数: %d\n", usr_win, com_win);
        printf("現在の連続あいこ数: %d\n\n", draw);
    }

    if(draw == 3){
        printf("あいこが3回連続で続いたので勝負が終わりました\n");
    }

    if(usr_win == 5){
        printf("あなたが先に5回勝利したので勝負が終わりました\n");
    }

    if(com_win == 5){
        printf("コンピュータが先に5回勝利したので勝負が終わりました\n");
    }



    return 0;
}