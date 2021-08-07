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
    string s,x;cin>>s>>x;

    vector<ll> mod7(n);
    ll num = 1;
    repp(i,n-1,0){
        ll keta = s[i]-'0';
        mod7[i] = keta * num % 7;
        num = (num*10)%7;
    }

    vector<ll> ok(7);
    if (mod7[n-1]!=0 && x[n-1]=='A'){
        cout<<"Aoki"<<endl;
        return 0;
    }

    repp(i,n-1,0){
        if (x[i]=='A'){
            if (i==0){
                if (ok[0]==1 && ok[mod7[0]]==1){
                    cout<<"Takahashi"<<endl;
                }else{
                    cout<<"Aoki"<<endl;
                }
                return 0;
            }
            vector<ll> n2(7);
            rep(j,0,7){
                n2[j] = ok[j];
                if (ok[j]==1 && ok[(j+mod7[i])%7]==0){
                    n2[j] = 0;
                }
            }
            rep(j,0,7){
                ok[j] = n2[j];
            }
            
        }else{
            if (i==0){
                if (ok[mod7[0]]==1 || ok[0]==1){
                    cout<<"Takahashi"<<endl;
                }else{
                    cout<<"Aoki"<<endl;
                }
                return 0;
            }
            ok[0] = 1;
            rep(j,0,7){
                if (ok[j]==1){
                    ok[(j-mod7[i]+7)%7] = 1;
                }
            }
        }
    }
}