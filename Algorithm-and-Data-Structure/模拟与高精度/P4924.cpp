#include<cstdio>
#define MAXN 510

using namespace std;

int a[MAXN][MAXN];
int n,m;

//z=1,逆时针
void f2(int n[][MAXN],int x,int y,int r){
    for (int i=x-r;i<x;i++){
        int tmp;
        for (int j=y-r;j<=y+r;j++){
            tmp=n[i][j];
            n[i][j]=n[2*x-i][j];
            n[2*x-i][j]=tmp;
        }
    }

    for (int i=-r;i<=r;i++){
        for (int j=-r;j<=-1-i;j++){
            int tmp;
            tmp=n[x+i][y+j];
            n[x+i][y+j]=n[x-j][y-i];
            n[x-j][y-i]=tmp;
        }
    }
}

//z=0,顺时针
void f3(int n[][MAXN],int x,int y,int r){
    for (int i=y-r;i<y;i++){
        int tmp;
        for (int j=x-r;j<=x+r;j++){
            tmp=n[j][i];
            n[j][i]=n[j][2*y-i];
            n[j][2*y-i]=tmp;
        }
    }

    for (int i=-r;i<=r;i++){
        for (int j=-r;j<=-1-i;j++){
            int tmp;
            tmp=n[x+i][y+j];
            n[x+i][y+j]=n[x-j][y-i];
            n[x-j][y-i]=tmp;
        }
    }
}

void f1(int n[][MAXN],int x,int y,int r,int z){
    if (z==1){
        f2(n,x,y,r);
    }
    else {
        f3(n,x,y,r);
    }
}

int main(){
    int x,y,r,z,cnt=1;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            a[i][j]=cnt++;
        }
    }
    for (int i=1;i<=m;i++){
        scanf("%d%d%d%d",&x,&y,&r,&z);
        f1(a,x,y,r,z);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
