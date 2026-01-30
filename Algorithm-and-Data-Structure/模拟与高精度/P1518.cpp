#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef struct{
    int x;
    int y;
}Position;

char map[12][12];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int dF=0,dC=0;
int ans=0;
long long cnt=0;


int main(){
    Position *F=(Position*)malloc(sizeof(Position));
    Position *C=(Position*)malloc(sizeof(Position));
    for (int i=0;i<12;i++){
        for (int j=0;j<12;j++){
            map[i][j]='*';
        }
    }
    for (int i=1;i<=10;i++){
        for (int j=1;j<=10;j++){
            char tmp;
            cin>>tmp;
            map[i][j]=tmp;
            if (tmp=='F'){
                F->x=i;
                F->y=j;
            }
            if (tmp=='C'){
                C->x=i;
                C->y=j;
            }
        }
    }

    while(F->x!=C->x || F->y!=C->y){
        ans++;
        cnt++;
        dF=dF%4;
        dC=dC%4;
        if (map[F->x+dx[dF]][F->y+dy[dF]]=='*'){
            dF++;
        }
        else {
            F->x+=dx[dF];
            F->y+=dy[dF];
        }
        if (map[C->x+dx[dC]][C->y+dy[dC]]=='*'){
            dC++;
        }
        else {
            C->x+=dx[dC];
            C->y+=dy[dC];
        }
        if (cnt>1e8){
            break;
        }
    };
    if (F->x==C->x && F->y==C->y) cout<<ans<<endl;
    else cout<<0<<endl;
    return 0;
}
