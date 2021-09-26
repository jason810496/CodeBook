#include<iostream>
using namespace std;
#define N 105
#define M 105

void stairs_1(){
    // Time :O(n*m) , Space: O(n*m)
    int DP[N][M];
    int n=10,m=10;
    // base case
    for(int i=0;i<n;i++) DP[i][0]=1;
    for(int j=0;j<m;j++) DP[0][j]=1;

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            DP[i][j]= DP[i-1][j]+ DP[i][j-1];
        }
    }
    cout<<DP[n-1][m-1]<<" ways from (0,0) to ("<<n<<','<<m<<")\n";
}

void stairs_2(){
    // Time :O(n*m) , Space: O(n)
    int DP[N];
    int n=10,m=10;
    // base case
    for(int j=0;j<m;j++) DP[j]=1;
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            DP[j]+= DP[j-1];
        }
    }

    cout<<DP[n-1]<<" ways from (0,0) to ("<<n<<','<<m<<")\n";
}
int main(){
    stairs_1();
    stairs_2();
    return 0;
}