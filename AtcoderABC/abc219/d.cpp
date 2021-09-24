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

ll memo[310][310][310];
ll dfs(vector<pair<ll,ll>> &obj, ll i, ll a, ll b) {

    if (memo[i][a][b]) return memo[i][a][b];

    if (a == 0 && b == 0) {
        return 0;
    }

    if (i >= (ll)obj.size()) {
        return INFLL;
    }

    ll n1 = obj[i].first;
    ll n2 = obj[i].second;

    ll t1 = dfs(obj, i+1, max(a-n1, 0LL), max(b-n2, 0LL)) + 1;
    ll t2 = dfs(obj, i+1, a, b);

    return memo[i][a][b] = min(t1, t2);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;cin>>n;
    ll x,y;cin>>x>>y;
    vector<pair<ll,ll>> obj(n);
    rep(i,0,n) {
        ll a,b;cin>>a>>b;
        obj[i] = mp(a,b);
    }

    ll ans = dfs(obj, 0, x, y);
    cout << (ans == INFLL ? -1 : ans) << endl;
}