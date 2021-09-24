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

// i=0から
struct UnionFind {
    int _n, join_size;
    vector<int> par, siz;

    UnionFind(int n) : par(n), siz(n, 1), join_size(n) {
        _n = n;
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    int unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return -1;
        if (siz[rx] < siz[ry]) swap(rx, ry);
        // rx>=ry rxが親
        siz[rx] += siz[ry];
        par[ry] = rx;  //rxにryを結合
        join_size--;
        return rx;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;cin>>n>>m;
    UnionFind uni(n);

    vector<pair<ll, pair<int,int>>> G;

    ll ans = 0;

    rep(i,0,m) {
        ll a,b,c;cin>>a>>b>>c;
        a--;
        b--;
        if (c<=0) {
            uni.unite(a,b);
        } else {
            G.push_back(mp(c, mp(a,b)));
            ans += c;
        }
    }

    sort(ALL(G));

    for (auto p:G) {
        ll c = p.first;
        if (!uni.same(p.second.first, p.second.second)) {
            ans -= c;
            uni.unite(p.second.first, p.second.second);
        }
    }

    cout << ans << endl;
}