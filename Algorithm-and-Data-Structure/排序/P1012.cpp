#include<string>
#include<iostream>
#include<algorithm>
#define MAXN 30
using namespace std;

bool cmp(string a,string b){
    return a+b>b+a;
}

int n;
string num[MAXN];

int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n,cmp);
    for (int i=0;i<n;i++){
        cout<<num[i];
    }
    return 0;
}