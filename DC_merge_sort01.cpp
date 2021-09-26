#include<iostream>
using namespace std;

void Merge_sort(int *arr,int L,int R){
    if(R-L<=1) return; //bse case
    int M=(L+R)/2;
    Merge_sort(arr,L,M);
    Merge_sort(arr,M,R);
    int temp[R-L],j=M,cur=0 ;
    for(int i=L ; i<M ;i++){
        while(j<R && arr[j]<arr[i] ){
            temp[cur++]=arr[j++];
        }
        temp[cur++]= arr[i];
    }

    for(cur=L;cur<j ;cur++ ) arr[cur]=temp[ cur -L];
    return;
}
int main(){
    srand(time(NULL));
    int n=10,arr[10];
    for(int i=0;i<n;i++){
        arr[i]=rand()%10;
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    Merge_sort(arr,0,10);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    return 0;
}