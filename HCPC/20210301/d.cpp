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
    string s;cin>>s;
    ll x;cin>>x;
    ll num = 0;

    ll first = 0;
    char last = 'a';

    while (1){
        rep(i,first,s.size()){
            if ('a'<= s[i] && s[i] <= 'z'){
                num++;
                last = s[i];
                if (num==x){
                    cout<<last<<endl;
                    return 0;
                }
            }else{
                ll tmp_num = num;
                num += num * (s[i]-'0');
                if (num == x){
                    cout<<last<<endl;
                    return 0;
                }else if(num > x){
                    x = x%tmp_num;
                    continue;
                }
            }
        }
    }
    
}