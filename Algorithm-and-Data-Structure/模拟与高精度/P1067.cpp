#include<cstdio>
#include<iostream>
#define MAXN 110
using namespace std;

int main(){
    int n,tmp;
    cin>>n;
    cin>>tmp;
    while(!tmp && n>=1){
        cin>>tmp;
        n--;
    };
    if (n>=2){
        if (tmp==1) cout<<"x^"<<n;
        else if (tmp==-1) cout<<"-x^"<<n;
        else cout<<tmp<<"x^"<<n;
        for (int i=n-1;i>1;i--){
            cin>>tmp;
            if (tmp){
                if (tmp>0){
                    if (tmp==1) cout<<"+x^"<<i;
                    else cout<<"+"<<tmp<<"x^"<<i;
                }
                else {
                    if (tmp==-1) cout<<"-x^"<<i;
                    else cout<<tmp<<"x^"<<i;
                }
            }
        }
        cin>>tmp;
        if (tmp>0){
            if (tmp==1) cout<<"+x";
            else cout<<"+"<<tmp<<"x";
        }
        else if (tmp<0){
            if (tmp==-1) cout<<"-x";
            else cout<<tmp<<"x";
        }
        cin>>tmp;
        if (tmp>0) cout<<"+"<<tmp;
        else if (tmp<0) cout<<tmp;
    }
    if (n==1){
        if (tmp>0){
            if (tmp==1) cout<<"x";
            else cout<<tmp<<"x";
        }
        else if (tmp<0){
            if (tmp==-1) cout<<"-x";
            else cout<<tmp<<"x";
        }
        cin>>tmp;
        if (tmp>0) cout<<"+"<<tmp;
        else if (tmp<0) cout<<tmp;
    }
    if (n==0){
        if (tmp) cout<<tmp;

    }
    cout<<endl;
    return 0;
}