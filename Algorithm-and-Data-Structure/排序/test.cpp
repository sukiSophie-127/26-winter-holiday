#include<iostream>
using namespace std;

void quickSort(int a[],int l,int r){
    if (l==r){
        return;
    }
    int i=l,j=r,pivot=a[(l+r)/2];
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
    if (i<r) quickSort(a,i,r);
    if (j>l) quickSort(a,l,j);
}

int main(){
    int a[]={5,7,3,4,1,9,0,2,6,8};
    quickSort(a,0,9);
    for (int i=0;i<10;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
}