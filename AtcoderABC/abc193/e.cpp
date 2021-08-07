//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,int>;
using PL = pair<ll,ll>;
using PPL = pair<pair<ll,ll>,ll>;
#define INF 1000000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
#define tp make_tuple
#define ALL(vec) vec.begin(), vec.end()

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll INFLL = numeric_limits<ll>::max();
    ll t;cin>>t;
    rep(_,0,t){
        ll x,y,p,q;cin>>x>>y>>p>>q;
        ll mod1 = (2*x+2*y)%(p+q);
        ll ans = INFLL;
        
        rep(i,x,x+y){
            if (mod1==0 && p<=i%(p+q) && i%(p+q) <p+q){
                ans = min(ans, (ll)i);
                continue;
            }
            rep(j,p,p+q){
                ll num = i%(p+q);
                ll num2 = j%(p+q);
                ll num3 = (num2-num+p+q)%(p+q);

                ll d = __gcd(__gcd((ll)num3,mod1),p+q);
                ll mod3 = mod1 / d;
                num3/=d;
                ll mod2 = (p+q)/d;
                if (__gcd(mod3,mod2)==1){
                    ll a1 = modinv(mod3, mod2);
                    ans = min(ans, (a1*num3)%mod2*(2*x+2*y)+i);
                }
            }
        }
        if (ans==INFLL){
            cout<<"infinity"<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
}