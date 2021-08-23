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

ll fun(string n){
    int sz = sz(n),val=0,flag=0;
    if(n[0] != n[sz-1]){
        if(n[sz-1]>n[0]){
            n[sz-1]=n[0];
        }
        else{
            n[sz-1] = n[0];
            if(sz>2){
                for(int i=sz-2;i>=1;i--){
                    if(n[i]>='1'){
                        n[i]--;
                        flag=1;
                        break;
                    }
                }
            }
            else{
                n[0]--;
                n[sz-1]=n[0];
                flag=1;
            }
            if(!flag)val=-1;
        }
    }
    ll ans = 0,sum=0;
    if(sz==1){
        return n[0]-'0';
    }
    if(sz>1)ans += 9;
    if(sz==2){
        return ans + n[0]-'0';
    }
    if(sz>2)ans += 9;
    for(int i=2;i<sz-1;i++){
        ans += pow(10,i-1) * 9;
    }
    ans += pow(10,sz-2) * (n[0]-'0'-1); 
    for(int i=1;i<sz-1;i++){
        sum = sum*10 + (n[i]-'0');
    }
    // cout<<ans<<" "<<sum<<" "<<val<<endl;
    return ans+sum+1+val;
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
    ll n,m,count=0,temp;cin>>n>>m;
    n--;
    string s = to_string(n),t = to_string(m);
    ll ans = fun(t) - fun(s);
    // cout<<fun(t)<<" "<<fun(s)<<endl;
    cout<<ans;
    return 0;
}
