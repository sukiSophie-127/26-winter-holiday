#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
#define MAXN 110
using namespace std;

struct Stu {
    string name;
    int y,m,d,id;
};

bool cmp(Stu a,Stu b){
    if (a.y==b.y){
        if (a.m==b.m){
            if (a.d==b.d){
                return a.id>b.id;
            }
            else {
                return a.d<b.d;
            }
        }
        else {
            return a.m<b.m;
        }
    }
    else {
        return a.y<b.y;
    }
}

int n;
Stu stu[MAXN];

int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>stu[i].name>>stu[i].y>>stu[i].m>>stu[i].d;
        stu[i].id=i;
    }
    sort(stu,stu+n,cmp);
    for (int i=0;i<n;i++){
        cout<<stu[i].name<<endl;
    }
    return 0;
}