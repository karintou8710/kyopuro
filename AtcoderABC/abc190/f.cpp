//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1000000000
#define INFL 1000000000000000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
#define tp make_tuple
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef tuple<int,int,int> T;
typedef tuple<ll,ll,ll> TL;
ll mod = 1000000007;
ll mod2 = 998244353;

template <typename X>
struct SegTree {

    using FX = function<X(X, X)>; // X•X -> X となる関数の型
    int n;
    FX fx; // 演算
    const X ex; // 単位元
    vector<X> dat;

    SegTree(int n_, FX fx_, X ex_) : n(), fx(fx_), ex(ex_), dat(n_ * 4, ex_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    void set(int i, X x) { dat[i + n - 1] = x; }

    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

    void update(int i, X x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }

    X query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return ex;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<ll> a(n),b(n);
    rep(i,0,n){
        cin>>a[i];
        b[a[i]] = i+1;
    }

    auto fx = [](int x1, int x2) -> int { return x1+x2; };
    int ex = 0;
    SegTree<int> st(n, fx, ex);
    st.build();
    ll ans = 0;
    rep(i,0,n){
        st.update(b[n-i-1]-1,1);
        ans += st.query(0,b[n-i-1]-1);
    }
    cout<<ans<<endl;
    rep(i,0,n-1){
        ans = ans + n - 2*a[i] -1;
        cout<<ans<<endl;
    }
}