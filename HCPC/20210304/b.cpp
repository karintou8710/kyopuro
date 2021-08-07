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

    ll n,a;cin>>n>>a;
    string s;cin>>s;
    s = "F" + s + "F";
    ll l = a, r=a;
    repp(i,a-1,0){
        if (s[i]=='F'){
            l=0;
            break;
        }
        if (s[i]=='#'){
            l = i;
            break;
        }

    }
    rep(i,a+1,n+2){
        if (s[i]=='F'){
            r=n+1;
            break;
        }
        if (s[i]=='#'){
            r = i;
            break;
        }
    }
    ll cnt = 0;
    rep(i,1,n+1){
        if (s[i]=='#') cnt++;
    }
    ll pos = a;
    ll f = 1;
    ll ans = 0;
    while (1){
        if (cnt==0){
            break;
        }

        if (f){
            ans += r-pos;
            pos = r;
            
            if (s[pos]!='F'){
                cnt--;
                s[pos] = '.';
            } 
            rep(i,pos,n+2){
                if (s[i]=='F'){
                    r=n+1;
                    break;
                }
                if (s[i]=='#'){
                    r = i;
                    break;
                }
            }
            f=0;
        }else{
            ans += pos-l;
            pos = l;
            
            if (s[pos]!='F'){
                s[pos] = '.';
                cnt--;
            } 
            f=1;
            repp(i,pos,0){
                if (s[i]=='F'){
                    l=0;
                    break;
                }
                if (s[i]=='#'){
                    l = i;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}