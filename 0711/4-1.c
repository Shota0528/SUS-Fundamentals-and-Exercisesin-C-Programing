#include <stdio.h>
#include <stdlib.h>

int main(){
    int i; //�J�E���^�ϐ�
    int game_num = 0; //���Q�[���������Ă����ϐ�
    int remove_stone_num = 0; //��菜���΂̌�
    int remove_stone_min = 1, remove_stone_max = 3; //��菜�����Ƃ��ł���΂̌��̍ŏ��l�ƍő�l
    int stone_num = 20; //��̐΂̌�

    while(1){
        //�ǂ���̃^�[�����\��
        if(game_num%2 == 0){
            printf("��s�̃^�[���ł�\n");
        }else{
            printf("��U�̃^�[���ł�\n");
        }
        
        //��̐΂̌���\��
        printf("��̐΂̌�: ");
        for(i=0; i<stone_num; i++){
            printf("��");
        }
        printf("\n");

        //����K�˂Đ΂���菜��
        printf("���΂����܂����H");
        scanf("%d", &remove_stone_num);
        if(remove_stone_num < remove_stone_min || remove_stone_num > remove_stone_max){
            printf("����΂̌���%d~%d�ł�\n", remove_stone_min, remove_stone_max);
            exit(0);
        }
        stone_num -= remove_stone_num;

        if(stone_num <= 0){
            printf("��̐΂��S�Ď���܂���\n");
            if(game_num%2 == 0){
                printf("��U�̏����ł�\n");
            }else{
                printf("��s�̏����ł�\n");
            }

            exit(0);
        }

        game_num++;
    }

    return 0;
}