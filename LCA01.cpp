#include<iostream>
#include<vector>
using namespace std;
#define N 10005
#define LOG __lg(N)+1
vector<int> Graph[N];
int Time_count=0,Path[N],Last_visited[N],ST[LOG][N],Depth[N];
bool visited[N];
/*
    Lowest Common Ancestor
    Example:
                1
              /  \
             2    3
           /  \   / \
          4   5  6   7

    LCA(4,5)= 2
    LCA(4,6)= 1
    LCA(1,5)= 1
    LCA(5,6)= 1
    LCA(6,7)= 3

    index: 0 1 2 3 4 5 6 7 8 9 10 11 12
    Path : 1 2 4 2 5 2 1 3 6 3 7  3  1 

            node : 1  2 3  4 5 6
    Last visited : 12 5 11 2 4 8
*/
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
    add_edge(1,3);
    add_edge(2,4);
    add_edge(2,5);
    add_edge(3,6);
    add_edge(3,7);
    // initialize depth
    Depth[1]=1;
    DFS(1);
    // sparse table
    Preprocess(Time_count+1);

    LCA(4,5);
    LCA(4,6);
    LCA(1,5);
    LCA(5,6);
    LCA(6,7);

    return 0;
}