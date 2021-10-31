#include<iostream>
using namespace std;
const int N= 1e6+5;
int P[N],Group_Size[N];
/*
    DSU
    check : https://zerojudge.tw/ShowProblem?problemid=f677
*/
inline void Initialize(int n){
    for(int i=0;i<=n;i++){
        P[i]=i; //initialize boss as itself
        Group_Size[i]=1;
    }
    return ;
}

inline int Find(int x){
    // check the boss
    return (x==P[x] ? x: P[x]=Find(P[x]) ); 
}

inline void Union(int a,int b){
    a=Find(a),b=Find(b);
    if(a==b) return;
    if(Group_Size[a]<Group_Size[b]) swap(a,b);
    P[b]=a;
    Group_Size[a]+=Group_Size[b];
}

int main(){
    int n ,m,x,y;
    cin>>n>>m;
    Initialize(n);
    while(m--){
        cin>>x>>y;
        Union(x,y);
    }
    cout<<Group_Size[Find(0)];
    return 0;
}