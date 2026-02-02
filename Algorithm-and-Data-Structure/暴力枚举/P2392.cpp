#include<cstdio>
#include<cstring>
#define MAXN 70
#define max(a,b) ((a>b)?(a):(b))
using namespace std;

int a[4],val[MAXN],dp[2500],ans=0;

int main(){
    for (int i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<4;i++){
        int sum=0;
        for (int j=0;j<a[i];j++){
            scanf("%d",&val[j]);
            sum+=val[j];
        }
        int target=sum/2;
        memset(dp,0,sizeof(dp));
        for (int j=0;j<a[i];j++){
            for (int k=target;k>=val[j];k--){
                dp[k]=max(dp[k],dp[k-val[j]]+val[j]);
            }
        }
        ans+=sum-dp[target];
    }
    printf("%d",ans);
    return 0;
}