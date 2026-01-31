#include<cstdio>
#include<cmath>
using namespace std;

int is_prime(int n){
    if (n%2==0) return 0;
    int bound=sqrt(n)+1;
    for (int i=3;i<=bound;i++){
        if (n%i==0) return 0;
    }
    return 1;
}

