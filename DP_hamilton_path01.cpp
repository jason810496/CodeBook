#include<iostream>
#include<string.h>
#define N 10
// too hard
bool Graph[N][N]; // adjacency matrix
bool DP[1<<N][N];
bool visited[1<<N][N];

bool Path(int s,int s_size,int j){

    if(s_size==1) return true;

    if(visited[s][j]) return DP[s][j];
    visited[s][j]=true;

    for(int i=0;i<N;i++){
        if( i!=j && s&(1<<i)){
            if(Path( s^(1<<j), s_size-1 ,i) && Graph[i][j] ){

                return DP[s][j]=true;
            }
        }
    }
}

bool Hamilton_path(){
    memset(DP,0,sizeof(DP));
    memset(visited,0,sizeof(visited));
    for(int i=0;i<N;i++){
        if( Path((1<<N)-1 , N ,i) ) return true;
    }
    return false;
}