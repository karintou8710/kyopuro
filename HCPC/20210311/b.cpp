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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;cin>>n;
    vector<ll> a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    sort(ALL(a));

    ll ans = 1;
    rep(i,0,n){
        if (a[i]==0){
            ans = 0;
            break;
        }
        if (ans > INFLL / a[i]){
            ans = -1;
            break;
        }
        ans *= a[i];
    }
    cout<<ans<<endl;
}