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

    ll l,q;cin>>l>>q;

    set<ll> sep;
    sep.insert(0);
    sep.insert(l);
    rep(i,0,q) {
        ll c, x;cin>>c>>x;
        if (c==1) {
            sep.insert(x);
        } else {
            auto i = sep.lower_bound(x);
            ll n2 = *i;
            i--;
            ll n1 = *i;
            cout << n2 - n1 << endl;
        }
    }
}