struct DisjointSet {
    int p[MAXN];
    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            p[i] = i;
        }
    }
    int Find(int x) {
        return (p[x] == x ? x : p[x] = Find(p[x]));
    }
    void Join(int a, int b) {
        p[Find(b)] = Find(a);
    }
}djs;
bool cmp(const Edge &a, const Edge &b) {
    return a.dis > b.dis;
}
struct Edge {
    int u, v, dis;
};
int main() {
    priority_queue<Edge, vector<Edge>, cmp> pq; 
    // push all edge in pq
    // djs init
    while (!pq.empty()) {
        Edge now = pq.top;
        pq.pop();
        if (djs.Find(now.u) != djs.Find(now.v)) {
            djs.join(u, v);
        }
    }
    return 0;
}
