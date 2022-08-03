#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e3+5;
struct line{ // each job can be regard as a line
    int Start,End,val;
    line(int s=0,int e=0,int v=0){
        Start=s,End=e,val=v;
    }
}Jobs[MAX_N];

// sort by end time 
inline bool comp(const line &a,const line &b){
    return a.End < b.End;
}
int main(){
    int dp[MAX_N]={},n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>Jobs[i].Start>>Jobs[i].End>>Jobs[i].val;
    }

    sort(Jobs,Jobs+n,comp);

    // dp[i] = max profit while choosing Jobs[i] or not
    dp[0]=Jobs[0].val ;

    for(int i=1;i<=n;i++){
        int L=0,R=i-1,idx=-1,Incusive;
        Incusive=Jobs[i].val;

        while( L<=R ){
            int mid = (L+R)/2;
            if(Jobs[i].Start >= Jobs[mid].End ){
                idx=mid;
                L=mid+1;
            }
            else R=mid-1;
        }

        if(idx!=-1 ) Incusive+=dp[idx];
        
        dp[i]=max(dp[i-1],Incusive);
    }

    cout<<dp[n-1];
    return 0;
}