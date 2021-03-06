#include <bits/stdc++.h>
using namespace std;


// セグ木 結合測と単位元の存在 and X × X' -> X モノイド
//遅延セグ木 作用付きモノイド
// 0-index

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

    // 0-index
    void set(int i, X x) { dat[i + n - 1] = x; }

    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

    // 0-index
    void update(int i, X x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    // [a,b)
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

void RMQ(){
    int n;cin>>n;
    auto fx = [](int x1, int x2) -> int { return min(x1, x2); };
    int ex = numeric_limits<int>::max();
    SegTree<int> rmq(n, fx, ex);

}