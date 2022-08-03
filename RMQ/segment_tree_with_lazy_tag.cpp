#include <bits/stdc++.h>
using namespace std;
ll pre[200005];
ll n, q; 
const int MAXN = 200005;
struct Node {
    int chg, data;
}ST[MAXN*4];
void build(int i, int l, int r) {
    if (l == r) {
        debug(i, pre[l]);
        ST[i].data = pre[l];
        return ;
    }
    int m = (l+r) / 2, lson = i*2+1, rson = i*2+2;
    build(lson, l, m);
    build(rson, m+1, r);
    ST[i].data = max(ST[lson].data, ST[rson].data);  
}
void add(int a, int b, int i, int l, int r, ll x) {
    if (a <= l && r <= b) {
        debug(i, l, r, x);
        ST[i].chg += x;
    }
    else if (r < a || b < l) return ;
    else {
        int m = (l+r) / 2, lson = i*2+1, rson = i*2 + 2;
        add(a, b, lson, l, m, x);
        add(a, b, rson, m+1, r, x);
        ST[i].data = max(ST[lson].data+ST[lson].chg, ST[rson].data+ST[rson].chg);
    }
}
ll query(int a, int b, int i, int l, int r) {
    if (a <= l && r <= b) return ST[i].data+ST[i].chg;
    else if (r < a || b < l) return -1;
    else {
        int m = (l+r) / 2, lson = i*2+1, rson = i*2+2;
        ll x1 = query(a, b, lson, l, m);
        ll x2 = query(a, b, rson, m+1, r);
        return max(x1, x2) + ST[i].chg;
    }
}
int main() {
    cin >> n >> q;
    // input pre arr (idx from 1)
    build(1, 1, n);
    // query(query_left, query_right, 1, 1, n);
    return 0;
}

