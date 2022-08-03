#include<bits/stdc++.h>
using namespace std;
#define PB push_back 
#define all(x) x.begin(),x.end()

int LIS(vector<int> arr){
    vector<int> Lis;
    for(int &num : arr ){
        if( Lis.empty() || Lis.back() < num ) Lis.PB( num );
        else{
            *lower_bound(all(Lis),num) = num ;
        }
    }
}