#include <cstdio>
#include <iostream>
using namespace std;
int a,b,c,d,e,f;
int A,B,C;
const int maxn=1e7+1;
int main(){
    scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&d,&e,&f);
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
    C=(c+f)%29;
    B=(b+e+(c+f)/29)%17;
    A=((b+e+(c+f)/29)/17+a+d);
    printf("%d.%d.%d\n",A,B,C);
    return 0;
}