//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1000000000
#define INFL 1000000000000000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
#define tp make_tuple
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef tuple<int,int,int> T;
typedef tuple<ll,ll,ll> TL;
ll mod = 1000000007;
ll mod2 = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;cin>>n>>k;
    ll num = n;

    rep(i,0,k){
        vector<ll> a;
        ll s = num;
        while (s>0){
            a.push_back(s%10);
            s/=10;
        }
        sort(a.begin(), a.end());

        s = 1;
        ll num2 = 0;
        rep(j,0,a.size()){
            num2 += (a[j]-a[a.size()-j-1])*s;
            s *= 10;
        }
        num = num2;
    }
    cout<<num<<endl;
}