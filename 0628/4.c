#include <stdio.h>
#include <math.h>

int main(){
    int i; //�J�E���^�ϐ�
    int count = 0; //�p�X���[�h������Ԉ������������ϐ�
    char password[256] = ""; //���[�U����󂯎��p�X���[�h
    int n; //�p�X���[�h�̒���
    long int h; //�n�b�V���l
    //���[�U�ɖK�˂��ۂɎ󂯎��p�X���[�h�ƃn�b�V���l
    char password_[256] = "";
    int n_;
    long int h_;

    printf("�p�X���[�h��o�^���Ă�������: ");
    scanf("%s", password);
    n = 0;
    h = 0;
    for(i=0; password[i]!='\0'; i++){
        n++;
    }
    for(i=0; i<n; i++){
        h += (int)password[i] * pow(31, n-i-1);
    }

    h = h % 4093;

    printf("�n�b�V���l: %ld\n", h);

    while(1){
        printf("�p�X���[�h?: ");
        scanf("%s", password_);
        n_ = 0;
        h_ = 0;
        for(i=0; password_[i]!='\0'; i++){
            n_++;
        }
        for(i=0; i<n_; i++){
            h_ += (int)password_[i] * pow(31, n_-i-1);
        }

        h_ = h_ % 4093;

        printf("�n�b�V���l: %ld\n", h_);

        if(h == h_){
            printf("���O�C�����܂���!\n");
            break;
        }else{
            printf("�p�X���[�h���Ⴂ�܂�\n");
            count++;
        }

        if(count >= 3){
            printf("���O�C���Ɏ��s���܂���\n");
            break;
        }
    }

    return 0;
}