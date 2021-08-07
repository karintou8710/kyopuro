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
    ll a,r,n;cin>>a>>r>>n;
    if (r==1){
        if (a<=INF){
            cout<<a<<endl;
        }else{
            cout<<"large"<<endl;
        }
    }else{
        ll num = a;
        ll cnt = 1;
        while (cnt<n){
            if (num>INF){
                cout<<"large"<<endl;
                return 0;
            }
            cnt++;
            num *= r;
        }
        if (num>INF){
            cout<<"large"<<endl;
            return 0;
        }
        cout<<num<<endl;
    }
    
}