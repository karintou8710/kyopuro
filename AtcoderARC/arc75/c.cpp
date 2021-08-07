//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
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
    int n;cin>>n;
    vector<ll> a;
    ll sum_ten = 0;
    ll ans = 0;
    rep(i,0,n){
        int b;cin>>b;
        if (b%10==0){
            sum_ten += b;
        }else{
            a.push_back(b);
            ans += b;
        }
    }

    if (a.size()==0){
        cout<<0<<endl;
        return 0;
    }

    if (ans%10==0){
        ans -= *min_element(a.begin(), a.end());
    }

    ans += sum_ten;
    cout<<ans<<endl;

}