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
ll pow_2[64];

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

ll solve(){
    ll n;cin>>n;
    // 0 1 2 3 4 5 6 7 8 9 10  11 12 13 14 15
    // 1 2 2 4 2 4 4 8 2 4  4  8  4  8  8  16
    ll temp = n,total=0;
    while(n){
        if(n%2)total++;
        n /= 2;
    } 
    ll res = temp+1 - pow_2[total];
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin); 
    int tc;cin>>tc;
    pow_2[0]=1;
    for(int i=1;i<64;i++){
        pow_2[i] = pow_2[i-1]*2;
    }
    for(int i=0;i<tc;i++){
        ll ans = solve();
        cout<<ans<<endl;
    }
}