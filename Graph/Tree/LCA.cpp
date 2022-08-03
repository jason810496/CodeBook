#include<iostream>
#include<vector>
using namespace std;
#define N 10005
#define LOG __lg(N)+1
vector<int> Graph[N];
int Time_count=0,Path[N],Last_visited[N],ST[LOG][N],Depth[N];
bool visited[N];

inline void add_edge(int u,int v){
    Graph[u].push_back(v);
    Graph[v].push_back(u);
}
// Get collection of DFS tree path
void DFS(int root){
    visited[root]=true;
    Last_visited[root]=Time_count;
    Path[Time_count++]=root;

    for(auto i:Graph[root]){
        if(visited[i]) continue;
        Depth[i]=Depth[root]+1;
        DFS(i);

        Last_visited[root]=Time_count;
        Path[Time_count++]=root;
    }
    
}
// sparse table preprocess
void Preprocess(int n){
    for(int i=0;i<n;i++) ST[0][i]=Path[i];

    for(int i=1; (1<<i)<=n ;i++){
        for(int j=0; j+(1<<(i))<=n ;j++){
            ST[i][j]= min( ST[i-1][j], ST[i-1][j+(1<<(i-1))] );
        }
    }
}
int Query(int L,int R){
    int K=__lg(R-L+1);
    return min( ST[K][L] , ST[K][R-(1<<K)+1 ]);
}

void LCA(int v,int u){
    // get last index of Path[i] ,i= v,u
    int L=min(Last_visited[v],Last_visited[u]);
    int R=max(Last_visited[v],Last_visited[u]);
    // min element of Path[L,R] = LCA
    // use sparse table to accomplish RMQ 
    int lca=Query(L,R);
    int len=Depth[v]+Depth[u] - 2*Depth[lca];
    cout<<"LCA("<<v<<','<<u<<")= "<<lca<<"\nPath length: "<<len<<"\n\n";
}

int main(){
    add_edge(1,2);
    DFS(1);
    Preprocess(Time_count+1);
    LCA(1,2);
    return 0;
}