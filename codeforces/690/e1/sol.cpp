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
    ll tc;cin>>tc;
    fact[0]=1;
    for(ll int i=1;i<MAX_N;i++)fact[i]=(fact[i-1]*i) % mod;
    while(tc--){
        /* tough version
        ll n,m,k,total,ans=0;cin>>n>>m>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        // for(int i=1;i<=10;i++)cout<<i<<" "<<cnt[i]<<endl;
        for(int i=0;i<n;i++){
            ll left = i+1;
            ll right = upper_bound(a.begin(),a.end(),a[i]+k)-a.begin();
            ans = (ans+nCr(right-left,m-1))%mod;
        }
        cout<<ans<<endl;        
        */
        ll n,x;cin>>n;
        vector<ll int>cnt(n+7,0);
        for(int i=0;i<n;i++){
            cin>>x;
            cnt[x]++;
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ans += cnt[i]*cnt[i+1]*cnt[i+2];
            ans += cnt[i]*((cnt[i+1]*(cnt[i+1]-1))/2);
            ans += cnt[i]*((cnt[i+2]*(cnt[i+2]-1))/2);
            ans += cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
            ans += (cnt[i]*(cnt[i]-1)/2 )* cnt[i+1];
            ans += (cnt[i]*(cnt[i]-1)/2 )* cnt[i+2];
        }
        cout<<ans<<endl;
    }
    return 0;
}