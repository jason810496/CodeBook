#include<iostream>
#include<string>
#define N 10005
using namespace std;
/*
    DP: Longest Common Subsequence
    O(N*M)
    N = len( String1 )
    M = len( String2 )
*/
string S1,S2;
int N1,N2,LCS_len;
int DP[N][N],Last[N][N];

// S1[0,n-1] , S2[0,m-1]
int LCS_length(int n,int m){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0) DP[i][j]=0;// initialize buttom

            else if(S1[i-1]==S2[j-1]){
                DP[i][j]=DP[i-1][j-1]+1;
            }
            else{
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    LCS_len=DP[n][m];
    return LCS_len;
}
void Print_LCS_loop(int n,int m){
    string temp;
    int len=LCS_len;
    temp.resize(LCS_len);
    while(len){
        if(S1[n-1]==S2[m-1]){
            temp[len-1]=S1[n-1];
            n--,m--,len--;
        }
        else if(DP[n-1][m] > DP[n][m-1]) n--;
        else m--;
    }
    cout<<temp<<'\n';
}

void Print_LCS_recursion(int n,int m){
    if(n<0||m<0) return;

    if( S1[n-1]==S2[m-1] ){
        Print_LCS_recursion(n-1,m-1);
        cout<<S1[n-1];
    }
    else if(DP[n-1][m]>DP[n][m-1]){
        Print_LCS_recursion(n-1,m);
    }
    else {
        Print_LCS_recursion(n,m-1);
    }
}
int main(){
    S1= "ABCBDAB";
    S2= "BDCABA";
    N1=S1.size(), N2=S2.size();
    cout<<"LCS Length: "<<LCS_length(N1,N2)<<'\n';
    Print_LCS_loop(N1,N2);
    Print_LCS_recursion(N1,N2);
    return 0;
}