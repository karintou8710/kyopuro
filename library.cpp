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
}

ll modpow(ll a, ll b) {
    ll r = 1;
    while (b) {
        r = r * ((b % 2) ? a : 1) % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

ll comb(ll N_, ll C_) {
    const int NUM_ = 400001;
    static ll fact[NUM_ + 1], factr[NUM_ + 1], inv[NUM_ + 1];
    if (fact[0] == 0) {
        inv[1] = fact[0] = factr[0] = 1;
        for (int i = 2; i <= NUM_; ++i) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
        for (int i = 1; i <= NUM_; ++i) fact[i] = fact[i - 1] * i % mod, factr[i] = factr[i - 1] * inv[i] % mod;
    }
    if (C_ < 0 || C_ > N_) return 0;
    return factr[C_] * fact[N_] % mod * factr[N_ - C_] % mod;
}

