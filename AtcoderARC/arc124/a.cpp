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

    ll n,k;cin>>n>>k;

    vector<ll> m(n, k);

    rep(i,0,k) {
        string c1;cin>>c1;
        ll k1;cin>>k1;
        if (c1=="L") {
            rep(j,0,k1-1) {
                if (m[j] != 1) m[j]--;
            }
            m[k1-1] = 1;
        }
        if (c1=="R") {
            repp(j,n-1,k1) {
                if (m[j] != 1) m[j]--;
            }
            m[k1-1] = 1;
        }
    }

    ll ans = 1;
    rep(i,0,n) {
        ans = ans*m[i]%mod2;
    }
    cout<<ans<<endl;
}