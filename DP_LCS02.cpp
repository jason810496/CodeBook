#include<iostream>
#include<string>
#include<set>
#define N 10005
using namespace std;
/*
    DP: Longest Common Subsequence 2
    Output all LCS
*/
string S1,S2;
int N1,N2;
int DP[N][N];
// length of LCS ( S1[0,n-1] ,S2[0,m-1] )
int LCS_length(int n,int m){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){

            if(i==0||j==0) DP[i][j]=0; // initialize

            else if(S1[i-1]==S2[j-1]){
                DP[i][j]= DP[i-1][j-1]+1;
            }
            else{
                DP[i][j]=max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
    return DP[n][m];
}

set<string> All_LCS(int n,int m){
    set<string> s;
    if(n==0 || m==0){ // end of string
        s.insert("");
        return s;
    }

    if(S1[n-1]== S2[m-1]){
        set<string> temp=All_LCS(n-1,m-1); // keep recursion

        for(string str:temp){
            s.insert(( str+S1[n-1]) ); // append current char to all possible LCS
        }

    }
    else{

        if(DP[n-1][m]>= DP[n][m-1]){
            s=All_LCS(n-1,m);
        }

        if(DP[n][m-1]>= DP[n-1][m]){
            set<string> temp=All_LCS(n,m-1);

            s.insert(temp.begin(),temp.end());
        }
        
    }
    return s;
}
int main(){
    S1= "ABCBDAB";
    S2= "BDCABA";
    N1=S1.size(), N2=S2.size();
    cout<<"LCS Length: "<<LCS_length(N1,N2)<<'\n';

    set<string> s=All_LCS(N1,N2);

    cout<<"All LCS:\n";
    for(string str:s){
        cout<<str<<'\n';
    }
}