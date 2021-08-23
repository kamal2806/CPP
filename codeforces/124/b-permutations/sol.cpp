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
    ll n,k;
    cin>>n>>k;
    ll arr[n][k];
    char ch;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>ch;
            arr[i][j]=ch-'0';
        }
    }
    int in[k];
    for(int i=0;i<k;i++){
        in[i]=i;
    }
    ll ans=INF;
    do{
        ll int mi=INF,ma=-INF,x; 
        for(int i=0;i<n;i++){
            x = 0;
            for(int j=0;j<k;j++){
                x = x*10 + arr[i][in[j]];
            }
            ma = max(ma,x);
            mi = min(mi,x);
        }
        ans = min(ans,ma-mi);
    }while(next_permutation(in,in+k));
    cout<<ans<<endl;
    return 0;
}