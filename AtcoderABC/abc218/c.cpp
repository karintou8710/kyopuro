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

ll solve(vector<vector<char>> &s, vector<ll> &cnt_th, vector<ll> &cnt_tw, ll n) {
    vector<ll> cnt_sh(n), cnt_sw(n) ;
    rep(i,0,n) {
        ll cnt = 0;
        rep(j,0,n) {
            if (s[i][j] == '#') cnt++;
        }
        cnt_sw[i] = cnt;
    }

    rep(i,0,n) {
        ll cnt = 0;
        rep(j,0,n) {
            if (s[j][i] == '#') cnt++;
        }
        cnt_sh[i] = cnt;
    }

    ll f = 0;

    rep(i,-n,n+1) {
        ll f2 = 1;
        rep(j, 0, n) {
            if (0<=j-i && j-i <n) {
                if (cnt_sh[j-i] != cnt_th[j]) f2 = 0;
            } else {
                if (0 != cnt_th[j]) f2 = 0;
            }
        }
        if (f2==1) f = 1;
    }

    if (f == 0) return 0;

    f = 0;
    
    rep(i,-n,n+1) {
        ll f2 = 1;
        rep(j, 0, n) {
            if (0<=j-i && j-i <n) {
                if (cnt_sw[j-i] != cnt_tw[j]) f2 = 0;
            } else {
                if (0 != cnt_tw[j]) f2 = 0;
            }
        }
        if (f2==1) f = 1;
    }

    return f;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;cin>>n;
    vector<vector<char>> s(n, vector<char>(n)), t(n, vector<char>(n)), s_rote(n, vector<char>(n));
    vector<ll> cnt_th(n), cnt_tw(n) ;

    rep(i,0,n) {
        rep(j,0,n) {
            char a;cin>>a;
            s[i][j] = a; 
        }
    }

    rep(i,0,n) {
        rep(j,0,n) {
            char a;cin>>a;
            t[i][j] = a; 
        }
    }
    ///

    // tate to yoko
    rep(i,0,n) {
        ll cnt = 0;
        rep(j,0,n) {
            if (t[i][j] == '#') cnt++;
        }
        cnt_tw[i] = cnt;
    }

    rep(i,0,n) {
        ll cnt = 0;
        rep(j,0,n) {
            if (t[j][i] == '#') cnt++;
        }
        cnt_th[i] = cnt;
    }

    if (solve(s, cnt_th, cnt_tw, n)) {
        cout << "Yes" << endl;
        return 0;
    }

    // 180
    rep(i,0,n) {
        rep(j,0,n) {
            s_rote[n-1-i][n-1-j] = s[i][j];
        }
    }

    if (solve(s_rote, cnt_th, cnt_tw, n)) {
        cout << "Yes" << endl;
        return 0;
    }

    // 90 (?)
    rep(i,0,n) {
        rep(j,0,n) {
            s_rote[n-1-j][i] = s[i][j];
        }
    }

    if (solve(s_rote, cnt_th, cnt_tw, n)) {
        cout << "Yes" << endl;
        return 0;
    }

    // 90 (?)
    rep(i,0,n) {
        rep(j,0,n) {
            s_rote[j][n-1-i] = s[i][j];
        }
    }

    if (solve(s_rote, cnt_th, cnt_tw, n)) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
}