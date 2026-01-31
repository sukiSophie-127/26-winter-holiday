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