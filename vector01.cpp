#include<iostream>
#include<vector>
using namespace std;

int main(){
    int Vector_Size=10;
    // Initialize vec01 
    vector<int > vec01;

    // Initialize vec02 of size 10
    vector<int > ve0c02( Vector_Size);

    // Initialize vec03 of size 10 with value
    vector<double > vec03( Vector_Size, 3.14);

    // 2D vector
    vector< vector<int> > vec_2D;
    // resize 2D vector using iterator
    vec_2D.resize(Vector_Size);
    // using iterator loop through vector
    for(vector<vector<int> >::iterator it=vec_2D.begin(); it!=vec_2D.end() ;it++){
        (*it).resize(Vector_Size);
    }
    // resize 2D vector by index
    for(int i=0;i<Vector_Size;i++){
        vec_2D[i].resize(Vector_Size);
    }
    // Using constructor initialize 2D vector size
    vector<vector<int> > vec_2D_2(Vector_Size,vector<int>(Vector_Size) );

    // for range 
    for(auto i:vec01){
        cout<<i<<'\n';
    }

    // pass by reference
    for(auto &i:vec01){
        cin>>i;
    }

    for(auto i:vec01){
        cin>>i;
        //value won't change
    }
    // like normal array
    for(int i=0;i<10;i++){
        cout<<vec01[i]<<' ';
    }
    
    // add new element
    vec01.push_back(100);
    // pop out last element
    vec01.pop_back();
    // get current vector size
    vec01.size();
    return 0;
}
