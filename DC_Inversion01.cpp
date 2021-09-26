#include<iostream>
using namespace std;

int Inversion(int *arr,int L,int R){
    if(R-L<=1 ) return 0;
    int M=(L+R)/2;
    int Sum=Inversion(arr,L,M)+Inversion(arr,M,R);
    int temp[R-L] , j=M , cur=0 , inv=0;
    for(int i=L;i<M;i++){
        while( j<R && arr[j]<arr[i] ){
            temp[cur++]=arr[j++];
        }
        temp[cur++]= arr[i];
        inv+=j-M; // cur inversion 
    }

    for(int i=L ;i<j;i++){
        arr[i]=temp[i-L];
    }
    return Sum+inv;
}
int main(){
    int n=9,arr[]={2,7,3,5,1,8,3,4,6};
    cout<<Inversion(arr,0,n);
    return 0;
}