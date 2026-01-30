#include<cstdio>
#define MAXN 5000010
using namespace std;

int n,k;
int a[MAXN];
int ans=0;

int findkth(int a[],int l,int r,int k){
    if (l==r){
        return a[l];
    }
    int i=l,j=r,pivot=a[(r-l)/2+l];
    do {
        while (a[i]<pivot) i++;
        while (a[j]>pivot) j--;
        if (i<=j){
            int tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
            i++;
            j--;
        }
    }while (i<=j);
    if (k<=j){
        return findkth(a,l,j,k);
    }
    else if (k>=i){
        return findkth(a,i,r,k);
    }
    else {
        return findkth(a,j+1,i-1,k);
    }
}

int main(){
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    ans=findkth(a,0,n-1,k);
    printf("%d",ans);
    return 0;
}