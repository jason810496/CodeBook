#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAX_N = 5005;
/*  Tarjan : AP / Bridge
    check : UVA 12783 (example input)
*/
//   dfs seq    Low seq
int D[MAX_N]={},Low[MAX_N]={},Time=0;
vector<int> G[2005];
vector<pii> Edge;
vector<int> AP;
void DFS(int v,int pa){
    D[v]=Low[v]=Time++;
    int ChildSize=0;
    bool isAP=false;

    for(int u:G[v]){
        if(u==pa ) continue;
        if( !D[u]){ // D[u]==0 -> haven't traval
            DFS(u,v);
            ChildSize++;
            if(D[v] <= Low[u] ) isAP=true;
            if(D[v] <  Low[u] ) Edge.push_back({v,u});
        }
        Low[v]=min(Low[v],Low[u]);
    }
    if( v==pa && ChildSize<2 ) isAP=false;
    if( isAP ) AP.push_back(v);
}

int DFS_cnt(int v,int pa){
    int ret=0;
    for(int u:G[v]){
        if(u==pa ) continue;
        ret+=DFS_cnt(u,v);
    }
    return ret+1;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,m,a,b;
    while(cin>>n>>m){
        if(n==0&&m==0 ) break;
        for(int i=0;i<n;i++) G[i].clear();
        Edge.clear();
        AP.clear();
        memset(D,0,sizeof(D));
        memset(Low,0,sizeof(Low));
        while(m--){
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        DFS(0,0);
        cout<<Edge.size()<<' ';
        sort(Edge.begin(),Edge.end());
        for(auto i:Edge){
            if(i.first>i.second){
                cout<<i.second<<' '<<i.first<<' ';
            }
            else{
                cout<<i.first<<' '<<i.second<<' ';
            }
        }
        cout<<'\n';
    }
    
    return 0;
}