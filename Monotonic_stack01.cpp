#include<iostream>
#include<stack>
using namespace std;
#define N 100005
/*
    Monotonic Stack
    ( increasing sequence ) 
*/

int main(){
    int arr[N],n;
    cin>>n;
    for(int i=0;i<n;i++) arr[i]=rand()%100;
    stack<int> stk;// store index instead of value
    for(int i=0;i<n;i++){
        // if new element > last element then pop
        while(stk.size() && arr[ stk.top()]< arr[i]){
            stk.pop();
        }
        // add new element
        stk.push(i);
    }

    return 0;
}