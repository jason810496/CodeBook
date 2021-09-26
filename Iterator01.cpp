#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec01;
    //iterator
    vector<int>::iterator it1=vec01.begin();
    // version >= c++11
    auto it2=vec01.begin();
    cout<<*it2; // dereference

    auto it3=vec01.end();
    cout<<*it3; // ERROR
    /*
    By C++ reference 
    The past-the-end element is the theoretical element that would follow the last element in the vector. 
    It does not point to any element, and thus shall not be dereferenced.
    */
    // reverse begin , reverse end
    auto it4=vec01.rbegin(), it5=vec01.rend();
    cout<<*it5; //ERROR (same error as vec.end() )
    //Instead 
    cout<<vec01.back(); // last value

    // Other STL container example
    set<int>::iterator iter_set;
    list<long long>::iterator iter_list;
    // etc...
    return 0;
}