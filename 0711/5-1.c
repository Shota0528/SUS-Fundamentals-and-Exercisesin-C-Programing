#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j; //カウンタ変数
    int game_num = 0; //何ゲームか数えておく変数
    int board[5][5] = {0}; //盤面 0: 空白, 1: 先攻の石, 2: 後攻の石
    int x, y; //ユーザが石を置く座標 
    int flag_first = 0, flag_second = 0; //勝利しているかのフラグ

    while(1){
        //どちらのターンか表示
        if(game_num%2 == 0){
            printf("先攻のターンです\n");
        }else{
            printf("後攻のターンです\n");
        }

        //石をおいてもらう
        printf("石を置く場所を教えて下さい\n");
        printf("何行目？: ");
        scanf("%d", &y);
        printf("何列目？: ");
        scanf("%d", &x);

        //扱いやすいように整形
        y -= 1;
        x -= 1;

        if(board[y][x] != 0){
            printf("そこには置けません\n");
            exit(1);
        }

        //石を置く
        if(game_num%2 == 0){
            board[y][x] = 1;
        }else{
            board[y][x] = 2;
        }

        //盤面を表示
        printf("現在の盤面\n");
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                if(board[i][j] == 0){
                    printf("|   ");
                }else if(board[i][j] == 1){
                    printf("| ○ ");
                }else{
                    printf("| ? ");
                }
            }
            printf("|\n");
        }

        //勝利条件の確認
        //横で揃っているかを確認
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                if(board[i][j] == 1){
                    flag_first++;
                }
                if(board[i][j] == 2){
                    flag_second++;
                }
            }
            if(flag_first == 5){
                printf("先攻の勝利\n");
                exit(1);
            }
            if(flag_second == 5){
                printf("後攻の勝利\n");
                exit(1);
            }
            flag_first = 0;
            flag_second = 0;
        }

        //縦で揃っているかを確認
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                if(board[j][i] == 1){
                    flag_first++;
                }
                if(board[j][i] == 2){
                    flag_second++;
                }
            }
            if(flag_first == 5){
                printf("先攻の勝利\n");
                exit(1);
            }
            if(flag_second == 5){
                printf("後攻の勝利\n");
                exit(1);
            }
            flag_first = 0;
            flag_second = 0;
        }

        //右下がりの斜めで揃っているかを確認
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                if(i == j){
                    if(board[i][j] == 1){
                        flag_first++;
                    }
                    if(board[i][j] == 2){
                        flag_second++;
                    }
                }
            }
        }
        if(flag_first == 5){
            printf("先攻の勝利\n");
            exit(1);
        }
        if(flag_second == 5){
            printf("後攻の勝利\n");
            exit(1);
        }
        flag_first = 0;
        flag_second = 0;

        //右上がりの斜めで揃っているかを確認
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                if(i+j == 4){
                    if(board[i][j] == 1){
                        flag_first++;
                    }
                    if(board[i][j] == 2){
                        flag_second++;
                    }
                }
            }
        }
        if(flag_first == 5){
            printf("先攻の勝利\n");
            exit(1);
        }
        if(flag_second == 5){
            printf("後攻の勝利\n");
            exit(1);
        }
        flag_first = 0;
        flag_second = 0;

        game_num++;
    }


    return 0;
}