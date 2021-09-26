#include<iostream>
using namespace std;
#define N 10005
int n,arr[N],length[N],Last[N],lis[N];
/*
    Longest Increasing Subquence :

    O ( N^2)

*/
void Print_LIS(int pos){
    int len = length[pos];
    for (int i=pos; i!=-1 ;i=Last[i]){
        lis[--len]=arr[i];
    }

    for(int i=0,n=length[pos] ;i<n;i++){
        cout<<lis[i]<<' ';
    }
}
void LIS(){

    for(int i=0;i<n;i++) length[i]=1, Last[i]=-1;

    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){
            if( arr[i] < arr[j]){// current > last
                
                if(length[i]+1 > length[j]){
                    length[j]= length[i]+1;
                    Last[j] =i;
                }
            }
        }
    }

    int len=0,pos=0;
    for(int i=0;i<n;i++ ){
        if(length[i]> len){
            len=length[i];
            pos=i;
        }
    }
    cout<<"LIS length : "<<len<<'\n';
    Print_LIS(pos);
}

int main(){
    int data[]={ 1,3,2,4,5,7,10,6,9,11};
    n=10;
    for(int i=0;i<n;i++ ) arr[i]=data[i];
    LIS();
    return 0;
}