#include<cstdio>
#define MAXN 210
using namespace std;
//0 表示 剪刀，1 表示 石头，2 表示 布，3 表示 蜥蜴人，4 表示 斯波克
//每一次赢的人得 1 分，输的得 0 分；平局两人都得 0 分
int v[5][5]={0,0,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,1,1,0,0,0};

int a[MAXN],b[MAXN];
int ascore=0,bscore=0;

int main(){
    int n,an,bn;
    scanf("%d%d%d",&n,&an,&bn);
    for (int i=0;i<an;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<bn;i++){
        scanf("%d",&b[i]);
    }

    for (int i=0;i<n;i++){
        ascore+=v[a[i%an]][b[i%bn]];
        bscore+=v[b[i%bn]][a[i%an]];
    }

    printf("%d %d",ascore,bscore);
    return 0;
}
