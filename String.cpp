#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    str.substr(1,3); //[1,3]
    str="dog:cat";

    int pos=str.find(":");
    string sub = str.substr(pos+1); //[pos+1,str_end]

    sub=str.substr(0,pos) ; //[0,pos-1];
    return 0;   
}