#include<iostream>
#include<string.h>
#define N 105
#define W 10005
#define INF INT32_MAX
using namespace std;
/*
    DP : Dividing coin
Given a bag with a maximum of 100 coins, determine the most fair division between two persons.
This means that the difference between the amount each person obtains should be minimised. The
value of a coin varies from 1 cent to 500 cents. It’s not allowed to split a single coin.
    N: itmes amount
    W: max weight
    Time : O(N*W)
    Space :  O(W)
*/

int main(){
    // items value = items weight 
    int n,total=0,limit,items[105];
    cin>>n;
    for(int i=0;i<n;i++) cin>>items[i],total+=items[i];

    limit=total/2;
    // weight limit = total money/2
    int dp[limit+5]={};

    for(int i=0;i<n;i++){ // for all items
        for(int w=limit;w-items[i]>=0;w--){
            // same as 0/1 knapsack
            dp[w]=max(dp[w],dp[w-items[i]]+items[i]);
        }
    }
    cout<<total-dp[limit]*2;
    
    return 0;
}