//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,int>;
using PL = pair<ll,ll>;
using PPL = pair<pair<ll,ll>,ll>;
#define INF 1000000000
#define INFLL 1000000000000000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
#define tp make_tuple
#define ALL(vec) vec.begin(), vec.end()
template <class T> inline bool chmax(T& a,T b) {if(a<b){a=b;return true;}return false;}
template <class T> inline bool chmin(T& a,T b) {if(a>b){a=b;return true;}return false;}
ll mod = 1000000007;
ll mod2 = 998244353;

ll modpow(ll a, ll b) {
    ll r = 1;
    while (b) {
        r = r * ((b % 2) ? a : 1) % mod2;
        a = a * a % mod2;
        b >>= 1;
    }
    return r;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,m,k;cin>>n>>m>>k;
    vector<vector<ll>> G(n);
    rep(i,0,m) {
        ll a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ll dp[n+1][k+1][2] = {};
    dp[0][0][0] = 1;
    rep(i,0,k) {
        ll sum0 = 0;
        rep(j,0,n){
            sum0 = (sum0 + dp[i][j][0]) % mod2;
        }
        ll sum1 = 0;
        rep(j,0,n){
            sum1 = (sum1 + dp[i][j][1]) % mod2;
        }

        rep(j,0,n) {
            dp[i+1][j][0] = (dp[i+1][j][0] + sum0 + mod2) % mod2;
            dp[i+1][j][1] = (dp[i+1][j][1] + sum1 + mod2) % mod2;
            for (auto p : G[j]) {
                dp[i+1][j][0] = ( dp[i+1][j][0] - dp[i][p][0] + mod2) % mod2;
                dp[i+1][j][1] = ( dp[i+1][j][1] + dp[i][p][0] + mod2) % mod2;
            }
        }
    }

    ll ans = (modpow(n-1, k-1) - dp[k][0][1] + mod2) % mod2 ;
    cout << ans << endl;
}