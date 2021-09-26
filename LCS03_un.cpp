#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define Char_Range 128
using namespace std;
/*  (LCS -> LIS )

    unfinish

    Longest Common Subsequence -> 2D Longest Increasing Subsequence
    2D LIS -> 1D LIS
    O( K* Log( min(N,M )) + S )
    N : len( S1)
    M : len( s2)
    K : pair of numbers (worse case : K =N*M)
    S : counting sort
*/
//string S1,S2;
vector<int> S1,S2;
int LCS(){

    if(S1.size()==0|| S2.size()==0 ) return 0;
    // counting sort 
    vector<int> P[Char_Range];
    for(int i=0;i<S2.size() ;i++){
        P[ S2[i]].push_back(i);
    }

    vector<int> LIS;

    for(int i=0;i<S1.size(); i++){
        for(int cur,j=P[ S1[i]].size()-1; j>=0 ;j-- ){
            cur=P[ S1[i]][j];

            if(!LIS.empty() && cur > LIS.back() ){
                // not empty and current > previous
                LIS.push_back(cur );
            } 
            else {
                // update LIS last element
                *lower_bound(LIS.begin(),LIS.end(),cur)= cur;
            }
            
        }
    }

    return LIS.size()-1;
}


int main(){
    // S1= "abcbdab";
    // S2= "bdcaba";
    cout<<'a';
    S1={0,1,2,3,2,4,1,2};
    S2={0,2,4,3,1,2,1};

    cout<<LCS();
    return 0;
}
/*
    Reference : 
    ntnu algorithm note

*/