#include<iostream>
using namespace std;
#define lowbit(x) x&-x
/*
    BIT RMQ
    build : N (lgN)^2
    query : (lgN)^2
    ( slower than seg tree or ST)

    https://blog.csdn.net/zhouzi2018/article/details/81108940
*/
int BIT[500005],arr[500005],n;
inline void update(int idx){
    BIT[idx]=arr[idx];

    for(int i=1,N=lowbit(idx);i<N;i<<=1){
        BIT[idx]=max(BIT[idx],BIT[idx-i]);
    }
}

inline int RMQ(int L,int R){
    int ret=arr[R];
    
    while( L<=R ){
        ret=max(ret,arr[R]);
        for(--R ; R-L >=lowbit(R) ;R-=lowbit(R)){
            ret=max(ret,arr[R]);
        }
    }
    return ret;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) update(i);
    int q,l,r; cin>>q;
    while(q--){
        cin>>l>>r;
        if(l>r) swap(l,r);
        cout<<RMQ(l,r)<<'\n';
    }
    return 0;
}