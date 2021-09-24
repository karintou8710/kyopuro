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

    ll n,m;cin>>n>>m;
    vector<vector<ll>> a(m);
    vector<ll> idx(m);
    vector<ll> isPresent(n, -1);
    rep(i,0,m) {
        ll k;cin>>k;
        rep(j,0,k) {
            ll b;cin>>b;
            b--;
            a[i].push_back(b);
        }
    }

    queue<pair<ll, ll>> q; // 値, index
    rep(i,0,m) {
        q.push( mp(a[i][idx[i]], i));
        idx[i]++;
    }

    while(!q.empty()) {
        auto pf = q.front();
        ll p = pf.first;
        ll pi = pf.second;
        q.pop();
        if (isPresent[p] != -1) {
            if (idx[pi] < (ll)a[pi].size()) {
                q.push( mp(a[pi][idx[pi]], pi) );
                idx[pi]++;
            }
            ll anoPi = isPresent[p];
            if (idx[anoPi] < (ll)a[anoPi].size()) {
                q.push( mp(a[anoPi][idx[anoPi]], anoPi) );
                idx[anoPi]++;
            }
            
        } else {
            isPresent[p] = pi; 
        }
    }

    ll f = 1;
    rep(i,0,m) {
        if ((ll)a[i].size() != idx[i]) {
            f = 0;
        }
    }

    cout << (f ? "Yes" : "No") << endl;
}