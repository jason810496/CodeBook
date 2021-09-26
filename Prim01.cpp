#include<bits/stdc++.h>
using namespace std;
#define N 1005
typedef pair<int,int> pii;
/*
    Minimium Span Tree : Prim's
    O(E logV)
    E : edges
    V : vertexs 
*/
int Dis[N];
bool visited[N];
vector<pii> Graph[N];
/*
    pii.first = edge
    pii.second = vertex
*/
inline void Add_edge(int v_,int u_,int e_){
    Graph[v_].push_back({e_,u_});
    Graph[u_].push_back({e_,v_});
}

int main(){
    // heap front : min edge
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    int n,u_,v_,e_,sum=0;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     cin>>v_>>u_>>e_;
    //     Add_edge(v_,u_,e_);
    // }
    n=11;
    Add_edge(0, 1, 4);
    Add_edge(0, 7, 8);
    Add_edge(1, 2, 8);
    Add_edge(1, 7, 11);
    Add_edge(2, 3, 7);
    Add_edge(2, 8, 2);
    Add_edge(2, 5, 4);
    Add_edge(3, 4, 9);
    Add_edge(3, 5, 14);
    Add_edge(4, 5, 10);
    Add_edge(5, 6, 2);
    Add_edge(6, 7, 1);
    Add_edge(6, 8, 6);
    Add_edge(7, 8, 7);

    // initialize
    memset(Dis,100,sizeof(Dis));
    memset(visited,0,sizeof(visited));
    // start from 0 
    int start=0;
    Dis[start]=0;
    pq.push({0,start});
    while(pq.size()){
        pii cur=pq.top();
        pq.pop();
        v_ =cur.second;
        // already visited or the path is longer
        if(visited[v_] || cur.first > Dis[v_]) continue;
        visited[v_]=true;// mark visited
        sum+=Dis[v_];
        for(auto i:Graph[v_]){
            int next=i.second, weight=i.first;
            if(Dis[next]> weight ){// update the path length (like Dijskra algorithm)
                Dis[next] = weight;
                pq.push( {Dis[next],next});
            }
            
        }
    }
    cout<<"weight of MST "<<sum;
}