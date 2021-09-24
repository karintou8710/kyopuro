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

ll decode(string s) {

    ll res = 0;
    rep(i, 0, s.size()) {
        if (s[i] == 'm') {
            if (i-1 >= 0 && '2' <= s[i-1] && s[i-1] <= '9') {
                res += (s[i-1] - '0') * 1000;
            } else {
                res += 1000;
            }
        } else if (s[i] == 'c') {
            if (i-1 >= 0 && '2' <= s[i-1] && s[i-1] <= '9') {
                res += (s[i-1] - '0') * 100;
            } else {
                res += 100;
            }
        } else if (s[i] == 'x') {
            if (i-1 >= 0 && '2' <= s[i-1] && s[i-1] <= '9') {
                res += (s[i-1] - '0') * 10;
            } else {
                res += 10;
            }
        } else if (s[i] == 'i') {
            if (i-1 >= 0 && '2' <= s[i-1] && s[i-1] <= '9') {
                res += (s[i-1] - '0');
            } else {
                res += 1;
            }
        }
    }

    return res;
}

string encode(ll num) {
    string res = "";
    for (string x : {"i", "x", "c", "m"}) {
        ll t = num % 10;
        if (t >= 2) {
            res = to_string(t) + x + res;
        }  else if (t == 1) {
            res = x + res;
        }

        num /= 10;
    }

    return res;
}
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;cin>>n;

    rep(i,0,n) {
        string s1, s2;cin>>s1>>s2;

        ll n1 = decode(s1);
        ll n2 = decode(s2);
        string ans = encode(n1 + n2);

        cout << ans << endl;
    }
}