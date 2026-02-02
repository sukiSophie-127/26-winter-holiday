#include<algorithm>
#include<cmath>
#include<iostream>
#include <iomanip>
#define MAXN 20
#define INF 1e9
using namespace std;

struct Point {
    double x,y;
};

double get_dist(Point a,Point b){
    double res;
    res=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return res;
}

Point p[MAXN];
int n;
int order[MAXN];
double ans=INF;
double dist[MAXN][MAXN];

int main(){
    cin>>n;
    p[0].x=0;
    p[0].y=0;
    for (int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            if (dist[j][i]) dist[i][j]=dist[j][i];
            else {
                dist[i][j]=get_dist(p[i],p[j]);
            }
        }
    }
    for (int i=1;i<=n;i++){
        order[i]=i;
    }
    do {
        double res=0;
        res+=dist[0][order[1]];
        for (int i=1;i<n;i++){
            res+=dist[order[i]][order[i+1]];
            if (res>=ans) break;
        }
        if (res<ans) ans=res;
    }while(next_permutation(order+1,order+n+1));
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}