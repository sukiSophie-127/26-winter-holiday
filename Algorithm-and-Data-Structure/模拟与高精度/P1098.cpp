#include<cstdio>
// #include<iostream>
using namespace std;

char tmp,pre=' ',opt1,opt2;
int p1,p2,p3,flag=0;

int main(){
    scanf("%d %d %d%c%c",&p1,&p2,&p3,&opt1,&opt2);
    while ((tmp=getchar())!='\r'){
        if (tmp=='-'){
            flag++;
        }
        else {
            if (!flag){
                if (pre!=' '){
                    printf("%c",pre);
                    pre=tmp;
                }
                else {
                    pre=tmp;
                }
            }
            else if (flag==1){
                if (pre!=' '){
                    if (((pre<=57 && pre>=48)&&(tmp<=57 && tmp>=48))||((pre<=122 && pre>=97)&&(tmp<=122 && tmp>=97))){
                        printf("%c",pre);
                        if (tmp>pre+1){
                            if (p3==1){
                                if (p1==1){
                                    for (int i=pre+1;i<tmp;i++){
                                        for (int j=1;j<=p2;j++){
                                            printf("%c",i);
                                        }
                                    }
                                }
                                else if (p1==2){
                                    if (pre<=122 && pre >=97){
                                        for (int i=pre+1;i<tmp;i++){
                                            for (int j=1;j<=p2;j++){
                                                printf("%c",i-32);
                                            }
                                        }
                                    }
                                    else {
                                        for (int i=pre+1;i<tmp;i++){
                                            for (int j=1;j<=p2;j++){
                                                printf("%c",i);
                                            }
                                        }
                                    }

                                }
                                else {
                                    for (int i=pre+1;i<tmp;i++){
                                        for (int j=1;j<=p2;j++){
                                            printf("*");
                                        }
                                    }
                                }
                            }
                            else {
                                if (p1==1){
                                    for (int i=tmp-1;i>pre;i--){
                                        for (int j=1;j<=p2;j++){
                                            printf("%c",i);
                                        }
                                    }
                                }
                                else if (p1==2){
                                    if ((pre<=122 && pre>=97)){
                                        for (int i=tmp-1;i>pre;i--){
                                            for (int j=1;j<=p2;j++){
                                                printf("%c",i-32);
                                            }
                                        }                                       
                                    }
                                    else {
                                        for (int i=tmp-1;i>pre;i--){
                                            for (int j=1;j<=p2;j++){
                                                printf("%c",i);
                                            }
                                        }
                                    }
                                }
                                else {
                                    for (int i=pre+1;i<tmp;i++){
                                        for (int j=1;j<=p2;j++){
                                            printf("*");
                                        }
                                    }
                                }
                            }
                        }
                        else if (tmp==pre+1){

                        }
                        else {
                            printf("-");
                        }
                    }
                    else {
                        printf("%c-",pre);
                    }
                    pre=tmp;
                }
                else {
                    printf("-");
                    pre=tmp;
                }
                flag--;
            }
            else {
                if (pre!=' '){
                    printf("%c",pre);
                    while (flag>0){
                        printf("-");
                        flag--;
                    }
                    pre=tmp;
                }
                else {
                    while (flag>0){
                        printf("-");
                        flag--;
                    }
                    pre=tmp;
                }
            }
        }
    }
    if (!flag&&pre!=' '){
        printf("%c",pre);
    }
    if (flag==1&&pre!=' '){
        printf("%c-",pre);
    }
    if (flag>1&&pre!=' '){
        printf("%c",pre);
        while (flag>0){
            printf("-");
            flag--;
        }
    }
    return 0;
}