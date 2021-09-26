#include<bits/stdc++.h>
using namespace std;
const int N= 10000;
bool is_Prime_1(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if( n%2==0 || n%3==0) return false;

    for(int i=5; i*i <=n ; i+=6){
        if(n%i==0 || n%(i+1)==0) return false;
    }

    return true;
}

void Prime_2(){
    bitset<N> Check;
    vector<int> v;
    for(int j=2;j<N;j++){
        if(!Check[j]){
            v.push_back(j);
            for(int i=j*j ;j<N;i+=j){
                Check[i]=true;
            }
        }
    }
}

