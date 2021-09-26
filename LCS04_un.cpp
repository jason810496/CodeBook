#include<iostream>
using namespace std;
#define N1 7
#define N2 6
/*
    Unfinish
    DP: Longest Common Subsequence
    // from ntnu algo 
*/
int LCS_len; // sequence length
int S1[N1+1]={0,1,2,3,2,4,1,2};
int S2[N2+1]={0,2,4,3,1,2,1}; // sequence 
/*
    LCS:
    {2,3,2,1}
    {2,3,1,2}
    {2,4,1,2}

    
*/
int DP[N1+1][N2+1]; // DP 
int Last[N1+1][N2+1];
int *temp;
/*
    Last: store where DP[i][j] from
    from DP[i-1][j-1] : 'k'
    from DP[i-1][ j ] : 'i'
    from DP[ i ][j-1] : 'j'
*/
void LCS_length(){
    // initialize 
    for(int i=0;i<=N1;i++) DP[i][0]=0;
    for(int j=0;j<=N2;j++) DP[0][j]=0;

     // just for lcs length 
    for(int i=1;i<=N1;i++){
        for(int j=1;j<=N2;j++){

            if(S1[i]==S2[j]) DP[i][j]=DP[i-1][j-1]+1;
            else DP[i][j]=max(DP[i-1][j], DP[i][j-1]);
        }
    }
    LCS_len=DP[N1][N2];
    cout<<"LCS length: "<<LCS_len<<'\n';
}
void Print_one_LCS(int i,int j){
    if(i==0 || j==0 ) return ; // NULL

    if(Last[i][j]=='k'){ //from [i-1][j-1]
        Print_one_LCS(i-1,j-1);
        cout<<S1[i];
    }
    else if(Last[i][j]=='i'){ // from [i-1][j]
        Print_one_LCS(i-1,j);
    }
    else if(Last[i][j]=='j'){// from [i][j-1]
        Print_one_LCS(i,j-1);
    }
}

void LCS_length_and_one_sequence(){
    // initialize 
    for(int i=0;i<=N1;i++) DP[i][0]=0;
    for(int j=0;j<=N2;j++) DP[0][j]=0;

     // get LCS 
    for(int i=1;i<=N1;i++){
        for(int j=1;j<=N2;j++){

            if(S1[i]==S2[j]){
                DP[i][j]= DP[i-1][j-1]+1;
                Last[i][j]='k'; // from [i-1][j-1]
            }
            else if(DP[i-1][j] > DP[i][j-1]){
                DP[i][j]= DP[i-1][j];
                Last[i][j]='i'; // from [i-1][j]
            }
            else {
                DP[i][j]= DP[i][j-1];
                Last[i][j]='j'; // from [i][j-1]
            }
        }
    }
    LCS_len=DP[N1][N2];
    // cout<<"LCS length: "<<LCS_len<<'\n';
    cout<<"LCS:\n";
    Print_one_LCS(N1,N2);
}

int main(){
    srand(time(NULL));
    // for(int i=1;i<=N1;i++){
    //     S1[i]=rand()%5+1;
    //     cout<<S1[i];
    // } 
    // cout<<'\n';
    // for(int i=1;i<=N2;i++){
    //     S2[i]=rand()%5+1;
    //     cout<<S2[i];
    // } 
    // cout<<'\n';
    LCS_length();
    temp= new int[LCS_len];
    LCS_length_and_one_sequence();
    return 0;
}
