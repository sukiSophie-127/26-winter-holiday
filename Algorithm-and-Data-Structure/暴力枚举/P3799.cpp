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