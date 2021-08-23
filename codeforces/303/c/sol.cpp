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
ll iv[MAX_N];
ll comb[1003][1003];

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

ll nCr(ll n, ll k){
    if (k > n) {
        return 0;
    }
    return ((fact[n]*iv[k]%mod)*iv[n-k])%mod;
}

struct tree{
    ll x,h;
};

bool comp(const tree& t1,const tree& t2){
    return t1.x < t2.x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin); 
    //
    fact[0]=1;
    for(int i=1;i<MAX_N;i++)fact[i] = (fact[i-1]*i)%mod;
    iv[MAX_N-1]=powmod(fact[MAX_N-1],mod-2);
    for(int i=MAX_N-2;i>=0;i--)iv[i]=(iv[i+1]*(i+1))%mod;
    //
    ll n;cin>>n;
    tree a[n];
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].h;
    }
    sort(a,a+n,comp);
    ll ans  = 1;
    for(int i=1;i<n;i++){
        if(i!=n-1){
            if((a[i].x - a[i].h) > a[i-1].x ){
                // cout<<"1 "<<i<<endl;
                ans++;
            }
            else if(a[i].x + a[i].h < a[i+1].x){
                ans++;
                a[i].x += a[i].h;
                // cout<<"2 "<<i<<endl;
            }
        }
        else{
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
