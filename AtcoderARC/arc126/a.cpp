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
    ll t;cin>>t;
    rep(_,0,t) {
        ll n2,n3,n4;cin>>n2>>n3>>n4;
        ll ans = 0;
        n3 /= 2;
        ll tmp = 0;
        if (n3 < n4) {
            ans += n3;
            tmp = n4 - n3; // 4
            ll tmp2 = tmp % 2;
            tmp /= 2;
            if (n2 < tmp) {
                ans += n2;
            } else {
                ans += tmp;
                n2 -= tmp;
                if (tmp2 && n2 >= 3) {
                    ans += 1;
                    n2 -= 3;
                }
                ans += n2/5;
            }
        } else {
            ans += n4;
            tmp = n3 - n4; // 6
            if (n2/2 < tmp) {
                ans += n2/2;
            } else {
                ans += tmp;
                n2 -= tmp * 2;
                ans += n2 /5;
            }
            
            
        }
        cout << ans << endl;

    }
}