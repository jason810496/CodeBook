#include<iostream>
using namespace std;
#define INF 9999
#define MAX_V 1005
#define MAX_E 1005
/*
    Short Path: Bellman Ford
    (use for negative cycles)
    O(V*E)
*/
struct Edge{
    int from,to,w;// w :weight
}Graph[MAX_E];

int V,E; // V: vertexs amount ,E: edges amount
int Dis[MAX_V];

int Bellman(int From,int To){
    for(int i=0;i<V;i++) Dis[i]=INF;
    Dis[From]=0;
    for(int k=1;k<=V;k++){ // relax V-1 times
        bool update=false;
        for(int i=0;i<E;i++){
            int from=Graph[i].from;
            int to=Graph[i].to;
            int weight=Graph[i].w;
            if(Dis[from]!=INF &&Dis[from]+weight <Dis[to]){
                if(to==To&&k==V) return -1;// detect negtative cycle (From->To)
                Dis[to]= Dis[from]+ weight;
                update=true;
            }
        }
        if(!update) break; //no negtive cycles
        //or if(!update) return true;
    }
    return Dis[To]!=INF;
}
int main(){

    return 0;
}