#include <stdio.h>
#include <math.h>

int main(){
    int i; //カウンタ変数
    int count = 0; //パスワードが何回間違ったか数える変数
    char password[256] = ""; //ユーザから受け取るパスワード
    int n; //パスワードの長さ
    long int h; //ハッシュ値
    //ユーザに訪ねた際に受け取るパスワードとハッシュ値
    char password_[256] = "";
    int n_;
    long int h_;

    printf("パスワードを登録してください: ");
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

    printf("ハッシュ値: %ld\n", h);

    while(1){
        printf("パスワード?: ");
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

        printf("ハッシュ値: %ld\n", h_);

        if(h == h_){
            printf("ログインしました!\n");
            break;
        }else{
            printf("パスワードが違います\n");
            count++;
        }

        if(count >= 3){
            printf("ログインに失敗しました\n");
            break;
        }
    }

    return 0;
}