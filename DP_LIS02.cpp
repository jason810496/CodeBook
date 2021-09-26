#include<bits/stdc++.h>
using namespace std;
/*
    DP LIS
    Time : O(NlgN)
    dp + b-search ( with STL )
*/
int main(){
    vector<int > LIS,arr;

    for(auto i:arr){
        auto it = lower_bound(LIS.begin(),LIS.end(),i);
        if(it==LIS.end() ) LIS.push_back( i );
        else *it=i;
    }
    return 0;
}
