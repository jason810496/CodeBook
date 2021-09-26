#include<iostream>
using namespace std;
#define N 105
int arr[N];
/*
    "Fake" segment tree (with single element update)
    use array instead of pointer
    (save time for new , delete operation)
*/
struct node{
    int sum; // range sum
    int min_; //range min
    int max_; // range max
}T[N<<2];

inline int Id(int L,int R){ return (L+R)|(L!=R);}

void Build(int L,int R){
    int i=Id(L,R);
    if(L==R){
        T[i].sum=arr[L];
        return;
    }

    int Mid=(L+R)/2;
    int l=Id(L,Mid),r=Id(Mid+1,R);
    Build(L    ,Mid );
    Build(Mid+1,R   );
    T[i].sum=T[ l ].sum+ T[ r ].sum;
}
int Query(int L,int R,int Q_L,int Q_R){
    int ret=0;
    if(Q_L<=L && R<= Q_R){
    // query left limit <= [cur range] <= query right limit
        ret+=T[ Id(L,R)].sum;
        return ret;
    }
    // check two sides
    int Mid=(L+R)/2;
    if(Q_L<=Mid) ret+=Query(L,  Mid, Q_L,Q_R);
    if(Q_R >Mid) ret+=Query(Mid+1,R, Q_L,Q_R);
    return ret;
}
void Update(int L,int R,int pos,int val){
    int i=Id(L,R);
    if(L==R){
        T[i].sum+=val;
        return ;
    }
    int Mid=(L+R)/2,l=Id(L,Mid),r=Id(Mid+1,R);
    if(pos<=Mid) Update(L,Mid,pos,val);
    if(pos>Mid) Update(Mid+1,R,pos,val);
    //pull
    T[i].sum= T[l].sum+T[r].sum;
}

int main(){
    //sample
    int n=10,L=1,R=10;
    
    for(int i=1;i<=n;i++) arr[i]=i;

    Build(L,R); // Build[1,10]
    cout<<'\n';
    cout<<Query(L,R,1,2)<<'\n';
    cout<<Query(L,R,3,4)<<'\n';
    cout<<Query(L,R,1,10)<<'\n';
    Update(L,R,5,10);
    cout<<Query(L,R,5,5)<<'\n';
    return 0;
}