#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 10000

struct Bigint {
    int len;
    int num[MAXN];

    Bigint(){
        len=0;
        memset(num,0,sizeof(num));
    }

    Bigint(int k){
        while (k>0){
            num[len++]=k%10;
            k=k/10;
        }
    }

    void flatten(int k){
        len=k;
        for (int i=0;i<len;i++){
            num[i+1]+=num[i]/10;
            num[i]=num[i]%10;
        }
        while (!num[len]){
            len--;
        }
        len++;
    }

    Bigint operator*(int k){
        Bigint res;
        for (int i=0;i<this->len;i++){
            res.num[i]=this->num[i]*k;
        }
        res.flatten(this->len+6);
        return res;
    }
    void print(){
        for (int i=0;i<this->len;i++){
            printf("%d",this->num[i]);
        }
        printf("\n");
    }
};

Bigint f(int k){
    Bigint res=Bigint(1);
    for (int i=k;i>=1;i--){
        res=res*i;
    }
    return res;
}

int t,n,a,cnt=0;
int ans[11];

int main(){
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d %d",&n,&a);
        Bigint tmp=f(n);
        for (int i=0;i<tmp.len;i++){
            if (tmp.num[i]==a){
                cnt++;
            }
        }
        ans[i]=cnt;
        cnt=0;
    }
    for (int i=0;i<t;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
