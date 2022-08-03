#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;

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

