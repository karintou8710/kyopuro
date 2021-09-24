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

typedef struct Node Node;

struct Node
{
    int kind;
    Node *rds;
    Node *lhs;
};

string str;
int str_i;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    str_i = 0;
}

Node *new_node(int kind, Node *lhs, Node *rds) {
    Node *node = (Node *)calloc(1, sizeof(Node));
    node->kind = kind;
    node->lhs = lhs;
    node->rds = rds;
    return node;
}

Node *E() {
    if (str[str_i] == '(') {
        str_i++;
        Node *e = E();
        Node *node = new_node(str[str_i], e, E());
        
        return node;
    }
}

Node *F() {

}