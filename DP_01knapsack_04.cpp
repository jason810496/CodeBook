#include<iostream>
#include<string.h>
using namespace std;
#define N 105
#define V 10005 // max sum of items value
int value[N],weight[N];
int DP_weight[V];
void Knapsack(){
    int n=100,max_val=1000,w=1000;
    for(int i=0;i<n;i++) {DP_weight[i]=10005;cout<<DP_weight[i]<<'\n';}
    n=6;
    max_val=200;
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

    for(int i=0;i<n;i++){ // for all items
        for(int j=max_val ;j-value[i] >=0 ;j--){// for all values
            DP_weight[j]=min(DP_weight[j], DP_weight[j- value[i]]+weight[i] );
        }
    }

    int val=max_val;
    cout<<"NNNNN\n";
    for(int i=0;i<val;i++) cout<<DP_weight[i]<<'\n';
    while( DP_weight[val] > w) val--;
    cout<<"Max value : "<<val;
}
int main(){
    Knapsack();
    return 0;
}