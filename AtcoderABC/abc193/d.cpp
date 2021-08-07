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
    ll k;cin>>k;
    string s;cin>>s;
    string t;cin>>t;
    map<ll,ll> a1,a2,a3;
    rep(i,0,4){
        a1[s[i]-'0']++;
        a3[s[i]-'0']--;
    }
    rep(i,0,4){
        a2[t[i]-'0']++;
        a3[t[i]-'0']--;
    }
    ll num_s = 0, num_t = 0;
    rep(i,0,9){
        num_s += (i+1) * pow(10,a1[i+1]);
    }
    rep(i,0,9){
        num_t += (i+1) * pow(10,a2[i+1]);
    }
    rep(i,0,9){
        a3[i+1] += k;
    }

    ld ans = 0;
    rep(i,1,10){
        rep(j,1,10){
            if (a3[i]==0 || a3[j]==0) continue;
            ll ns = num_s - i * pow(10,a1[i]) + i * pow(10,a1[i]+1);
            ll nt = num_t - j * pow(10,a2[j]) + j * pow(10,a2[j]+1);
            if (ns>nt){
                if (i==j){
                    ans += ld(a3[i]) * ld(a3[i]-1) / ld(9*k-8) / ld(9*k-9);
                }else{
                    ans += ld(a3[i])/ld(9*k-8) * ld(a3[j]/ld(9*k-9));
                }
            }
        }
    }
    cout<<std::fixed << std::setprecision(15)<<ans<<endl;
}