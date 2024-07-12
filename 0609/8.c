#include <stdio.h>

int main(){
    int i; //カウンタ変数
    int a, b, c, d;
    double sum_tan = 0.0, sum_fuku = 0.0; //単利と複利の合計

    //初期条件の決定
    printf("元金[円]: ");
    scanf("%d", &a);
    printf("単利[%%]: ");
    scanf("%d", &b);
    printf("複利[%%]: ");
    scanf("%d", &c);
    printf("年数: ");
    scanf("%d", &d);

    sum_tan += a;
    sum_fuku += a;
    //結果の表示
    printf("年数\t 単利[円]\t 複利[円]\t 複利が単利を超えるか\n");
    for(i=1; i<=d; i++){
        sum_tan += a * b / 100;
        sum_fuku += sum_fuku * c / 100;

        if(sum_fuku < sum_tan){
            printf("%d\t %.0f\t %.0f\t 超えない\n", i, sum_tan, sum_fuku);
        }else{
            printf("%d\t %.0f\t %.0f\t 超える\n", i, sum_tan, sum_fuku);            
        }
    }
    return 0;
}