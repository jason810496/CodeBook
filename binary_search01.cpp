#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

void Output(int *L,int *R){
    for(int i=0;L+i!=R;i++) cout<<*(L+i)<<' ';
    cout<<'\n';
}
void Output(vector<int> vec){
    for(auto i:vec) cout<<i<<' ';
    cout<<'\n';
}
int main(){
    int num=128;
    

    int n=10,arr[10],value=10;
    for(int i=0;i<n;i++) arr[i]=i;
    // rearrange the array randomly
    random_shuffle(arr,arr+n);
    // output
    Output(arr,arr+n);
    // sort O(N*LogN)
    sort(arr,arr+n);
    Output(arr,arr+n);
    // for STL
    vector<int> vec(n);
    for(int i=0;i<n;i++) vec[i]=i;
    // rearrange the vector randomly
    random_shuffle(vec.begin(),vec.end());
    // output
    Output(vec);
    // sort
    sort(vec.begin(),vec.end());
    Output(arr,arr+n);

    // binary search
    // return iterator
    auto it = lower_bound(vec.begin(),vec.end(),5);
    auto it2 = upper_bound(vec.begin(),vec.end(),3);
    // if found return true
    bool it3 =binary_search(vec.begin(),vec.end(),10);
    // return pointer
    int *ptr =lower_bound(arr,arr+n,4);
    
    // binary search for set
    set<int> S;
    // faster
    auto s_it1= S.lower_bound(value);
    // slower 
    auto s_it2= lower_bound(S.begin(),S.end(),value);
    return 0;
}
