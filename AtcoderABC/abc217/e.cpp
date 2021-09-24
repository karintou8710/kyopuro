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

    ll q;cin>>q;

    multiset<ll> aset;
    deque<ll> adeq;

    rep(i,0,q) {
        ll c;cin>>c;
        if (c == 1) {
            ll x;cin>>x;
            adeq.push_back(x);
        } else if (c == 2) {
            if (aset.size() == 0) {
                ll n = adeq.front();
                adeq.pop_front();
                cout << n << endl;
            } else {
                auto n = aset.begin();
                aset.erase(n, next(n));
                cout << *n << endl;
            }
        } else if (c == 3) {
            int size = adeq.size();
            rep(i, 0, size) {
                ll n = adeq.front();
                adeq.pop_front();
                aset.insert(n);
            }
        }
    }
}