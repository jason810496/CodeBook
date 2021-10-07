#include<iostream>
using namespace std;
#define N 1000
int P[N+1],Group_Size[N+1];

inline void Initialize(int n){
    for(int i=1;i<=n;i++){
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
    Initialize(100);
    Union(10,20);
    Union(20,30);
    cout<<(Find(10)==Find(30) ? "Same group":"Different group");
    return 0;
}