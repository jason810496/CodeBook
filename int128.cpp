#include<bits/stdc++.h>
using namespace std;

inline __int128_t read(){
    __int128_t x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch==-1) f=-1;
        ch=getchar();
    }

    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

inline void Print(__int128_t x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) Print(x/10);
    
    putchar(x%10+'0');
}

__int128_t Pow(__int128_t x,int n){
    if(n==0) return (__int128_t)1;
    if(n%2==0 ) {
        __int128_t temp=Pow(x,n/2);
        return temp*temp;
    }
    return x*Pow(x,n-1);
}
int main(){
    int n;
    cin>>n;
    __int128_t ans=( (__int128_t)-Pow(4,n) )/(__int128_t)(-3);
    Print(ans); 
    return 0;
}