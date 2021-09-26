#include<iostream>
using namespace std;
#define N 10005
#define INF 9999
int T[N<<1],arr[N];
/*
    Unfinish 


*/
inline int id(int l,int r){ return (r+l)|(r!=l); }

void Build(int L,int R){
    int i=id(L,R),Mid=(L+R)/2;
    int l=id(L,Mid),r=(Mid+1,R);
    if(L==R){
        T[i]=arr[L];
        return ;
    }
    
    Build(L,Mid);
    Build(Mid+1,R);
    T[i]=T[l]+T[r];
}
void Update(int L,int R,int ql,int qr,int val){
    if(ql>R || qr<L ) return;//out of range
    int i=id(L,R),Mid=(L+R)/2;
    int l=id(L,Mid),r=(Mid+1,R);

    if(ql<=L && R<=qr){
        T[i]+=val;
        return ;
    }

    Update(L,Mid,ql,qr,val);
    Update(Mid+1,R,ql,qr,val);
    T[i]=T[l]+T[r];
}

int Query(int L,int R,int ql,int qr){
    if(ql>R|| qr<L ) return 0;
    int i=id(L,R), Mid=(L+R)/2, ret=0;

    if(ql<=L && R<=qr){
        ret+=T[i];
        return ret;
    }
    ret+=Query(L,Mid,ql,qr);
    ret+=Query(Mid+1,R,ql,qr);
    return ret;
} 
int main(){
    int n=10,L=1,R=10;
    for(int i=1;i<=n;i++) arr[i]=i;
    Build(L,R);

    cout<<Query(L,R,1,2)<<'\n';
    cout<<Query(L,R,3,4)<<'\n';
    cout<<Query(L,R,1,10)<<'\n';
    Update(L,R,1,5,10);
    cout<<Query(L,R,5,5)<<'\n';
    cout<<Query(L,R,1,5)<<'\n';
    return 0;

    return 0;
}