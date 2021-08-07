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
    ll n,m,q;cin>>n>>m>>q;
    vector<ll> cnt(m);
    vector<vector<ll>> sol(n,vector<ll>(m));
    rep(_,0,q){
        ll t;cin>>t;
        if (t==1){
            ll a1;cin>>a1;
            a1--;
            ll num = 0;
            rep(i,0,m){
                if (sol[a1][i]==1) num += n-cnt[i];
            }
            cout<<num<<endl;
        }else{
            ll a1,a2;cin>>a1>>a2;
            a1--;a2--;
            cnt[a2]++;
            sol[a1][a2] = 1;
        }
    }
}