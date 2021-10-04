#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 1e4+5;
const int INF = 1e9;
/*
min(dp[i][j - 1], // Insert
    dp[i - 1][j], // Remove
    dp[i - 1][j - 1]); // Replace

https://zerojudge.tw/ShowProblem?problemid=e828
*/
int dp[MAX_N][MAX_N]={};
int main(){
    OAO
    string str1,str2;
    cin>>str1>>str2;
    int n=str1.size(),m=str2.size(),Dis=INF;

    int Insert=2,Remove=2,Replace=3; // cost of operation
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0) dp[i][j]=j*Insert;
            else if(j==0) dp[i][j]=i*Insert;
            else if(str1[i-1]==str2[j-1]){
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j]+Insert ,dp[i][j-1]+Remove));
            }
            else {
                dp[i][j]=min(dp[i-1][j-1]+Replace, min(dp[i-1][j]+Remove,dp[i][j-1]+Insert ));
            }
        }
    }

    if(dp[n][m]<=Dis){
        Dis=dp[n][m];
    }
    cout<<Dis;
    return 0;
}