#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)

int main(){
    int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
    int ans = 0;
    if (a<0){
        ans += (-a)*c+d;
        ans += b*e;
    }else if(a==0){
        ans += d+b*e;
    }else{
        ans += (b-a)*e;
    }
    cout<<ans<<endl;
}