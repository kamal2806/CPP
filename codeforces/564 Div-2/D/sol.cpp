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

const int MAX_N = 2e6 + 7;
const ll mod = 998244353;
const ll INF = 1e9;
ll fact[MAX_N];
vector<int>edges[MAX_N];

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin); 
    int n,u,v;cin>>n;
    int dp[n]={0};
    fact[0]=1;
    for(int i=1;i<n;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        u--;v--;
        dp[u]++;dp[v]++;
    }
    ll ans = n;
    for(int i=0;i<n;i++){
        ans *= fact[dp[i]];
        ans %= mod;
    }
    cout<<ans<<endl;
}