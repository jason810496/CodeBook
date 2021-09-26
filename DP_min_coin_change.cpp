#include<bits/stdc++.h>
using namespace std;
/*

    DP miniumn coin change
Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1
    Time(C*V)
    C : Coins
    V : max value 

*/
const int INF = 1e9;
int main(){
    int coin[]={25,10,5},val=6;
    vector<int> dp(val+5,INF);

    dp[0]=0;
    for(int i=0;i<3;i++){ // for all coin
        for(int j=coin[i];j<=val;j++){
            dp[j]=min(dp[j],dp[j-coin[i]]+1);
        }
    }

    cout<<(dp[val]==INF ? -1:dp[val]);
    return 0;
}