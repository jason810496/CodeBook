#include<iostream>
#include<vector>
using namespace std;
#define N 10005
vector<int> Graph[N];
int Time_count=0,Path[N];
bool visited[N];
/*
    decomposes tree into collection of path

    Example:
                1
              /  \
             2    3
           /  \   \
          4   5    6
    Euler Path:
    
    1 2 4 2 5 2 1 3 6 3 1 
*/
inline void add_edge(int u,int v){
    Graph[u].push_back(v);
    Graph[v].push_back(u);
}
void DFS(int root){
    visited[root]=true;
    Path[Time_count++]=root;
    for(auto i:Graph[root]){
        if(visited[i]) continue;
        DFS(i);
        Path[Time_count++]=root;
    }
    
}
int main(){
    add_edge(1,2);
    add_edge(1,3);
    add_edge(2,4);
    add_edge(2,5);
    add_edge(3,6);

    DFS(1);
    for(int i=0;i<Time_count;i++){
        cout<<Path[i]<<' ';
    }
    return 0;
}