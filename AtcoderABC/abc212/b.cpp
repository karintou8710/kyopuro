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

    string x;cin>>x;
    int a[4] = {};
    a[0] = x[0] - '0';
    a[1] = x[1] - '0';
    a[2] = x[2] - '0';
    a[3] = x[3] - '0';
    if (x[0] == x[1] && x[1]==x[2] && x[2]==x[3]) {
        cout << "Weak" << endl;
        return 0;
    }

    if ( (a[0]+1)%10 == a[1] && (a[1]+1)%10 == a[2] && (a[2] + 1)%10 == a[3] ) {
        cout << "Weak" << endl;
        return 0;
    }

    cout << "Strong" << endl;
    return 0;
}