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

vector<ll> a;

int main() {
    ll n;cin>>n;
    a.resize(n);
    auto f = [&](auto self, int i) {
        if (i == 0 || i == 1) return 1;
        return self(self, i-1) + self(self, i-2);
    };
    cout << f(f, n) << endl;
}