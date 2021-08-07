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

string t;
ll ans = 0;

void solve(string s, ll cnt){

    ll f = 1;
    rep(i,0,s.size()-2){
        if (s[i]==t[0] && s[i+1]==t[1] && s[i+2]==t[2]){
            string tmp = "";
            rep(j,0,s.size()){
                if (j<i || i+2<j){
                    tmp += s[j];
                }
            }
            solve(tmp, cnt+1);
            f = 0;
        }
    }
    if (f) ans = max(ans, cnt);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    string s;cin>>s;
    cin>>t;
    string tmp;
    ll cnt = 0;
    solve(s, cnt);
    cout<<ans<<endl;
}