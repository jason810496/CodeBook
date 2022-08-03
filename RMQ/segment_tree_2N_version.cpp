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
int tree[2*MAXN];
int n; // size of array
// a, b are 0 based index!
int sum(int a, int b) {
    a += n, b += n;
    int s = 0;
    while (a <= b) {
        if (a % 2 == 1) s += tree[a++]; 
        if (b % 2 == 0) s += tree[b--];
        a /= 2, b /= 2;
    }
    return s;
}

void add(int k, int x) { // k is 0 based index!
    k += n;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2*k] + tree[2*k + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}

