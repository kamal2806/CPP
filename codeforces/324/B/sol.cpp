#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define trav(a,x) for (auto& a: x)

#define ll long long
#define pb push_back
#define what_is(x) cerr << #x << " is " << x << endl;
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define fi first
#define se second

const int MAX_N = 2e5 + 7;
// const ll mod = 998244353;
const ll mod = 1e9+7;
const ll INF = 1e9;
ll fact[MAX_N];

ll powmod(ll a,ll b){
    a %= mod;
    if(a==0)return 0;
    ll res = 1;
    while(b){
        if(b%2){
            res = res*a;
            res %= mod;
        }
        a = a*a;
        a %= mod;
        b /= 2;
    }
    return res;
}

ll inv(ll a){
    return powmod(a,mod-2);
}

ll nCr(ll n, ll k){
    if (k > n) {
        return 0;
    }
    return ((fact[n]*inv(fact[k])%mod)*inv(fact[n-k]))%mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin); 
    ll n;cin>>n;
    fact[0]=1;

    for(int i=1;i<MAX_N;i++)fact[i] = (fact[i-1]*i)%mod;
    // 20*3^3 + 20*3^3 - 20*20;
    // a U b = a + b - a int b
    // a U b = 2*one - 2C2*two
    // a U b U c = a + b + c - a int b .. + a int b int c  
    // a U b U c = 3C1*one - 3C2*two + 3C3three
    ll val,ans=0;
    for(int i=1;i<=n;i++){
        val = powmod(3,3*(n-i));
        val %= mod;
        val *= powmod(20,i);    
        val %= mod;
        val *= pow(-1,i+1);
        // cout<<val<<endl;
        ans = (ans + nCr(n,i)*val)%mod;
        while(ans<0)ans+=mod;
        ans%=mod;
        // cout<<val<<" "<<nCr(n,i)<<endl;
    }
    cout<<ans<<endl;
}