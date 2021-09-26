#include<iostream>
#include<string.h>
#define N 105
#define W 10005
#define INF INT32_MAX
using namespace std;
/*
    DP : 0/1 Knapsack with different combination
    N: itmes amount
    W: max weight
    Time : O(N*W)
    Space : O(N*W) or O(W)
*/
int value[N],weight[N];
int DP[W],Put[N][W];
int output[N];
int ways[W];

void Print_all_possible(int n,int w,int k){
    if(n<0){
        for(int i=0;i<k;i++) cout<<output[i]<<' ';
        return ;
    }

    if(Put[n][w]==0){ // didn't put
        Print_all_possible(n-1,w,k);
    }
    else if(Put[n][w]==1){ // put
        output[k]=n;
        Print_all_possible(n-1,w-weight[n],k+1);
    }
    else if(Put[n][w]==2){
        // put
        output[k]=n;
        Print_all_possible(n-1,w-weight[n],k+1);

        // not put
        Print_all_possible(n-1,w,k);


    }
}

void Knapsack_with_different_combination(){
    int n=100,w=1000;
    memset(DP,0,sizeof(DP));
    memset(Put,0,sizeof(Put));
    memset(ways,0,sizeof(ways));

    for(int i=0;i<n;i++){ // for all items
        for(int j=w ; j>=weight[i] ;j--){ // j-weight[i]>=0

            if( DP[j-weight[i]]+value[i] < DP[j]){
                // don't put in knapsack

                Put[i][j]=0;
            }
            else if( DP[j-weight[i]]+value[i] > DP[i]){
                // is better to put in kapsack 
                DP[j]= DP[j-weight[i]]+value[i];
                Put[i][j]=1;
                ways[j]= ways[j-weight[i]]+1;
            }
            else { // DP[j-weight[i]]+value[i] == DP[i]
                // same value if not put
                
                Put[i][j]=2;
                ways[j]=ways[j- weight[i]]+1;
            }
        }
    }
    cout<<"Max value : "<<DP[w]<<'\n';
    cout<<"In "<<ways[w]<<" ways\n";
    Print_all_possible(n,w,0);
}
int main(){
    Knapsack_with_different_combination();
    return 0;
}


/*
n=6;
w=70;
int items_w[]{
    10,20,30,40,50,60
};
int items_v[]{
    1 ,20,40,30,50,1
};
for(int i=0;i<n;i++){
    weight[i]=items_w[i];
    value[i]=items_v[i];
}
*/