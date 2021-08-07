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

    vector<PL> a(n);
    rep(i,0,n){
        cin>>a[i].first>>a[i].second;
    }
    vector<ll> box(m);
    rep(i,0,m) cin>>box[i];

    rep(i,0,q){
        ll l,r;cin>>l>>r;
        l--;r--;
        vector<ll> use;
        rep(j,0,l){
            use.push_back(box[j]);
        }
        rep(j,r+1,m){
            use.push_back(box[j]);
        }

        sort(ALL(use));

        ll ans = 0;
        vector<ll> used(n);
        rep(j,0,use.size()){
            ll num = 0, index=-1;
            rep(k,0,n){
                ll w = a[k].first, v=a[k].second;
                if (use[j]>=w && used[k]==0 && num < v){
                    num = v;
                    index = k;
                }
            }
            if (index!=-1){
                ans += num;
                used[index] = 1;
            }
            
        }
        cout<<ans<<endl;
    }
}