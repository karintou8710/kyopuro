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
    vector<ll> ans; 
    for (ll i=1;i*i<=n;i++){
        if (n%i==0){
            if (n/i==i){
                ans.push_back(i);
            }else{
                ans.push_back(i);
                ans.push_back(n/i);
            }
        }
    }
    sort(ALL(ans));

    for (auto i : ans){
        cout<<i<<endl;
    }
}