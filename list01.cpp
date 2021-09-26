#include<iostream>
#include<list>
using namespace std;

int main(){

    list<int> List01;
    // add new value from back
    List01.push_back(10);
    List01.push_back(30);
    List01.push_back(40);
    // add new value from front
    List01.push_front(20);
    // remove last value
    List01.pop_back();
    // remove first value
    List01.pop_front();
    // O(1)
    auto it = List01.begin();
    advance(it,2); // point to 3rd postion
    // insert value
    List01.insert(it,20);
}