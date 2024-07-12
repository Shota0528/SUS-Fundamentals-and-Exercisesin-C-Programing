#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j; //�J�E���^�ϐ�
    int game_num = 0; //���Q�[���������Ă����ϐ�
    int board[5][5] = {0}; //�Ֆ� 0: ��, 1: ��U�̐�, 2: ��U�̐�
    int x, y; //���[�U���΂�u�����W 
    int flag_first = 0, flag_second = 0; //�������Ă��邩�̃t���O

    while(1){
        //�ǂ���̃^�[�����\��
        if(game_num%2 == 0){
            printf("��U�̃^�[���ł�\n");
        }else{
            printf("��U�̃^�[���ł�\n");
        }

        //�΂������Ă��炤
        printf("�΂�u���ꏊ�������ĉ�����\n");
        printf("���s�ځH: ");
        scanf("%d", &y);
        printf("����ځH: ");
        scanf("%d", &x);

        //�����₷���悤�ɐ��`
        y -= 1;
        x -= 1;

        if(board[y][x] != 0){
            printf("�����ɂ͒u���܂���\n");
            exit(1);
        }

        //�΂�u��
        if(game_num%2 == 0){
            board[y][x] = 1;
        }else{
            board[y][x] = 2;
        }

        //�Ֆʂ�\��
        printf("���݂̔Ֆ�\n");
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                if(board[i][j] == 0){
                    printf("|   ");
                }else if(board[i][j] == 1){
                    printf("| �� ");
                }else{
                    printf("| ? ");
                }
            }
            printf("|\n");
        }

        //���������̊m�F
        //���ő����Ă��邩���m�F
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
                printf("��U�̏���\n");
                exit(1);
            }
            if(flag_second == 5){
                printf("��U�̏���\n");
                exit(1);
            }
            flag_first = 0;
            flag_second = 0;
        }

        //�c�ő����Ă��邩���m�F
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
                printf("��U�̏���\n");
                exit(1);
            }
            if(flag_second == 5){
                printf("��U�̏���\n");
                exit(1);
            }
            flag_first = 0;
            flag_second = 0;
        }

        //�E������̎΂߂ő����Ă��邩���m�F
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
            printf("��U�̏���\n");
            exit(1);
        }
        if(flag_second == 5){
            printf("��U�̏���\n");
            exit(1);
        }
        flag_first = 0;
        flag_second = 0;

        //�E�オ��̎΂߂ő����Ă��邩���m�F
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
            printf("��U�̏���\n");
            exit(1);
        }
        if(flag_second == 5){
            printf("��U�̏���\n");
            exit(1);
        }
        flag_first = 0;
        flag_second = 0;

        game_num++;
    }


    return 0;
}