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

    ll n;cin>>n;
    ll a,b;cin>>a>>b;
    rep(i,1,n) {
        ll t1,t2;cin>>t1>>t2;

        ll t3 = __gcd(a, t1);
        ll t4 = __gcd(b, t2);
        ll a1 = t3*t4/__gcd(t3, t4);

        ll t5 = __gcd(a, t2);
        ll t6 = __gcd(b, t1);
        ll a2 = t5*t6/__gcd(t5, t6);

        if (a1<=a2) {
            a = t5;
            b = t6;
        } else {
            a = t3;
            b = t4;
        }
    }

    cout << (a*b)/__gcd(a,b) << endl;
}