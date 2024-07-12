#include <stdio.h>

#define N 3

int main(){
    int i, j; //カウンタ変数
    int x, y; //現在の数字が入る座標
    int x_next, y_next; //次の数字が入る座標
    int magic_square[N+1][N+1]; //魔法陣を入れておく配列

    //魔法陣のすべてのマスを1で初期化する
    for(i=0; i<N+1; i++){
        for(j=0; j<N+1; j++){
            magic_square[i][j] = 1;
        }
    }

    //外側以外を0にする
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            magic_square[i][j] = 0;
        }
    }

    //手順1
    x = (N+1) / 2;
    y = 1;
    magic_square[y][x] = 1;

    //手順2, 3
    for(i=2; i<=N*N; i++){
        //右上を指定
        x_next = x + 1;
        y_next = y - 1;

        //魔法陣は一番右と一番左、一番上と一番下がつながっているので、外に出たら回り込むように考えれば良い
        //右上が魔法陣の外だった場合を回り込むようにする
        if(x_next > N){
            x_next = 1;
        }
        if(y_next < 1){
            y_next = N;
        }

        //次にいれる場所にすでに数字がある場合は下に数字をいれる
        if(magic_square[y_next][x_next] != 0){
            x_next = x;
            y_next = y + 1;
        }

        magic_square[y_next][x_next] = i;
        x = x_next;
        y = y_next;
    }

    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            printf("%2d ", magic_square[i][j]);
        }
        printf("\n");
    }
    return 0;
}