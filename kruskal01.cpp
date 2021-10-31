#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
#define N 1005
typedef pair<int,int> pii;
/*
    Minimium Span Tree : Kruskal's
    O(E LogV)
*/
struct Edge{
    int V,U,E;
    /*  V: from
        U: to
        E: weight
    */
    Edge(int v_=0,int u_=0,int e_=0){
        V=v_;
        U=u_;
        E=e_;
    }
};
int P[N],Group_size[N];
vector<Edge> Graph;
/*
    Edge.V = from
    Edge.U = to
    Edge.E = edge
    ( sort edges in increase order)
*/
void Init(int n){
    for(int i=0;i<=n;i++){
        P[i]=i;
        Group_size[i]=1;
    }
}
inline int Find(int x){
    return x==P[x]? x: P[x]=Find(P[x]);
}
void Union(int a,int b){
    a=Find(a),b=Find(b);
    if(a==b) return;
    if(Group_size[b]>Group_size[a]) swap(a,b);
    Group_size[a]+=Group_size[b];
    P[b]=a;
}
inline bool comp(Edge a,Edge b){
    // sort in increasing order (by edge weight)
    return a.E<b.E;
}
inline void Add_edge(int v_,int u_,int e_){
    Graph.push_back(Edge(v_,u_,e_));
}
int main(){
    Init(10);
    int n,v_,u_,e_,a,b,sum=0;
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
    sort(Graph.begin(),Graph.end(),comp);

    for(auto i:Graph){ // loop through sorted edges
        a=Find(i.V), b=Find(i.U);
        if(a==b) continue; // if already connected 
        Union(a,b);
        sum+=i.E;
    }
    cout<<"weight of MST "<<sum;
    return 0;
}