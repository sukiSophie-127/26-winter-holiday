#include<cstdio>
#define MAXN 1010
using namespace std;

int n,cnt=0;
int a[MAXN];

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<=n-2;i++){
        for (int j=i+1;j<n;j++){
            if (a[i]>a[j]) cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}