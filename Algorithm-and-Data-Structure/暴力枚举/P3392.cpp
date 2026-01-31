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