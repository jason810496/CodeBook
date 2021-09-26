#include<iostream>
using namespace std;
const int MAX_Moneny = 1e5+5;
/*
    DP coin change :
Given a value N, if we want to make change for N cents, 
and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
how many ways can we make the change? 

    Time : O(C*N) C: C kinds of coin value
    Space: O(N)   N: MAX value 
*/
long long dp[MAX_Moneny];
int main(){
    int coin[]={1,5,10,25,50};

    // base case 
    dp[0]=1;
    for(int i=0;i<5;i++){ // for all coin value
        for(int j=coin[i];j<=100000;j++){ 
            dp[j]+=dp[j-coin[i]];
        }
    }
    return 0;
}