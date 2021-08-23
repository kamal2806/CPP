#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>T;

// lowest one bit (i & -i)

ll sum(ll i){
    ll sum = 0;
    while(i>0){
        sum += T[i];
        i -= i & -i;
    }
    return sum;
}

void add(ll i,ll k){
    while(i < T.size()){
        T[i] += k;
        i += i & -i;
    }
}

vector<ll> fun(vector<ll> in){
    vector<ll> res(in.begin(),in.end());
    for(int i=1;i<res.size();i++){
        ll p = i + (i & -i); // index to parent
        if(p < res.size()){
            res[p] = res[p] + res[i];
        }
    }
    return res;
}


int main(){
    int n;cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    T = fun(a);
}