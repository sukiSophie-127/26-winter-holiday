#include<algorithm>
#include<cstdio>
#define MAXN 20010
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int n,k,h=0,cnt=0;
int cow[MAXN];

int main(){
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d",&cow[i]);
    }
    sort(cow,cow+n,cmp);
    while (h<k){
        h+=cow[cnt++];
    }
    printf("%d",cnt);
    return 0;
}