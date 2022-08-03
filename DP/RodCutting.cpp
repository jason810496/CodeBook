int Topdown(int L,int R){
    if(dp[L][R]>0 ) return dp[L][R];
    // not more cut between cut[L] and cut[L+1]
    if(L+1==R ) return dp[L][R]=0;

    int Min_cost=1e9;
    for(int i=L+1;i<R;i++){
        // cost(i,j) = cost(i,k)+cost (k,j)
        // i<k<j
        Min_cost=min(Min_cost,
            Topdown(L,i)+Topdown(i,R)
        );
    }

    return dp[L][R] = Min_cost + cut[R]-cut[L];
}
int main(){
    cin>>Len>>n;
    cut[0]=0;
    cut[n+1]=Len;
    for(int i=1;i<=n;i++) cin>>cut[i];
    cout<<Topdown(0,n+1);
    return 0;
}