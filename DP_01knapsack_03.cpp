#include<iostream>
#include<string.h>
#define N 105
#define W 10005
#define INF INT32_MAX
using namespace std;
/*
    DP : 0/1 Knapsack 
    * max values with minimum( maximum ) ways
    * max values with minimum( maximum ) weight
    N: itmes amount
    W: max weight
    Time : O(N*W)
    Space : O(N*W) or O(W)
*/
int value[N],weight[N];
int DP[W];
int ways[W];

void Knapsack(){
    int n=100,w=10000;
    memset(DP,0,sizeof(DP));
    memset(ways,0,sizeof(ways));

    for(int i=0;i<n;i++){ // for all items
        for(int j=w ; j>=weight[i] ;j--){ // j-weight[i]>=0

            if( DP[j-weight[i]]+value[i] > DP[j]){
                DP[j]= DP[ j-weight[i] ] + value[i];
                ways[j]=ways[ j-weight[i] ]+1;
            }
            else if( DP[j-weight[i]]== DP[j]){
                // for minimum ways
                if( ways[j-weight[i]]+1 < ways[j] ){
                    ways[j]= ways[j-weight[i]]+1 ;
                }
            }
        }
    }
    cout<<"Max value : "<<DP[w]<<'\n';
    cout<<"Minimum ways: "<<ways[w]<<"\n";
    // minimum weight
    int Min_weight=w;
    while( Min_weight-1>=0 && DP[Min_weight-1]==DP[w] ) Min_weight--;
    cout<<"Minimum weight: "<<Min_weight<<'\n';
}
int main(){
    Knapsack();
    return 0;
}