#include<cstdio>
#include<algorithm>
#define MAXN 1010
// #define ll long long
using namespace std;

int n;
int a[MAXN];

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if (n==1){
        printf("Jolly");
        return 0;
    }
    for (int i=1;i<n;i++){
        a[i-1]=abs(a[i]-a[i-1]);
    };
    sort(a,a+n-1);
    // for (int i=0;i<n-1;i++){
    //     if (a[i]!=i+1){
    //         printf("Not jolly");
    //         return 0;
    //     }
    // }
    // printf("Jolly");
    int *tail=unique(a,a+n-1);
    if (*tail==n-1 && a[0]==1 && (tail-a)==n-1){
        printf("Jolly");
    }
    else {
        printf("Not jolly");
    }
    return 0;
}