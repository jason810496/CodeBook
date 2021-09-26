#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define N 1001
/*
    N*N Graph in matrix
    (i,j) for each block
    1<= i <=1000 , 1<= j <=1000 in this example
*/
int Graph[N][N];
bool visited[N][N];
int pos[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
/*
    pos array means four direction of each block
    (shorten four if statment in a for loop)
*/
inline void Output(int i,int j){
    cout<<'('<<i<<','<<j<<")\n";
}
void DFS(int I,int J){
    // make sure (I,J) is marked visited
    Output(I,J);
    int I__,J__;
    for(int i=0;i<4;i++){
        I__=I+pos[i][0], J__=J+pos[i][1];
        // check if out of range
        if(I__<1||I__>1000||J__<1||J__>1000) continue;
        // check if visited
        if(visited[I__][J__]) continue;
        visited[I__][J__]=true;
        DFS(I__,J__);
    }
}
void BFS(int I,int J){
    // make sure (I,J) is marked visited
    int I__,J__;
    queue<pair<int,int> > q;
    q.push({I,J});
    Graph[I][J]=1;
    while(q.size()){
        I=q.front().first;
        J=q.front().second;
        Output(I,J);
        q.pop();

        for(int i=0;i<4;i++){
            I__=I+pos[i][0], J__=J+pos[i][1];
            // check if out of range
            if(I__<1||I__>1000||J__<1||J__>1000) continue;
            // check if visited
            if(visited[I__][J__]) continue;
            visited[I__][J__]=true;
            q.push({I__,J__});
            Graph[I__][J__]=Graph[I][J]+1;
            // count steps
        }
    }
    
}
int main(){
    return 0;
}