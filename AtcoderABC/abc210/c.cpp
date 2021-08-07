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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;cin>>n>>k;
    vector<ll> color(n), num(n+1);
    map<ll,ll> m;
    ll cnt = 1;
    rep(i,0,n) {
        ll c;cin>>c;
        if (m[c] == 0) {
            m[c] = cnt;
            cnt++;
        }
        color[i] = m[c];
    }
    ll ans = 0;
    ll tmp = 0;
    rep(i,0,k) {
        if (num[color[i]] == 0) {
            tmp++;
        }
        num[color[i]]++;
    }
    ans = tmp;
    rep(i,k,n) {
        if (num[color[i-k]] == 1) {
            tmp--;
        }
        num[color[i-k]]--;
        if (num[color[i]] == 0) {
            tmp++;
        }
        num[color[i]]++;
        ans = max(ans, tmp);
    }

    cout<<ans<<endl;
}