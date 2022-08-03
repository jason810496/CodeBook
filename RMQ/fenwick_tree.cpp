#include <bits/stdc++.h>
using namespace std;
#ifdef tars3017
#define debug(...) do{\
    fprintf(stderr, "Line: %d -(%s) = ", __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0)
template<typename I>void _DO(I&&x){cerr<<x<<endl;}
template<typename I, typename...T>void _DO(I&&x, T&&...tail) {
    cerr<<x<<", ";
    _DO(tail...);
}
#else 
#define debug(...)
#endif
#define F first
#define S second
#define pii pair<int, int>
#define ll long long

#define MAXN 1005
struct FenwickTree {
    // index from 1 to n
    int tree[MAXN];
    int n;
    void init(int Size) {
        n = Size;
        memset(tree, 0, sizeof(tree));
    }
    int sum(int k) {
        int s = 0;
        while (k > 0) {
            s += tree[k];
            debug(k);
            k -= k&-k;
        }
        return s;
    }
    void add(int k, int x) {
        while (k <= n) {
            tree[k] += x;
            k += k&-k;
        }
    }
}BIT;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    BIT.init(5);
    for (int i = 1; i <= 5; i++) {
        int num;
        cin >> num;
        BIT.add(i, num);
    }
    cout << BIT.sum(3) << endl;
    return 0;
}

