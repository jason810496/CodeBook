#include<iostream>
using namespace std;
#define MAX_N 10005
#define MAX_LOG __lg(MAX_N)+1// ( MAX_LOG >= log2(MAX_N) )
/*
    Sparse Table :
    Preprocess: O(N*logN)
    Query     : O(1)
*/
int n,arr[MAX_N],ST[MAX_LOG][MAX_N];
void Preprocess(){// ST[0,n-1]
    for(int i=0;i<n;i++) ST[0][i]= arr[i];

    for(int i=1; (1<<i)<=n ;i++){
        for(int j=0; j+(1<<i)<=n ;j++){
            ST[i][j]=max( ST[i-1][j], ST[i-1][j+(1<<(i-1))]);
        }
    }

}
inline int Query(int L,int R){// max arr[i] ,range(i) = [L,R]
    int K=__lg(R-L+1); // __lg :return log2(N) 
    return max(ST[K][L], ST[K][R-(1<<K)+1]);
}
int main(){
    n=10;
    for(int i=0;i<n;i++) arr[i]=i+1;
    Preprocess();
    cout<<Query(0,5)<<'\n';
    cout<<Query(5,9)<<'\n';
    cout<<Query(0,0)<<'\n';
    return 0;
}