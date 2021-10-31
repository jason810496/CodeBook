#include<bits/stdc++.h>
using namespace std;
#define MAX_N 105
#define range(x) x.begin(),x.end()
typedef vector<int> NUM;
// unsigned Big int
/*  Big int 
    check : https://zerojudge.tw/ShowProblem?problemid=c874
*/
NUM IN(string str){
    NUM ret(MAX_N);
    int n=str.size();
    for(int i=0;i<n;i++){
        ret[i]=str[n-i-1]-'0';
    }
    return ret;
}

NUM IN(int x){
    NUM ret(MAX_N);
    int i=0;
    while(x){
        ret[i++]=x%10;
        x/=10;
    }
    return ret;
}

void Print(NUM x){
    int i=MAX_N-1;
    while(i>=0 && x[i]==0) i--;

    if(i<0) cout<<'0';
    else{
        while(i>=0 ) cout<<x[i--];
    }
}

bool less_than(NUM a,NUM b){ // a< b
    for(int i=MAX_N-1 ;i>=0 ;i--){
        if(a[i]!=b[i]) return a[i]<b[i];
    }
    return false; // same
}

NUM Add(NUM a,NUM b){
    NUM ret(MAX_N);
    for(int i=0;i<MAX_N;i++){
        ret[i]=a[i]+b[i];
    }
    // carry
    for(int i=0;i<MAX_N-1 ;i++){
        ret[i+1]+=ret[i]/10;
        ret[i]%=10;
    }
}

NUM Subtract(NUM a,NUM b){ // a-b
    NUM ret(MAX_N);
    for(int i=0;i<MAX_N;i++){
        ret[i]=a[i]-b[i];
    }
    for(int i=0;i<MAX_N-1;i++){
        if(ret[i]<0){
            ret[i+1]--;
            ret[i]+=10;
        }
    }
    return ret;
}

NUM mul(const NUM &a,const NUM &b){
    NUM ret(MAX_N,0);

    for(int i=0;i<MAX_N;i++){
        for(int j=0;j<MAX_N;j++){
            if(i+j < MAX_N){
                ret[i+j]+=a[i]*b[j];
            }
        }
    }

    for(int i=0;i<MAX_N-1;i++){
        ret[i+1]+=ret[i]/10;
        ret[i]%=10;
    }

    return ret;
}

NUM mul(NUM a,int k){
    for(int i=0;i<MAX_N;i++){
        a[i]*=k;
    }
    for(int i=0;i<MAX_N-1;i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    return a;
}

// BUG
NUM Divide(NUM a,NUM b){  // a/b
    NUM ret;
    int Idx=0;
    for(int i=MAX_N-1 ;i>=0 ;i--){
        for(int k=9;k>0;k--){// try diviser
            NUM temp=mul(b,k);

            if(!less_than(a,temp)){
                ret.push_back(k);
                a=Subtract(a,temp);
                break;
            }
        }
    }
    reverse(range(ret));
    while(ret.size()<100) ret.push_back(0);
    return ret;
}

NUM Divide(NUM a,int k){
    int r=0;
    NUM ret(MAX_N);
    for(int i=MAX_N-1;i>0;i--){
        r=r*10 + a[i];
        ret[i]=r/k;
        r%=k;
    }

    return ret;
}
int main(){
    string str_a,str_b,oper;
    while(cin>>str_a>>oper>>str_b){
        NUM A=IN(str_a) , B=IN(str_b);
        if(oper=="*"){
            Print(mul(A,B));
        }
        else{
            Print(Divide(IN(str_a),IN(str_b)));
        }
        cout<<'\n';
    }

    // cin>>str_a>>str_b;
    // NUM A=IN(str_a) ;
    // NUM B=IN(str_b);
    // Print(A); cout<<"\n";
    // Print(B); cout<<"\n";
    // Print(mul(A,B));
    
    return 0;
}