#include<cstdio>
#include<algorithm>
#include<cmath>
#define MAXN 50010
using namespace std;

struct Point {
    int x,y,z;
};

bool cmp(Point a,Point b){
    return a.z<b.z;
}

int n;
Point p[MAXN];
double ans=0;

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);
    }
    sort(p,p+n,cmp);
    for (int i=1;i<n;i++){
        ans+=sqrt(pow(p[i].x-p[i-1].x,2)+pow(p[i].y-p[i-1].y,2)+pow(p[i].z-p[i-1].z,2));
    }
    printf("%.3f",ans);
    return 0;
}
