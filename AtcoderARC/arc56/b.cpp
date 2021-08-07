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
ll mod = 1000000007;
ll mod2 = 998244353;

// i=0から
struct UnionFind {
    int _n, joinSize;
    vector<int> par, siz;

    UnionFind(int n) : par(n), siz(n, 1) {
        _n = n;
        joinSize = n;
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
        joinSize--;
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
    ll n,m,s;cin>>n>>m>>s;
    s--;
    vector<vector<ll>> G(n);

    rep(i,0,m){
        ll a,b;cin>>a>>b;
        a--;b--;
        if (a>b) swap(a,b);
        G[a].push_back(b);
    }

    UnionFind uf(n);

    vector<ll> ans(n);
    repp(i,n-1,0){
        
        for (auto v : G[i]){
            uf.unite(i,v);
        }
        if (uf.same(s,i)){
            ans[i] = 1;
        }
    }
    rep(i,0,n){
        if (ans[i]) cout<<i+1<<endl;
    }
}