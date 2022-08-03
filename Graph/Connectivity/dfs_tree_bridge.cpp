vector<int> g[kN];
int depth[kN], low[kN];
bool vis[kN];

void TarjanDfs (int v, int p) {
    vis[v] = true;
    low[v] = depth[v] = (p != -1 ? depth[p]+1 : 0);
    for (int u : g[v]) {
        if (u == p) continue;
        if (vis[u]) {
            low[v] = min(low[v], depth[u]);
        }
        else {
            TarjanDfs(u, v);
            low[v] = min(low[v], low[u]);
        }
    }
    if (low[v] == depth[v]) {
        // the edfe (v, p) is a bridge if v is not the root vertex.
    }
}
