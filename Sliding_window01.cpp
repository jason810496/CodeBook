#include<iostream>
#include<deque>
#define N 100005
using namespace std;

int n,K,arr[N];
deque<int > dq_min,dq_max;

// store index instead of the whole data (save more space)
void add_min(int i){
    // keep dq_min.front() is the smallest element in the window
    while(dq_min.size() && arr[dq_min.back()]>=arr[i] ){
        // if dq is not empty and the last element is bigger than the new element
        dq_min.pop_back();
    }
    // add new element
    dq_min.push_back(i);
}
void add_max(int i){
    // keep dq_max.front() is the biggest element in the window
    while(dq_max.size() && arr[dq_max.back()]<=arr[i] ){
        // if dq is not empty and the last element is smaller than the new element
        dq_max.pop_back();
    }
    // add new element
    dq_max.push_back(i);
}

void update(int i){
    // check if the arr[ dq.front() ] is out of window ,then pop front
    if (i-dq_min.front()>=K) dq_min.pop_front();
    if(i-dq_max.front()>=K ) dq_max.pop_front();
}
int main(){
    /*
        n: size of sequence
        K: window's length

        Max_dif = max difference of sequence in window at length of K
        Max_dif = max(arr[i]-arr[j]) , 1<= i,j <= n
    */
    cin>>n>>K;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int Max_dif=INT32_MIN, cur_dif;

    for(int i=1;i<=n;i++){
        update(i);
        add_min(i);
        add_max(i);

        cur_dif= arr[dq_max.front()]-arr[dq_min.front()];
        Max_dif= max(Max_dif ,cur_dif);
    }

    cout<<Max_dif;
    return 0;
}