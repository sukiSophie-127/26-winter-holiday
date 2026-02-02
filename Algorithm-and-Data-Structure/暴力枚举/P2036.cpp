#include<cstdio>
#include<algorithm>
#define INF 1e9
#define MAXN 10
using namespace std;

int n;
int s[MAXN],b[MAXN];
int total_s,total_b;
int ans=INF;

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d%d",&s[i],&b[i]);
    }
    for (int i=1;i<(1<<n);i++){
        total_s=1;
        total_b=0;
        for (int j=0;j<n;j++){
            if ((i>>j)&1){
                total_s*=s[j];
                total_b+=b[j];
            }
        }
        ans=min(ans,abs(total_s-total_b));
    }
    printf("%d",ans);
    return 0;
}