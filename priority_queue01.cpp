#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

struct Comp{
    // return even number ,if all odd return bigger number
    bool operator()(const int &a,const int &b){
        return (a&1 ? 0:(b&1==1 ? a>b:1));
    }
};

int main(){
    // max heap 
    priority_queue<int> pq1;
    // min heap
    priority_queue<int,vector<int>,greater<int> > pq2;
    // using compartor
    priority_queue<int,vector<int>,Comp > pq3;

    // add new value O(LogN)
    pq1.push(10);
    pq1.push(20);
    pq1.push(15);
    // get max value O(1)
    cout<<pq1.top();
    // pop out max value 
    pq1.pop();
    return 0;
}