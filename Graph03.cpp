#include<iostream>
#include<vector>
using namespace std;
#define N 1005
/*
    Graph with vertexs and edges
    pair.first = next vertex
    pair.second = edge
*/
vector<pair<int,int> > Graph[N];

void Add_vertex_ditected(int v,int u,int e){
    //    edge
    // v---------> u
    // vertex v to u with edge= e
    Graph[v].push_back({u,e});
}
void Add_vertex_undirected(int v,int u,int e){
    Graph[v].push_back({u,e});
    Graph[u].push_back({v,e});
}

int main(){

    return 0;
}