#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//=== 今回のコンピュータの疑似AIのアルゴリズム ===//
//コンピュータはまず勝てる位置に石を置こうとし、次にプレイヤーの勝利を防ぐための防御を行います。
//それでも置く場所が見つからない場合は、ランダムな位置に石を置きます。

int main(){
    int i, j, k; //カウンタ変数
    int game_num = 0; //何ゲームか数えておく変数
    int board[5][5] = {0}; //盤面 0: 空白, 1: 先攻の石, 2: コンピュータの石
    int x, y; //ユーザが石を置く座標 
    int flag_first = 0, flag_second = 0; //勝利しているかのフラグ
    int min = 0, max = 4; //乱数の最小値と最大値
    int placed; //疑似AI用の変数

    srand((unsigned int)time(NULL));
    while(1){
        //どちらのターンか表示
        if(game_num%2 == 0){
            printf("先攻のターンです\n");
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
        }else{
            printf("コンピュータのターンです\n");
            //コンピュータが勝てる位置があればそこに置く
            placed = 0;
            for(i=0; i<5; i++){
                for(j=0; j<5; j++){
                    if(board[i][j] == 0){
                        board[i][j] = 2; //仮に置く
                        //勝利条件の確認
                        flag_second = 1;
                        //横のチェック
                        for(k=0; k<5; k++){
                            if(board[i][k] != 2){
                                flag_second = 0;
                                break;
                            }
                        }
                        if(flag_second == 1){
                            x = j;
                            y = i;
                            placed = 1;
                            break;
                        }
                        //縦のチェック
                        flag_second = 1;
                        for(k=0; k<5; k++){
                            if(board[k][j] != 2){
                                flag_second = 0;
                                break;
                            }
                        }
                        if(flag_second == 1){
                            x = j;
                            y = i;
                            placed = 1;
                            break;
                        }
                        //右下がりの斜めチェック
                        if(i == j){
                            flag_second = 1;
                            for(k=0; k<5; k++){
                                if(board[k][k] != 2){
                                    flag_second = 0;
                                    break;
                                }
                            }
                            if(flag_second == 1){
                                x = j;
                                y = i;
                                placed = 1;
                                break;
                            }
                        }
                        //右上がりの斜めチェック
                        if(i+j == 4){
                            flag_second = 1;
                            for(k=0; k<5; k++){
                                if(board[k][4-k] != 2){
                                    flag_second = 0;
                                    break;
                                }
                            }
                            if(flag_second == 1){
                                x = j;
                                y = i;
                                placed = 1;
                                break;
                            }
                        }
                        board[i][j] = 0; //元に戻す
                    }
                }
                //置く場所が決定していたら終わり
                if(placed == 1){
                    break;
                }
            }

            //まだ置く場所が決まっていなくて、プレイヤーが勝てる位置があればそこを防御
            if(placed == 0){
                for(i=0; i<5; i++){
                    for(j=0; j<5; j++){
                        if(board[i][j] == 0){
                            board[i][j] = 1; //仮に置く
                            //勝利条件の確認
                            flag_first = 1;
                            //横のチェック
                            for(k=0; k<5; k++){
                                if(board[i][k] != 1){
                                    flag_first = 0;
                                    break;
                                }
                            }
                            if(flag_first == 1){
                                x = j;
                                y = i;
                                placed = 1;
                                break;
                            }
                            //縦のチェック
                            flag_first = 1;
                            for(k=0; k<5; k++){
                                if(board[k][j] != 1){
                                    flag_first = 0;
                                    break;
                                }
                            }
                            if(flag_first == 1){
                                x = j;
                                y = i;
                                placed = 1;
                                break;
                            }
                            //右下がりの斜めチェック
                            if(i == j){
                                flag_first = 1;
                                for(k=0; k<5; k++){
                                    if(board[k][k] != 1){
                                        flag_first = 0;
                                        break;
                                    }
                                }
                                if(flag_first == 1){
                                    x = j;
                                    y = i;
                                    placed = 1;
                                    break;
                                }
                            }
                            //右上がりの斜めチェック
                            if(i+j == 4){
                                flag_first = 1;
                                for(k=0; k<5; k++){
                                    if(board[k][4-k] != 1){
                                        flag_first = 0;
                                        break;
                                    }
                                }
                                if(flag_first == 1){
                                    x = j;
                                    y = i;
                                    placed = 1;
                                    break;
                                }
                            }
                            board[i][j] = 0; //元に戻す
                        }
                    }
                    //置く場所が決定していたら終わり
                    if(placed == 1){
                        break;
                    }
                }
            }

            //その他の場合はランダムに置く
            if(placed == 0){
                do{
                    x = min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
                    y = min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
                }while(board[y][x] != 0);
            }

            printf("%d行目, %d列目\n", y+1, x+1);
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
        flag_first = 0;
        flag_second = 0;
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
                printf("コンピュータの勝利\n");
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
                printf("コンピュータの勝利\n");
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
            printf("コンピュータの勝利\n");
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
            printf("コンピュータの勝利\n");
            exit(1);
        }
        flag_first = 0;
        flag_second = 0;

        game_num++;

        //盤面の全ての場所に石が置いてあったら引き分けで終了
        if(game_num == 25){
            printf("引き分けです\n");
            exit(1);
        }
    }


    return 0;
}