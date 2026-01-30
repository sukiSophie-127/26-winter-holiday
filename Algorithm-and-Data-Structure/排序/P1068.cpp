#include<cstdio>
#include<algorithm>
#define MAXN 5010
using namespace std;

struct Stu {
    int k;
    int s;
};

bool cmp(Stu a,Stu b){
    if (a.s==b.s) return a.k<b.k;
    else return a.s>b.s;
}

Stu stu[MAXN];
int n,m;
int ans_s,ans;

int main(){
    scanf("%d %d",&n,&m);
    int line=m*3/2-1;
    for (int i=0;i<n;i++){
        scanf("%d %d",&stu[i].k,&stu[i].s);
    }
    sort(stu,stu+n,cmp);
    ans_s=stu[line].s;
    ans=line;
    while (stu[ans+1].s==stu[ans].s){
        ans++;
    }
    printf("%d %d\n",ans_s,ans+1);
    for (int i=0;i<=ans;i++){
        printf("%d %d\n",stu[i].k,stu[i].s);
    }
    return 0;
}