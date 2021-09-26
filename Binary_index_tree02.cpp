#include<iostream>
using namespace std;
#define lowbit(x) x&-x
#define N 1005
/*
    2D Binary index tree
*/
int BIT[N][N];
// BIT[i][j]+=val, I1<=i<=I2, J1<=j<=J2
inline void Update(int I1,int J1,int I2,int J2,int val){
    for(int i=I1;i<=I2;i+=lowbit(i)){
        for(int j=J1;j<=J2;j+=lowbit(j)){
            BIT[i][j]+=val;
        }
    }
}
// Query from sum of BIT[i][j] 0<=i<=I, 0<=j<=J
inline int Query(int I,int J){
    int ret=0;
    for(int i=I;i;i-=lowbit(i)){
        for(int j=J;j;j-=lowbit(j)){
            ret+=BIT[i][j];
        }
    }
    return ret;
}

// Query from sum of BIT[i][j] I1<=i<=I2, J1<=j<=J2
inline int Query(int I1,int J1,int I2,int J2){
    return Query(I1-1,J1-1)-Query(I1-1,J2)-Query(I2,J1-1)+Query(I2,J2);
}
int main(){
    
    return 0;
}