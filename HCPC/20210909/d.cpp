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

    while (1) {
        ll n,m;cin>>n>>m;
        if (n==0 && m==0) {
            break;
        }
    vector<pair<string, pair<ll,ll>>> a(n);
    rep(i,0,n) {
        string a1;cin>>a1;
        ll a2,a3;cin>>a2>>a3;
        a[i] =mp(a1, mp(a3-a2+1, a3));
    }
    rep(i,0,m) {
        ll q;cin>>q;
        string ans_str = "";
        ll ans_num = 0;
        rep(j,0,n) {
            if (a[j].second.first <= q && q <= a[j].second.second) {
                ans_str = a[j].first;
                ans_num = q - a[j].second.first + 1;
                break;
            }
        }

        if (ans_num == 0) {
            cout << "Unknown" << endl;
        } else {
            cout << ans_str << " " << ans_num << endl;
        }
        
    }
    }
}