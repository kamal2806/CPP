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
// const ll mod = 998244353;
const ll mod = 1e9+7;
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
    ll n;cin>>n;
    
    // do{
    //     for(auto x:a)cout<<x<<" ";
    //     cout<<endl;
    //     for(int i=0;i<n;i++){
    //         cout<<a[i]<<":"<<" ";
    //         for(int j=i-1;j>=0;j--){
    //             if(a[j]>a[i]){cout<<a[j]<<" ";break;}
    //         }
    //         for(int j=i+1;j<n;j++){
    //             if(a[j]>a[i]){cout<<a[j]<<" ";break;}
    //         }
    //         cout<<",";
    //     }
    //     cout<<endl;
    // }while(next_permutation(a.begin(),a.end()));
    ll ans1 = 1;
    for(ll i=1;i<=n;i++)ans1 = (ans1*i)%mod;
    ll ans2 = powmod(2,n-1);
    ll ans = (ans1 - ans2)%mod;
    while(ans<0)ans+=mod;
    
    ans%=mod;
    cout<<ans;
    return 0;
}