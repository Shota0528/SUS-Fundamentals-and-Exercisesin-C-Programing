#include <stdio.h>
#include <stdlib.h>

int main(){
    int i; //カウンタ変数
    int game_num = 0; //何ゲームか数えておく変数
    int remove_stone_num = 0; //取り除く石の個数
    int remove_stone_min = 1, remove_stone_max = 3; //取り除くことができる石の個数の最小値と最大値
    int stone_num = 20; //場の石の個数

    while(1){
        //どちらのターンか表示
        if(game_num%2 == 0){
            printf("先行のターンです\n");
        }else{
            printf("後攻のターンです\n");
        }
        
        //場の石の個数を表示
        printf("場の石の個数: ");
        for(i=0; i<stone_num; i++){
            printf("◯");
        }
        printf("\n");

        //個数を訪ねて石を取り除く
        printf("何個石を取りますか？");
        scanf("%d", &remove_stone_num);
        if(remove_stone_num < remove_stone_min || remove_stone_num > remove_stone_max){
            printf("取れる石の個数は%d~%d個です\n", remove_stone_min, remove_stone_max);
            exit(0);
        }
        stone_num -= remove_stone_num;

        if(stone_num <= 0){
            printf("場の石が全て取られました\n");
            if(game_num%2 == 0){
                printf("後攻の勝利です\n");
            }else{
                printf("先行の勝利です\n");
            }

            exit(0);
        }

        game_num++;
    }

    return 0;
}