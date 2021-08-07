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
    ll n,m;cin>>n>>m;
    ll ans = 0;
    vector<ll> a(m),b(m),c(m);
    rep(i,0,m){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;b[i]--;c[i]--;
    }
    rep(i,0,1<<n){
        vector<ll> num(n);
        ll cnt = 0;
        rep(j,0,n){
            if (i & (1<<j)){
                num[j] = 1;
            }
        }

        ll f = 1;
        rep(k,0,m){
            if (num[a[k]] && num[b[k]] && num[c[k]]){
                f = 0;
                break;
            }
        }

        rep(j,0,n){
            if (f==0) break;
            if (num[j]==0){
                num[j] = 1;
                
                rep(k,0,m){
                    if (num[a[k]] && num[b[k]] && num[c[k]]){
                        cnt++;
                        break;
                    }
                }
                
                num[j] = 0;
            }
        }
        
        ans = max(ans, cnt);
        
    }
    cout<<ans<<endl;
}