#include<iostream>
using namespace std;
const int MAX_Size = 1e5+5;
/*
    MAX Heap 
    build : O(n)
    insert : O(lgN)
    find max : O(1)
    delete max : O(lgN)
*/
int arr[MAX_Size],n;

void AdjustDown(int idx){
    int L_idx=idx<<1 , R_idx=idx<<1|1;
    // left child index , right child index 
    int max_idx; // index of max child element

    if(L_idx > n) return ; // no left child ( no right child as well )
    
    if( R_idx > n || arr[L_idx]>arr[R_idx] ){
        // (no right child) or (left child > right child )
        max_idx = L_idx;
    }
    else max_idx = R_idx;

    if(arr[idx ] < arr[max_idx]){ // adjust value 
        swap(arr[max_idx],arr[idx]);
        AdjustDown(max_idx); 
    }
}

void AdjustUp(int idx){
    int par_idx = idx>>1; // parent index 

    if( par_idx < 1) return ;// root case

    // value of current node > value of parent node
    if(arr[idx] > arr[par_idx] ){
        swap(arr[idx],arr[par_idx]);
        AdjustUp(par_idx);
    } 
}
void Build_Heap(){
    // n/2 -> index of last node with child  
    for(int i=n/2 ;i>=1 ;--i){
        AdjustDown(i);
    }
}

void Add(int val){
    arr[n++]=val;
    AdjustUp(n);
}

void DeleteMax(){
    arr[1]=arr[n--];
    AdjustDown(1);
}
int main(){
    // demo code
    srand(time(NULL));
    cin>>n;
    for(int i=1;i<=n;i++) arr[i]=rand()%100+1;
    for(int i=1;i<=n;i++) cout<<arr[i]<<' ';
    cout<<'\n';

    Build_Heap();

    while(n){
        // get max element ( root )
        cout<<arr[1]<<'\n';
        DeleteMax();
    }

    return 0;
}