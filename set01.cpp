#include<iostream>
#include<set>
using namespace std;

int main(){
    int New_Value=10,Same_Value=10,Value_To_Find=20;
    set<int > S;
    // insert new value
    S.insert(New_Value);
    // insert same value
    S.insert(Same_Value);
    // Result : will not be inserted 

    // find value O(logN)
    auto it=S.find(Value_To_Find);

    if(it!=S.end()){
        // return iterator of value to find
        cout<<"Found "<<*it<<'\n';
    }
    else{
        // return set.end() if not found
        cout<<"Not Found\n";
    }
    // erase value
    S.erase(New_Value);

    return 0;
}