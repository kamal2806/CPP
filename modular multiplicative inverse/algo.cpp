#include<iostream>
using namespace std;
#define ll long long


// (1/k!)%p != (1/k!%p)
// (1/k!)%p = inv(k!)%p
// inv(a)%p = (a ^ p-2) % p

ll p = 17;  // prime given in question

ll inv(ll a){
    ll res = 1,b=p-2;
    while(b){
        if(b%2){
            res = res*a;
            res %= p;
        }
        a = a*a;
        a %= p;
        b/=2;
    }
    return res;
}

int main(){
    int a;cin>>a;
    printf("%d",inv(a));
}