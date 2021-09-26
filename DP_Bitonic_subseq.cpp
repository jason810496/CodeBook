#include<bits/stdc++.h>
using namespace std;
/*
    DP : Longest Bitonic Subsequence
    a subsequence of arr[] is called Bitonic if it is first increasing, then decreasing
    (variation of standard Longest Increasing Subsequence (LIS) problem. )

    LIS : longest increasing subsequence
    LDS : longest decreasing subsequence
    LBS : LIS[i]+LDS[i]-1;
*/
const int MAX_Size = 105;
int n,seq[MAX_Size],LIS[MAX_Size],LDS[MAX_Size];
int main(){
    srand(time(NULL));
    // demo 
    vector<int> lis,lds;
    n=20;
    for(int i=1;i<=20;i++){
        seq[i]=rand()%30+1;
        cout<<seq[i]<<' ';
    }
    // cin>>n;
    // for(int i=1;i<=n;i++) cin>>seq[i];

    // LIS
    for(int i=1;i<=n;i++){
        auto it = lower_bound(lis.begin(),lis.end(),seq[i]);
        if(it==lis.end() ) lis.push_back( seq[i] );
        else *it=seq[i];

        LIS[i]=lis.size() ;
    }
    // LDS
    for(int i=n;i>0;i--){
        auto it = lower_bound(lds.begin(),lds.end(),seq[i]);
        if(it==lds.end() ) lds.push_back( seq[i] ) ;
        else *it=seq[i];

        LDS[i]=lds.size();
    }

    // the following can be combine to Loop of computing LDS
    int Mx=0;
    for(int i=1;i<=n;i++){
        // lis[i]=1 or lds[i]=1 can't be LBS
        if( i==1 || i==n || LIS[i]==1 ||LDS[i]==1 ) continue;

        Mx=max(Mx,LIS[i]+LDS[i]-1); 
    }

    cout<<Mx<<'\n';

    for(int i=1;i<=n;i++){
        cout<<LIS[i]<<' ';
    }
    cout<<'\n';
    for(int i=1;i<=n;i++){
        cout<<LDS[i]<<' ';
    }
    cout<<'\n';
    return 0;
}