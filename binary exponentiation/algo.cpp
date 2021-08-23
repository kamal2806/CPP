#include <iostream>
using namespace std;
#define ll long long
ll mod = 1e9+7;

// recursive approach 

ll binpow1(ll a,ll b){
    if(b==0)return 1;
    ll res = binpow1(a,b/2);
    if(b%2) return res*res*a;
    else return res*res;
}

// non-recursive approach 

ll binpow2(ll a,ll b){
    a %= mod;
    ll res = 1;
    while(b){
        if(b%2)res = res*a % mod;;
        a=a*a % mod;
        b/=2;
    }
    return res;
}

int main(){
    int a,b;
    cin>>a>>b;
    printf("Recursive Method: %lld\n",binpow1(a,b));
    printf("Non-recursive Method: %lld",binpow2(a,b));
}