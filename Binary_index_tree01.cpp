#include<iostream>
using namespace std;
#define lowbit(x) x&-x
#define N 1005
/*
    Query for range(i,j)
    : Query(i)-Query(j-1)
*/
int BIT[N],arr[N],n=100;
inline void Update(int i,int val){
    for(;i<=n;i+=lowbit(i)) BIT[i]+=val;
}
inline int Query(int i){
    int ret=0;
    for(;i;i-=lowbit(i)) ret+=BIT[i];
    return ret;
}

void Build(int n){
    for(int i=1;i<=n;i++){
        Update(i,arr[i]);
    }
}

void Demo(){
    for(int i=1;i<=10;i++) arr[i]=1;
    Build(10);
    for(int i=1;i<=10;i++){
        cout<<Query(i)<<'\n';
    }
}
int main(){
    
    Demo();
    return 0;
}