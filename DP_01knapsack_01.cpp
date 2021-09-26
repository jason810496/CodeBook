#include<iostream>
#include<string.h>
#define N 105
#define W 10005
#define INF INT32_MAX
using namespace std;
/*
    DP : 0/1 Knapsack 
    N: itmes amount
    W: max weight
    Time : O(N*W)
    Space : O(N*W) or O(W)
*/
int value[N],weight[N];
int DP[N][W];
bool Put[N][W];
int Top_down(int n,int w){
    if(w <0 ) return -INF; // overweight
    if(n==0 ) return 0; //base

    if(DP[n][w]!=0 ) return DP[n][w]; 
                          // choose                      not choose
    return DP[n][w]= max( Top_down(n-1,w-weight[n]+value[n]) , Top_down(n-1,w) );
}

void Top_down_Demo(){
    // Time: O(N*W) ,Space: O(N*W)
    int n=100,w=10000;
    memset(DP,0,sizeof(DP));
    cout<<"Max value : "<<Top_down(n,w)<<'\n';
}

void Buttom_up(){
    // Time: O(N*W) ,Space: O(N*W)
    int n=100,w=10000;
    memset(DP,0,sizeof(DP));

    for(int i=0;i< n;i++){ //for all items
        for(int j=0;j<= w;j++){ // for all weight
            // overweight
            if( j-weight[i-1] <0){
                DP[i+1][j]= DP[i][j];
            }
            else{
                DP[i+1][j]= max( 
                    DP[i][j] ,
                    DP[i][ j-weight[i] ]+ value[i] );
            }
        }
    }
    cout<<"Max value : "<<DP[n][w]<<'\n';
}

void Buttom_up_space_W(){
    // Time: O(N*W) ,Space: O(W)
    int n=100,w=10000;
    int DP[W];
    memset(DP,0,sizeof(DP));
    int sum=0,arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    
    w=min(w,sum); // optimize

    int n=6,w=100;
    memset(DP,0,sizeof(DP));
    memset(Put,0,sizeof(Put));
    int item_value[]={
        100,100,100,100,100,100
    };
    int item_weight[]={
        10,20,30,40,50,60
    };
    for(int i=0;i<n;i++){
        value[i]=item_value[i];
        weight[i]=item_weight[i];
    }

    
    for(int i=0;i< n;i++){ //for all items
        for(int j=w ; j-weight[i] >=0 ;j--){// for all weight
            DP[j] =max( DP[j], DP[j-weight[i]]+value[i] );
        }
    }
    cout<<"Max value : "<<DP[w]<<'\n';
}

void Print_Ith_items(){
    // method 1:
    // Put[I][j]=true :  Ith item in the knapsack
    int n=100,w=10000;
    for(int i=n-1,j=w ; i>=0 ;i--){
        if(Put[i][j]){
            cout<<i<<"th item in the knapsack\n";
            j-= weight[i];
        }
    }

    // method 2: 
    // use original DP table with out extra space
    for(int i=n-1,j=w ;i>=0; i--){
        // not overweight  and      in the knapsack
        if( j-weight[i]>=0 && DP[i+1][j]==DP[i][j-weight[i]+value[i]] ){
            cout<<i<<"th item in the knapsack\n";
            j-= weight[i];
        }
    }

}

int main(){
    Buttom_up_space_W();
    return 0;
}