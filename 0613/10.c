#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int usr_hand, com_hand; //���[�U�̎�ƃR���s���[�^�̎�
    int usr_win = 0, draw = 0; //���[�U�̏���, �����̐�
    int com_win = 0; //�R���s���[�^�̏����̐�

    while(draw < 3 && usr_win < 5 && com_win < 5){ //��������3�A����������5��ɂȂ�܂ŏ����𑱂���
        //�����̎�����߂�
        srand((unsigned int)time(NULL));

        //���[�U�Ɏ����͂��Ă��炤
        printf("�O�[: 0, �`���L: 1, �p�[:2\n");
        printf("���Ȃ��̎����͂��Ă�������\n");
        scanf("%d", &usr_hand);
        //0, 1, 2�̂����ꂩ�łȂ��ꍇ�̓v���O�������I��
        if(!(usr_hand == 0 || usr_hand == 1 || usr_hand == 2)){
            printf("[ERROR!]0, 1, 2�̂����ꂩ����͂��Ă�������\n");
            exit(1);
        }

        //�R���s���[�^�̎�����߂�
        com_hand = rand() % 3;

        //���s�����肷��
        if(usr_hand == com_hand){ //���������̏ꍇ
            printf("��������\n");
            draw++;
        }else if((usr_hand == 0 && com_hand == 1) || (usr_hand == 1 && com_hand == 2) || (usr_hand == 2 && com_hand == 0)){ //���[�U�̏����̏ꍇ
            printf("���Ȃ��̏���\n");
            usr_win++; //���[�U�̏����Ȃ̂ŃC���N�������g
            draw = 0; //���������ł͂Ȃ��̂ŃJ�E���g�����Z�b�g
        }else{ //�����̎�
            printf("���Ȃ��̕���\n");
            draw = 0; //���������ł͂Ȃ��̂ŃJ�E���g�����Z�b�g
            com_win++; //�R���s���[�^���������̂ŃC���N�������g
        }

        printf("���Ȃ�����������: %d, ��������: %d\n", usr_win, com_win);
        printf("���݂̘A����������: %d\n\n", draw);
    }

    if(draw == 3){
        printf("��������3��A���ő������̂ŏ������I���܂���\n");
    }

    if(usr_win == 5){
        printf("���Ȃ������5�񏟗������̂ŏ������I���܂���\n");
    }

    if(com_win == 5){
        printf("�R���s���[�^�����5�񏟗������̂ŏ������I���܂���\n");
    }



    return 0;
}