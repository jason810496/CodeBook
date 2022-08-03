ll dp[MAX_N]={};
int main(){
    int n,Limit,wt,val,k;
    int Weight[MAX_N],Value[MAX_N],cnt=0;
    cin>>n>>Limit;
    while(n--){
        cin>>val>>wt>>k;
        if(k==-1){ // infinity
            for(int w=wt;w<=Limit;w++){
                dp[w]=max(dp[w],dp[w-wt]+val);
            }
        }
        else if(k==1){ // 0/1
            for(int w=Limit;w-wt>=0;w--){
                dp[w]=max(dp[w],dp[w-wt]+val);
            }
        }
        else{ // bounded 
            int base=1,rest=k;
            while(rest>=base){
                Weight[++cnt]=wt*base;
                Value[cnt] =val*base;
                rest-=base;
                base*=2;
            }
            if(rest>0){
                Weight[++cnt]=wt*rest;
                Value[cnt] = val*rest;
            }
        }
    }

    for(int i=1;i<=cnt;i++){
        for(int w=Limit;w-Weight[i]>=0;w--){
            dp[w]=max(dp[w],dp[w-Weight[i]]+Value[i]);
        }
    }

    cout<<dp[Limit];
    return 0;
}
Footer
