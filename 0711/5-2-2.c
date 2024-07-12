#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//=== ����̃R���s���[�^�̋^��AI�̃A���S���Y�� ===//
//�R���s���[�^�͂܂����Ă�ʒu�ɐ΂�u�����Ƃ��A���Ƀv���C���[�̏�����h�����߂̖h����s���܂��B
//����ł��u���ꏊ��������Ȃ��ꍇ�́A�����_���Ȉʒu�ɐ΂�u���܂��B

int main(){
    int i, j, k; //�J�E���^�ϐ�
    int game_num = 0; //���Q�[���������Ă����ϐ�
    int board[5][5] = {0}; //�Ֆ� 0: ��, 1: ��U�̐�, 2: �R���s���[�^�̐�
    int x, y; //���[�U���΂�u�����W 
    int flag_first = 0, flag_second = 0; //�������Ă��邩�̃t���O
    int min = 0, max = 4; //�����̍ŏ��l�ƍő�l
    int placed; //�^��AI�p�̕ϐ�

    srand((unsigned int)time(NULL));
    while(1){
        //�ǂ���̃^�[�����\��
        if(game_num%2 == 0){
            printf("��U�̃^�[���ł�\n");
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
        }else{
            printf("�R���s���[�^�̃^�[���ł�\n");
            //�R���s���[�^�����Ă�ʒu������΂����ɒu��
            placed = 0;
            for(i=0; i<5; i++){
                for(j=0; j<5; j++){
                    if(board[i][j] == 0){
                        board[i][j] = 2; //���ɒu��
                        //���������̊m�F
                        flag_second = 1;
                        //���̃`�F�b�N
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
                        //�c�̃`�F�b�N
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
                        //�E������̎΂߃`�F�b�N
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
                        //�E�オ��̎΂߃`�F�b�N
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
                        board[i][j] = 0; //���ɖ߂�
                    }
                }
                //�u���ꏊ�����肵�Ă�����I���
                if(placed == 1){
                    break;
                }
            }

            //�܂��u���ꏊ�����܂��Ă��Ȃ��āA�v���C���[�����Ă�ʒu������΂�����h��
            if(placed == 0){
                for(i=0; i<5; i++){
                    for(j=0; j<5; j++){
                        if(board[i][j] == 0){
                            board[i][j] = 1; //���ɒu��
                            //���������̊m�F
                            flag_first = 1;
                            //���̃`�F�b�N
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
                            //�c�̃`�F�b�N
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
                            //�E������̎΂߃`�F�b�N
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
                            //�E�オ��̎΂߃`�F�b�N
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
                            board[i][j] = 0; //���ɖ߂�
                        }
                    }
                    //�u���ꏊ�����肵�Ă�����I���
                    if(placed == 1){
                        break;
                    }
                }
            }

            //���̑��̏ꍇ�̓����_���ɒu��
            if(placed == 0){
                do{
                    x = min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
                    y = min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
                }while(board[y][x] != 0);
            }

            printf("%d�s��, %d���\n", y+1, x+1);
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
        flag_first = 0;
        flag_second = 0;
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
                printf("�R���s���[�^�̏���\n");
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
                printf("�R���s���[�^�̏���\n");
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
            printf("�R���s���[�^�̏���\n");
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
            printf("�R���s���[�^�̏���\n");
            exit(1);
        }
        flag_first = 0;
        flag_second = 0;

        game_num++;

        //�Ֆʂ̑S�Ă̏ꏊ�ɐ΂��u���Ă���������������ŏI��
        if(game_num == 25){
            printf("���������ł�\n");
            exit(1);
        }
    }


    return 0;
}