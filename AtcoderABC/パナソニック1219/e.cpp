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

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int t;cin>>t;
    rep(_,0,t){
        ll n,s,k;cin>>n>>s>>k;
        s %= n;
        s = (-s+n)%n;
        ll gcd = __gcd(__gcd(n,s),k);
        n /= gcd;
        s /= gcd;
        k /= gcd;
        if (__gcd(n,k)==1){
            ll a1 = modinv(k,n);
            cout<<a1*s%n<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
}   