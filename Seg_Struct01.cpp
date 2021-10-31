#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 500005;

int arr[N];
ll T[N<<1]={} , tag[N]={} ;
struct seg{
    int n;
    void upd(int p,ll val,int h){
        T[p]+= val<<h ;
        if(p < n) tag[p]+= val;
    }
    void pull(int p){
        for(int h=1;p>1 ;p>>=1 ,h++ ){
            T[p>>1]=T[p^1]+ T[p]+ (tag[p>>1]<<h);
        }
    }
    void push(int p){
        for(int h=__lg(n);h>=0 ;h--){
            int i = p>>h ;
            if( !tag[i>>1] ) continue;
            upd(i, tag[i>>1] ,h);
            upd(i^1 ,tag[i>>1] ,h);
            tag[i>>1]=0;
        }
    }
    void add(int L,int R,ll val){
        int l=L , r=R ,h=0;
        push(l+n) , push(r-1+n);
        for(l+=n,r+=n ; l<r ;l>>=1 ,r>>=1 ,h++){
            if(l&1) upd(l++,val,h);
            if(r&1) upd(--r,val,h);
        }
        pull(L+n) , pull(R-1+n);
    }
    ll query(int l,int r){
        ll res=0;
        push(l+n) , push(r-1+n);
        for(l+=n,r+=n; l<r ;l>>=1 ,r>>=1){
            if(l&1) res+=T[l++];
            if(r&1) res+=T[--r];
        }
        return res;
    }
    void init(int Size){
        n=Size;
        for(int i=0;i<n;i++) T[i+n]=arr[i];
        for(int i=n-1;i>0 ;i--){
            T[i]=T[i<<1]+T[i<<1|1];
        }
    }
}SegmentTree;

int main(){
    // check :
    // https://zerojudge.tw/ShowProblem?problemid=d799
    int n ,q ,op,l,r; cin>>n;
    ll v;
    for(int i=0;i<n;i++) cin>>arr[i];
    SegmentTree.init(n);
    cin>>q;
    while(q--){
        cin>>op;
        if(op==2){
            scanf("%d%d",&l,&r);
            printf("%lld\n",SegmentTree.query(l-1,r));
        }
        else{
            scanf("%d%d%lld",&l,&r,&v);
            SegmentTree.add(l-1,r,v);
        }
    }
    return 0;
}