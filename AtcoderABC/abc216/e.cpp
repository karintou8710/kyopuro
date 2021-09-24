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
template <class T> inline bool chmax(T& a,T b) {if(a<b){a=b;return true;}return false;}
template <class T> inline bool chmin(T& a,T b) {if(a>b){a=b;return true;}return false;}
ll mod = 1000000007;
ll mod2 = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, k;cin>>n>>k;
    vector<ll> a;
    map<ll, ll> cnt;
    a.push_back(0);
    rep(i,0,n) {
        ll b;cin>>b;
        a.push_back(b);
        cnt[b]++;
    }
    sort(ALL(a), greater<ll>());
    int i = 0;
    ll ans = 0;
    while (k > 0) {
        if (i < (ll)a.size()-1 && a[i] == a[i+1]) {
            i++;
            continue;
        }

        ll score = a[i];
        if (score == 0) {
            break;
        }
        ll next = a[i+1];
        if (k - (score - next) * cnt[score] >= 0) {
            ans += ((score) * (score+1) / 2 - (next) * (next+1) / 2 ) * cnt[score];
            k -= (score - next) * cnt[score];
            cnt[next] += cnt[score];
            i++;
        } else {
            ll can = k / cnt[score];
            ans += ((score) * (score+1) / 2 - (score-can) * (score-can+1) / 2 ) * cnt[score];
            k -= can * cnt[score];
            ans += (score-can) * k;
            break;
        }

    }

    cout << ans << endl;

}