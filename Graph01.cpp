#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define N 1000
/*
    Graph with vertex
    * Directed
    * Undirected
*/
vector<int> Graph[N];
bool visited[N];

inline void Add_vertex_undirected(int a,int b){
    // Undirected graph
    Graph[a].push_back(b);
    Graph[b].push_back(a);
}
inline void Add_vertex_directed(int a,int b){
    // directed graph
    // add vertex from a to b
    Graph[a].push_back(b);
}
void DFS_directed(int root){
    // make sure mark root visited
    if(Graph[root].empty()) return;
    // output in DFS order
    cout<<root<<' ';
    for(auto i:Graph[root]){
        visited[i]=true;
        DFS_directed(i);
    }
}
void BFS_directed(int root){
    queue<int> q;
    visited[root]=true;
    q.push(root);
    
    while(q.size()){
        int cur_node=q.front();
        q.pop();
        // output in BFS order
        cout<< cur_node<<' ';
        if(Graph[cur_node].empty()) continue;
        for(auto i:Graph[cur_node]){
            if(visited[i]) continue;
            visited[i]=true;
            q.push(i);
        }
    }

}

int main(){
    
    return 0;
}