//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,int>;
using PL = pair<ll,ll>;
using PPL = pair<ll,pair<ll,ll>>;
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

    int n;cin>>n;
    vector<PPL> s;
    ll a = 0, t = 0;
    rep(i,0,n){
        ll a1,a2;cin>>a1>>a2;
        s.push_back(mp(a1*2+a2, mp(a1,a2)));
        a += a1;
    }
    sort(s.begin(), s.end(), greater<PPL>());
    ll ans = 0;
    rep(i,0,n){
        if (a<t) break;
        ans++;
        a -= s[i].second.first;
        t += s[i].second.second + s[i].second.first;
    }
    cout<<ans<<endl;
}