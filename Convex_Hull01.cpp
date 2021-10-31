#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int,int> P;
/*
    Convex Hull : Montone chain
    Check : https://zerojudge.tw/ShowProblem?problemid=b596
*/
int cross(P o,P a,P b){
    return (a.X-o.X)*(b.Y-o.Y) - (a.Y-o.Y)*(b.X-o.X);
}
int n;
void solve(){
    vector<P> arr(n),CH(n+5);
    for(auto &i:arr){
        cin>>i.X>>i.Y;
    }

    sort(arr.begin(),arr.end());
    int cnt=0;
    // Lower
    for(int i=0;i<n;i++){

        while(cnt>=2 && cross(CH[cnt-2],CH[cnt-1],arr[i])<=0 ){
            cnt--;
        }
        CH[cnt++]=arr[i];
    }
    // Upper , will not include added point but start point
    for(int i=n-2 , t=cnt+1 ;i>=0 ;i--){

        while(cnt>= t &&cross(CH[cnt-2],CH[cnt-1],arr[i])<=0){
            cnt--;
        }
        CH[cnt++]=arr[i];
    }
    cnt-- ; // start point = end point ,so minus 1

    cout<<cnt<<'\n';
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    while(cin>>n){
        if(!n) break;
        solve();
    }
    return 0;
}