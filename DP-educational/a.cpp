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


/*
    DPは部分問題(状態)に切り分けるのとそれの遷移式から考えると良さそう
    部分問題を考える時に、それまでの経路によって部分問題の答えが変わらないとかが大事(?)
*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin>>n;
    vector<ll> h(n), memo(n, -1);
    rep(i,0,n) cin>>h[i];

    auto solve = [&](auto solve, int idx) -> ll {
        if (memo[idx] != -1) return memo[idx];
        if (idx == n-1) return memo[idx] = 0;
        
        if (idx < n-2) {
            ll s1 = solve(solve, idx+1) + abs(h[idx] - h[idx+1]);
            ll s2 = solve(solve, idx+2) + abs(h[idx] - h[idx+2]);
            return memo[idx] = min(s1, s2);
        } else {
            ll s1 = solve(solve, idx+1) + abs(h[idx] - h[idx+1]);
            return memo[idx] = s1;
        }
    };
    
    cout << solve(solve, 0) << endl;
}