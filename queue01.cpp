#include<iostream>
#include<queue>
using namespace std;

int main(){
    int New_Value=10;
    queue<int > que;
    //add new value
    que.push(New_Value);
    //get front
    cout<<que.front();
    // pop the front value
    que.pop();
    //get current size
    cout<<que.size();
    return 0;   
}