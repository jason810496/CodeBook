#include<bits/stdc++.h>
using namespace std;
int main(){
    multiset<int> S;
    S.count(10); // return val amount
    S.equal_range(10); 
    //return range in pair
    /* Eg:
The multiset elements are: 1 2 3 3 3 5 5 6 
The lower bound of 3 is 3
The upper bound of 3 is 5
    */
   S.erase(10); // erase all
   S.erase(S.lower_bound(10)); // erase single
    return 0;
}