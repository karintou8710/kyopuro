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

    ll a,b,w;cin>>a>>b>>w;
    w *= 1000;
    ll maxans = 0;
    ll minans = 0;
    
    ll num = w%b, num2 = w/b;
    if (num > num2*(b-a)){
        cout<<"UNSATISFIABLE"<<endl;
        return 0;
    };
    minans = num2;
    if (num!=0) minans++;

    num = w%a, num2 = w/a;

    if (num > num2*(b-a)){
        cout<<"UNSATISFIABLE"<<endl;
        return 0;
    };

    maxans = num2;

    cout<<minans<<" "<<maxans<<endl;
}