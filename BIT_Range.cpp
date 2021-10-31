#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define lowbit(x) (x&-x)
const int MAX_N = 500005;
ll BIT1[MAX_N]={},BIT2[MAX_N]={};
int arr[MAX_N],n;
/*  BIT range update
    BUG
*/
void Init(){ // O(n) init
    for(int i=1;i<=n;i++){
        BIT1[i]+=arr[i];

        int j=i+lowbit(i);
        if(j<=n ) BIT1[j]+=BIT1[i];
    }
}

void Upd(ll T[],int idx,int val){
    for(int i=idx;i<=n;i+=lowbit(i)){
        T[i]+=val;
    }
}

void Range_Upd(int L,int R,int val){ // [L , R]
    // upd BIT1
    Upd(BIT1 , L ,val);
    Upd(BIT1 ,R+1 , (-val) );
    // upd BIT2
    Upd(BIT2, L ,val*(L-1) );
    Upd(BIT2, R+1 , (-val)*R );
}

inline ll query(ll T[],int idx){
    ll ret=0;
    for(; idx;idx-=lowbit(idx)){
        ret+=T[idx];
    }
    return ret;
}

ll RangeSum(int L,int R){
    L--; // L-1
    ll R_0,L_0; // [0,R] , [0,L-1]
    R_0 = query(BIT1,R)*R - query(BIT2,R);
    L_0 = query(BIT1,L)*L - query(BIT2,L);
    return R_0-L_0 ;
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    memset(BIT1,0,sizeof(BIT1));
    memset(BIT2,0,sizeof(BIT2));
    Init();
    int q,oper,l,r,v; 
    cin>>q;
    while(q--){
        cin>>oper;
        if(oper==1){
            cin>>l>>r>>v;
            Range_Upd(l,r,v);
        }
        else{
            cin>>l>>r;
            cout<<RangeSum(l,r)<<'\n';
        }
    }
    return 0;
}
