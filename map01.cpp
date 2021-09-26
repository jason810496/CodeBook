#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    int New_Value=10,Same_Value=10,Value_To_Find=20;
    // Initialize map type
    map<int,int> M01; // int as index
    map<string ,int> M02; // string as index

    // add new pair in different ways
    M01.insert(make_pair(-1,-10));
    M01.insert({0,10});
    M01[1]=1;
    M01[2]=20;

    M02["num1"]=1;
    M02["num2"]=2;

    // find by index
    auto it =M02.find("num1");
    if(it!=M02.end()){
        cout<<"Found "<<M02["num1"]<<'\n';
    }
    else{
        cout<<"Not Found\n";
    }
    // hash table 
    unordered_map<string ,int> Hash_Table;
    // add new pair like "map"
    Hash_Table["number"]=123;
    return 0;
}