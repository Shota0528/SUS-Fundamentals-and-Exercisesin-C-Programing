#include <stdio.h>

#define N 3

int main(){
    int i, j; //�J�E���^�ϐ�
    int x, y; //���݂̐�����������W
    int x_next, y_next; //���̐�����������W
    int magic_square[N+1][N+1]; //���@�w�����Ă����z��

    //���@�w�̂��ׂẴ}�X��1�ŏ���������
    for(i=0; i<N+1; i++){
        for(j=0; j<N+1; j++){
            magic_square[i][j] = 1;
        }
    }

    //�O���ȊO��0�ɂ���
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            magic_square[i][j] = 0;
        }
    }

    //�菇1
    x = (N+1) / 2;
    y = 1;
    magic_square[y][x] = 1;

    //�菇2, 3
    for(i=2; i<=N*N; i++){
        //�E����w��
        x_next = x + 1;
        y_next = y - 1;

        //���@�w�͈�ԉE�ƈ�ԍ��A��ԏ�ƈ�ԉ����Ȃ����Ă���̂ŁA�O�ɏo�����荞�ނ悤�ɍl����Ηǂ�
        //�E�オ���@�w�̊O�������ꍇ����荞�ނ悤�ɂ���
        if(x_next > N){
            x_next = 1;
        }
        if(y_next < 1){
            y_next = N;
        }

        //���ɂ����ꏊ�ɂ��łɐ���������ꍇ�͉��ɐ����������
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