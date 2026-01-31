#include<cstdio>
#define MAXN 2000
using namespace std;

int digit[10]={6,2,5,5,4,5,6,3,7,6};

int f(int n){
    if (n==0) return digit[0];
    int res=0;
    while (n>0){
        res+=digit[n%10];
        n=n/10;
    }
    return res;
}

int n;
int num[MAXN];
int ans=0;

int main(){
    scanf("%d",&n);
    if (n<13){
        printf("0");
        return 0;
    }
    for (int i=0;i<MAXN;i++){
        num[i]=f(i);
    }
    for (int i=0;i<MAXN/2;i++){
        for (int j=0;j<MAXN/2;j++){
            if (num[i]+num[j]+num[i+j]==n-4){
                ans++;
                // printf("%d+%d=%d\n",i,j,i+j);
            }
        }
    }
    printf("%d",ans);
    return 0;
}