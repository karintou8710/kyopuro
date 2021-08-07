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

   ll n,m;cin>>n>>m;
   vector<ll> a(n), b(m);
   rep(i,0,n) {
       cin >> a[i];
   }
   rep(i,0,m) {
       cin>>b[i];
   }

   sort(ALL(a));
   sort(ALL(b));

   ll ans = INFLL;

   rep(i,0,n) {
       int idx = lower_bound(ALL(b), a[i]) - b.begin();
       if (idx - 1 >= 0) {
           ans = min(ans, abs(a[i]-b[idx-1]));
       }

       if (idx >= 0 && idx < m) {
           ans = min(ans, abs(a[i]-b[idx]));
       }

        if (idx + 1 < m) {    
           ans = min(ans, abs(a[i]-b[idx+1]));
       }
   }

   cout << ans << endl;
}