#include<cstring>
#include<cstdio>
#define MAXN 1000000

using namespace std;

struct BigInt {
    int len;
    int num[MAXN];
    int cnt;

    BigInt(){
        len=1;
        cnt=0;
        memset(num,0,sizeof(num));
    }

    BigInt(int n){
        memset(num,0,sizeof(num));
        if (n==0){
            len=1;
            return ;
        }
        len=0;
        while (n>0){
            num[len++]=n%10;
            n=n/10;
        }
        cnt=0;
    }

    void mul(BigInt other){
        if (other.len==1&&other.num[0]==0){
            len=1;
            memset(num,0,sizeof(num));
            return;
        }
        BigInt ans=BigInt(0);
        for (int i=0;i<len;i++){
            for (int j=0;j<other.len;j++){
                ans.num[i+j]+=num[i]*other.num[j];
            }
        }
        ans.len=len+other.len+1;
        for (int i=0;i<ans.len;i++){
            ans.num[i+1]+=ans.num[i]/10;
            ans.num[i]%=10;
        }
        while (!ans.num[ans.len-1]){
            ans.len--;
        }
        memcpy(num,ans.num,sizeof(num));
    }

    void print(){
        for (int i=1;i<=500-len;i++){
            printf("0");
            cnt++;
            if (cnt%50==0){
                printf("\n");
            }
        }
        for (int i=len-1;i>=0;i--){
            printf("%d",num[i]);
            cnt++;
            if (cnt%50==0){
                printf("\n");
            }
        }
    }
};

int p;

BigInt pow(int p){
    BigInt res=BigInt(1);
    BigInt tmp=BigInt(2);
    while (p>0){
        if (p%2==1){
            res.mul(tmp);
        }
        tmp.mul(tmp);
        p/=2;
    }
    return res;
}

int main(){
    scanf("%d",&p);
    BigInt ans=pow(p);
    ans.num[0]-=1;
    printf("%d\n",ans.len);
    ans.print();
    return 0;
}