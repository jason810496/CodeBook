#include<bits/stdc++.h>
using namespace std;
struct Comp{
    // return even number ,if all odd return bigger number
    bool operator()(const int &a,const int &b){
        return (a&1 ? 0:(b&1==1 ? a>b:1));
    }
};
int main(){
    priority_queue<int,vector<int>,Comp> pq1; // compare function structure 
    priority_queue<int,vector<int>,greater<int>> pq2; // min heap 
    return 0;
}