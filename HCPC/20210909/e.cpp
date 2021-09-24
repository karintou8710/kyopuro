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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,t,l,b;cin>>n>>t>>l>>b;
    vector<ll> mapp(n+1); // 1 -> l, 2 -> b
    vector<vector<ld>> dp(t+1, vector<ld>(n+1));

    rep(i,0,l) {
        ll a;cin>>a;
        mapp[a] = 1;
    }

    rep(i,0,b) {
        ll a;cin>>a;
        mapp[a] = 2;
    }

    dp[0][0] = 1;

    rep(i,1,t+1) {
        rep(j, 1, n+1) {
            rep(k,1,7) {
                if (j-k >= 0) {
                    if (mapp[j-k] != 1) {
                        dp[i][j] += dp[i-1][j-k] / 6;
                    } else {
                        if (i-2 >= 0) {
                            dp[i][j] += dp[i-2][j-k] / 6;
                        }
                    }
                }
            }
        }

        // n-1
        rep(j,0,5) {
            dp[i][n-1-j] += dp[i-1][n-1] / 6;
        }

        // n-2
        rep(j,0,4) {
            dp[i][n-1-j] += dp[i-1][n-2] / 6;
        }

        // n-3
        rep(j,0,3) {
            dp[i][n-1-j] += dp[i-1][n-3] / 6;
        }

        // n-4
        rep(j,0,2) {
            dp[i][n-1-j] += dp[i-1][n-4] / 6;
        }

        // n-5
        rep(j,0,1) {
            dp[i][n-1-j] += dp[i-1][n-5] / 6;
        }

        rep(j,1,n) {
            if (mapp[j] == 2) {
                dp[i][0] += dp[i][j];
                dp[i][j] = 0;
            }
        }
    }

    ld ans = 0;
    rep(i,0,t+1) {
        ans += dp[i][n];
    }

    cout << ans << endl;
}