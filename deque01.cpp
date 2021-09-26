#include<iostream>
#include<deque>
using namespace std;

int main(){
    // double ended queue
    deque<int > dq01;
    // add value from back
    dq01.push_back(10);
    dq01.push_back(30);
    // add value from front
    dq01.push_front(20);
    dq01.push_front(40);
    // pop value from front
    dq01.pop_front();
    // pop vlaue from back
    dq01.pop_back();
    // get front value
    cout<<dq01.front();
    //get last value
    cout<<dq01.back();

    return 0;
}