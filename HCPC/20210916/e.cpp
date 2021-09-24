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

    ll n,m,t,p;cin>>n>>m>>t>>p;

    vector<vector<ll>> G(n, vector<ll>(m, 1));
    
    ll w = n;
    ll h = m;
    rep(i,0,t) {
        ll d,c;cin>>d>>c;
        if (d == 1) {
            if (w/2 >= c) c = w-c;
            vector<vector<ll>> a(c, vector<ll>(m));
            rep(j,0,c) {
                rep(k,0,m) {
                    
                }
            }
        } else {

        }
    }


    ll ans = 0;
    rep(i,0,p) {
        ll x,y;cin>>x>>y;
        ans += G[x][y];
    }
    cout << ans << endl;
}