#include <stdio.h>

int main(){
    int i; //�J�E���^�ϐ�
    int a, b, c, d;
    double sum_tan = 0.0, sum_fuku = 0.0; //�P���ƕ����̍��v

    //���������̌���
    printf("����[�~]: ");
    scanf("%d", &a);
    printf("�P��[%%]: ");
    scanf("%d", &b);
    printf("����[%%]: ");
    scanf("%d", &c);
    printf("�N��: ");
    scanf("%d", &d);

    sum_tan += a;
    sum_fuku += a;
    //���ʂ̕\��
    printf("�N��\t �P��[�~]\t ����[�~]\t �������P���𒴂��邩\n");
    for(i=1; i<=d; i++){
        sum_tan += a * b / 100;
        sum_fuku += sum_fuku * c / 100;

        if(sum_fuku < sum_tan){
            printf("%d\t %.0f\t %.0f\t �����Ȃ�\n", i, sum_tan, sum_fuku);
        }else{
            printf("%d\t %.0f\t %.0f\t ������\n", i, sum_tan, sum_fuku);            
        }
    }
    return 0;
}