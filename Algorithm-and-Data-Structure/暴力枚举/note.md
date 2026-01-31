### P3392

#### 最优解(我的代码)

```C++
#include<cstdio>
#include<cstring>
#define MAXN 60
#define min(a,b) ((a<b)?(a):(b))
using namespace std;

int a[MAXN][3];
int n,m;
int ans=MAXN*MAXN+10;
int res=0;

int main(){
    memset(a,0,sizeof(a));
    scanf("%d %d",&n,&m);
    char tmp;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf(" %c",&tmp);
            if (tmp=='W') a[i][0]++;  //white is 0
            else if (tmp=='B') a[i][1]++;  //blue is 1
            else a[i][2]++;  //red is 2
        }
    }
    for (int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            res=0;
            for (int p=0;p<=i-1;p++){
                res+=a[p][1]+a[p][2];
            }
            for (int p=i;p<=j-1;p++){
                res+=a[p][0]+a[p][2];
            }
            for (int p=j;p<=n-1;p++){
                res+=a[p][0]+a[p][1];
            }
            ans=min(ans,res);
        }
    }
    printf("%d",ans);
    return 0;
}
```

因为n,m<=50所以可以暴力枚举


### P3654

#### 最优解(我的代码)

```C++
#include<cstdio>
#include<cstring>
#define MAXN 110
#define max(a,b) ((a>b)?(a):(b))
using namespace std;

int a[MAXN][MAXN];
int dx[2]={1,0};
int dy[2]={0,1};
int r,c,k;
int ans=0,other_ans=0;

int main(){
    memset(a,0,sizeof(a));
    scanf("%d %d %d",&r,&c,&k);
    char tmp;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            scanf(" %c",&tmp);
            if (tmp=='.'){
                a[i][j]=1;
                other_ans++;
            }
        }
    }
    if (k==1){
        printf("%d",other_ans);
        return 0;
    }
    //注释部分为O(n^3)复杂度,非注释部分为O(n^2)
    // for (int i=1;i<=r;i++){
    //     for (int j=1;j<=c;j++){
    //         if (a[i][j]){
    //             for (int p=0;p<2;p++){
    //                 int res=1;
    //                 while (a[i+dx[p]*res][j+dy[p]*res]){
    //                     res++;
    //                 }
    //                 if (res>=k) ans++;
    //             }
    //         }
    //     }
    // }
    for (int i=1;i<=r;i++){
        int res=0;
        for (int j=1;j<=c;j++){
            if (a[i][j]) res++;
            else {
                ans+=max(0,res-k+1);
                res=0;
            }
        }
        ans+=max(0,res-k+1);
    }
    for (int j=1;j<=c;j++){
        int res=0;
        for (int i=1;i<=r;i++){
            if (a[i][j]) res++;
            else {
                ans+=max(0,res-k+1);
                res=0;
            }
        }
        ans+=max(0,res-k+1);
    }
    printf("%d",ans);
    return 0;
}
```

### P1217

#### 最优解

```C++
#include <cstdio>
#include <stdbool.h>
#include <cmath>

bool is_prime(int n){
    if(n<2)return false;
    if(n==2)return true;
    if(n%2==0)return false;
    int limit=(int)sqrt(n);
    for(int i=3;i<=limit;i+=2){
        if(n%i==0)return false;
    }
    return true;
}

void check_and_print(int num,int a,int b){
    if(num>=a&&num<=b&&is_prime(num)){
        printf("%d\n",num);
    }
}

int main(){
    int a,b;
    if(scanf("%d %d",&a,&b)!=2)return 0;
    for(int d1=1;d1<=9;d1++){
        check_and_print(d1,a,b);
    }
    check_and_print(11,a,b);
    if(b>=101){
        for(int d1=1;d1<=9;d1+=2){
            for(int d2=0;d2<=9;d2++){
                int num=d1*100+d2*10+d1;
                check_and_print(num,a,b);
            }
        }
    }
    if(b>=10001){
        for(int d1=1;d1<=9;d1+=2){
            for(int d2=0;d2<=9;d2++){
                for(int d3=0;d3<=9;d3++){
                    int num=d1*10000+d2*1000+d3*100+d2*10+d1;
                    check_and_print(num,a,b);
                }
            }
        }
    }
    if(b>=1000001){
        for(int d1=1;d1<=9;d1+=2){
            for(int d2=0;d2<=9;d2++){
                for(int d3=0;d3<=9;d3++){
                    for(int d4=0;d4<=9;d4++){
                        int num=d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1;
                        check_and_print(num,a,b);
                    }
                }
            }
        }
    }
    return 0;
}
```

先得到回文数再判断质数;
偶数都不是质数;
偶位的回文数不是质数(被11整除).

### P1149

#### 最优解(我的代码)

```C++
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
```

有点理解暴力枚举的含义了,两种方式:寻找变量间关系(一一映射等)从而减少枚举变量的数量;寻找变量间关系(和一定等)从而减少枚举变量的范围.

### P3799

#### 最优解(我的代码,AI纠错后)

```C++
#include<cstdio>
#include<cstring>
#define MAXN 5010
#define MOD 1000000007
#define ll long long
using namespace std;

ll cnt[MAXN];
int res[MAXN];
int len=0;
int n;
ll ans=0;

ll c(int n){
    return n*(n-1)/2%MOD;
}

int main(){
    memset(cnt,0,sizeof(cnt));
    memset(res,0,sizeof(res));
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        cnt[tmp]++;
    }
    // for (int i=1;2*i<MAXN;i++){
    //     if (cnt[i]<2) continue;
    //     if (cnt[2*i]>=2){
    //         ans+=cnt[i]*(cnt[i]-1)*cnt[2*i]*(cnt[2*i]-1)/4;
    //         ans=ans%MOD;
    //     }
    // }
    for (int i=0;i<MAXN;i++){
        if (cnt[i]) res[len++]=i;
    }
    for (int i=len-1;i>=0;i--){
        if (cnt[res[i]]<2) continue;
        int l=0,r=i-1;
        while (l<=r){
            if (res[l]+res[r]==res[i]){
                if (l==r){
                    ans+=c(cnt[res[l]])*c(cnt[res[i]]);
                    ans=ans%MOD;
                    break;
                }
                else {
                    ans+=cnt[res[l]]*cnt[res[r]]*c(cnt[res[i]]);
                    ans=ans%MOD;
                    l++;
                    r--;
                }
            }
            else if (res[l]+res[r]>res[i]){
                r--;
            }
            else {
                l++;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
```

注意审题,不要想当然地默认核心逻辑

### P2392

#### 