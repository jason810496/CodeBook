#include<iostream>
#include<stack>
using namespace std;

int main(){
    int New_Value=10;
    stack<int> stk;
    stk.push(New_Value);
    // get stack top value
    cout<<stk.top();
    // pop last value
    stk.pop();
    // get current size
    cout<<stk.size();
    
    return 0;
}