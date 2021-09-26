#include<iostream>
using namespace std;
#define INF 9999
#define N 10005
/*
    Segment Tree (pointer) 
    ( with single element update)
*/
struct node{
    int val=0;
    node *right=nullptr,*left=nullptr;
    // update current value after recursion
    void Pull(){
        val=max(right->val,left->val);
    }
};
int arr[N];

node *Build(int l,int r){
    node *T=new node;
    if(l==r){
        T->val=arr[l];
        return T;
    }
    // keep recursion
    int Mid=(l+r)/2;
    T->left= Build(l,Mid);
    T->right= Build(Mid+1,r);
    T->Pull();
    return T;
}

int Query(node *T,int l,int r,int ql,int qr){
    if(r<ql || l>qr ) return -INF; // check out of range
    if(ql<=l && r<=qr){ // current block range fit query range
        return T->val;
    }
    int Mid=(l+r)/2;
    return max( Query(T->left,l,Mid,ql,qr),Query(T->right,Mid+1,r,ql,qr) );
}
// arr[pos]+=val
void Update(node *T,int l,int r,int pos,int val){
    if(l==r){
        T->val+=val;
        return;
    }
    int Mid=(l+r)/2;
    /*
        either check range by the following if else statement
        or check at the begging of function
    */
    if(pos<=Mid) Update(T->left,l,Mid,pos,val);
    if(pos> Mid) Update(T->right,Mid+1,r,pos,val);
    T->Pull();
}
void Demo(){
    
}
int main(){

    // sample
    int n=10,L=1,R=10;
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    node *T=Build(L,R);
    cout<<Query(T,L,R,1,3)<<'\n';
    cout<<Query(T,L,R,3,5)<<'\n';
    Update(T,L,R,5,-5);
    cout<<Query(T,L,R,1,3)<<'\n';
    cout<<Query(T,L,R,3,5)<<'\n';
    cout<<Query(T,L,R,5,5)<<'\n';
    return 0;
}