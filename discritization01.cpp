#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
/*  Discritization
    Concept:
        using sort and binary search turn value to rank
*/

void Discritization1(vector<int> &vec){
    vector<int> temp(vec);
    sort(temp.begin(),temp.end());
    temp.erase( unique(temp.begin(),temp.end()),temp.end() );
    for(auto &i:vec){
        i=lower_bound(temp.begin(),temp.end(),i)-temp.begin();
    }
}
void Discritization2(vector<int> &vec){
    int rank=0;
    map<int,int> M;
    for(auto i:vec) M[i]=0;
    for(auto &i:M){
        i.second=rank++;
    }
    for(auto &i:vec){
        i=M.find(i)->second;
    }
}
int main(){
    
    return 0;
}