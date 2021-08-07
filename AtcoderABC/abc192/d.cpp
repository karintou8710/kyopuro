//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,int>;
using PL = pair<ll,ll>;
using PPL = pair<pair<ll,ll>,ll>;
#define INF 1000000000
#define INFL 1000000000000000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
#define tp make_tuple
#define ALL(vec) vec.begin(), vec.end()
ll mod = 1000000007;
ll mod2 = 998244353;

// a + b がオーバーフローするならtrueを返す
template <class T> bool overflow_if_add(T a, T b) {
    return (std::numeric_limits<T>::max() - a) < b;
}

// a * b がオーバーフローするならtrueを返す
template <class T> bool overflow_if_mul(T a, T b) {
    return (std::numeric_limits<T>::max() / a) < b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string x;cin>>x;
    ll m;cin>>m;
    ll max_d = 0;
    ll size = x.size();
    if (size==1){
        ll ans = (x[0]-'0'<=m) ? 1 : 0;
        cout<< ans << endl;
        return 0;
    }

    rep(i,0,size){
        max_d = max(max_d, (ll)x[i]-'0');
    }

    max_d++;

    ll ok = m+1;
    ll inf = INFL + 10;
    ll ng = max_d-1;

    while ( (ok-ng)>1 ){
        ll mid = (ok+ng)/2;

        ll num = 0, keta=1, f=1;
        repp(i,size-1,0){
            ll d = x[i]-'0';
            if (d>inf/keta){
                f = 0;
                break;
            }
            ll num2 = d*keta;
            if (num>inf-num2){
                f = 0;
                break;
            }
            
            num += num2;
            if (i!=0 && keta>inf/mid){
                f = 0;
                break;
            }
            keta *= mid;
        }

        if (mid==2){
            cerr<<num<<endl;
            cerr<<m<<endl;
        }

        if (f && num<=m){
            ng = mid;
        }else{
            ok = mid;
        }
    }

    cout<<ng-max_d+1<<endl;
}