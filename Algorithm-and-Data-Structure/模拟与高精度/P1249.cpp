#include<cstdio>
#include<cstring>
#define MAXN 2000

struct BigInt {
    int len;
    int a[MAXN];

    BigInt(){
        memset(a,0,sizeof(a));
    }

    BigInt(int n){
        memset(a,0,sizeof(a));
        if (n==0){
            len=1;
        }
        else {
            len=0;
            while (n>0){
                a[len++]=n%10;
                n=n/10;
            }
        }
    }

    void mul(int k){
        if (!k){
            memset(a,0,sizeof(a));
            len=1;
            return ;
        }

        for (int i=0;i<len;i++){
            a[i]=a[i]*k;
        }
        len=len+6;
        for (int i=0;i<len;i++){
            a[i+1]=a[i+1]+a[i]/10;
            a[i]=a[i]%10;
        }
        while (!a[len-1]){
            len--;
        }
    }

    void print(){
        for (int i=len-1;i>=0;i--){
            printf("%d",a[i]);
        }
        printf("\n");
    }
};

int split[MAXN];
int cnt=0,sum=0,n;

int main(){
    scanf("%d",&n);
    if (n==3){
        printf("3\n3");
    }
    if (n==4){
        printf("4\n4");
    }
    if (n==5){
        printf("2 3\n6");
    }
    for (int i=2;i<n;i++){
        if (sum+i<n){
            split[cnt++]=i;
            sum+=i;
            continue;
        }
        else if (sum+i==n){
            split[cnt++]=i;
            sum+=i;
            break;
        }
        else {
            int res=n-sum;
            int pr=cnt;
            while (res>0){
                if (pr==0) pr+=cnt;
                split[--pr]++;
                res--;
            }
            break;
        }
    }
    BigInt ans=BigInt(1);
    for (int i=0;i<cnt;i++){
        ans.mul(split[i]);
    }
    for (int i=0;i<cnt;i++){
        printf("%d ",split[i]);
    }
    printf("\n");
    ans.print();
    return 0;
}