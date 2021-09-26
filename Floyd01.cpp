#include<iostream>
using namespace std;
#define INF 9999
#define N 105
/*
    Shortest Path: Floyd Warshall 
    O(V^3)
    limit: *no negtive cycle*
*/
int V,Dis[N][N],Graph[N][N];
int main(){
    cin>>V;
    // Graph[i][j] = weight from i to j
    // if not exist : Graph[i][j]=INF
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            Dis[i][j]=Graph[i][j];
        }
    }

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                // check if the path is shoter
                if(Dis[i][j]> Dis[i][k]+ Dis[k][j]){
                    Dis[i][j]=Dis[i][k]+Dis[k][j];
                }
            }
        }
    }
    return 0;
}