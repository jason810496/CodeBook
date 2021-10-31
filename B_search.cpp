#include<bits/stdc++.h>
using namespace std;
int arr[1005];

void Cmp(){
    vector<int> vec;
    auto it=lower_bound(vec.begin(),vec.end(),10,[&](int a,int b){
        return a>b;
    });
}
int B_search(int L,int R,int target){ //[L,R]
    while(L<=R){
        int mid=L+(R-L)/2;
        if(arr[mid]<=target ) L=mid+1;
        else R=mid-1;
    }
    return L;
}