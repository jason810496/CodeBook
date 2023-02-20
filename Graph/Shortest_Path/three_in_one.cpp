// Dijkstra
struct edge {
    int node, weigth;
};
void Dijkstra(vector<edge> G[], vector<int> &dist, int src) {
    auto cmp = [](edge lhs, rhs) {
        return lhs.weight < rhs.weight;
    }
    priority_queue<edge, vecotr<edge>, decltype(cmp)> pq(cmp);
    dist[src] = 0; pq.push({src, 0});
    while (!pq.empty()) {
        auto u = pq.top(); pq.pop();
        if( u.weight != dist[u.node] ) continue;
        for (auto v : G[u.node]) {
            if (dist[v.node] > dist[u.node] + v.weight) {
                dist[v.node] = dist[u.node] + v.weight;
                pq.push({v.node, dist[v.node]});
            }
        }
    }
}
// BellmanFord
void BellmanFord(vector<edge> G[], vector<int> &dist, int src) {
    dist[src] = 0;
    for (int i = 0; i < N_NODE - 1; ++i) {
        for (int u = 0; u < N_NODE; u++) {
            for (auto e : G[u]) {
                if (dist[e.node] > dist[u] + e.weight) {
                    dist[e.node] = dist[i] + e.weight;
                }
            }
        }
    }
}
// FloydWarshall
void FloydWarshall(int G[][N_NODE]) {
    for (int k = 0; k < N_NODE; ++k) {
        for (int i = 0; i < N_NODE; ++i) {
            for (int j = 0; j < N_NODE; ++j) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}
