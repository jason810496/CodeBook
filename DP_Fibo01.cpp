#include<iostream>
#include<vector>
using namespace std;
#define N 10005
#define ll long long
typedef vector<vector<ll> > mat;
/*
    DP : O(N) Fibonacci Button-up & Top-down
    Matrix + Fast power: O(LogN) Fibonacci 
*/
int DP[N];
void Fibo_N_buttom_up(){
    int n=100;
    DP[1]=1,DP[2]=1;
    for(int i=3;i<=n;i++){
        DP[i]=DP[i-1]+DP[i+2];
    }
}

int Top_down(int n){
    if(n==0 ||n==1) return DP[n]=1;
    if(DP[n]!=0) return DP[n];

    DP[n]=Top_down(n-1) + Top_down(n-2);
    return DP[n];
}

void Fibo_N_top_down(int n){

    cout<<Top_down(n);
}
mat Multiply(mat a,mat b){
    int n=a.size();
    mat temp(n,vector<ll>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                temp[i][j]+= a[i][k]*b[k][j];
            }
        }
    }
    return temp;
}

mat Fast_pow(int n,mat base){
    if(n==1) return base;

    if(n&1){
        return Multiply(base,Fast_pow(n-1,base));
    }
    else{
        mat temp=Fast_pow(n/2,base);
        return Multiply(temp,temp);
    }
}

void Fibo_LogN(){
    mat base(2,vector<ll>(2));
    base={
        {1,1},
        {1,0},
    };
    int n=100;
    mat F_N=Fast_pow(n,base);
    cout<<F_N[0][0]<<'\n';
}
int main(){
    Fibo_LogN();
    return 0;
}