#include<bits/stdc++.h>
using namespace std;
int main(){
    long long ll_num;
    scanf("%lld",&ll_num);
    printf("%lld\n",ll_num);
    double d=3.1415926535;
    scanf("%lf",&d);
    printf("%lf\n",d);
    printf("%.5lf\n",d); // 3.141593
    printf("%.1lf\n",d); // 3.1
    printf("%.0lf\n",d); // 3
    cout<<setprecision(5)<<d<<'\n';
    cout<<setprecision(2)<<d<<'\n';
    cout<<setprecision(0)<<d<<'\n';
    long double ld;
    scanf("%LF",&ld);
    printf("%LF\n",ld);
    return 0;
}