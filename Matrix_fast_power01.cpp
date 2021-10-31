#include<bits/stdc++.h>
using namespace std;
#define ll long long 
typedef vector<vector<long long > > Mat;
ll MOD = 1000000007;
Mat mul(Mat a,Mat b){
    Mat ret(2,vector<ll>(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                ret[i][j]=(ret[i][j]+ (a[i][k]*b[k][j])%MOD )%MOD;
            }
        }
    }
    return ret;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n;
    Mat Init={{0,1},{1,1}};
    while(cin>>n && n!=-1){
        Mat base=Init,ret={{1,0},{1,0}};
        n--;
        while(n){
            if(n&1){
                ret=mul(base,ret);
            }
            base=mul(base,base);
            n>>=1;
        }
        cout<<ret[0][0]<<'\n';
    }
    return 0;
}