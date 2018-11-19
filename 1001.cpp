#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int one = 1e6;
const int two = 1e3;
int main(){
    int a,b;
    cin>>a>>b;
    a=a+b;
    if(a>=one||a<=-one){
        printf("%d,%03d,%03d\n",a/one,abs(a)%one/two,abs(a)%two);
    }
    else if(a>=two||a<=-two){
        printf("%d,%03d\n",a/two,abs(a)%two);
    }else{
        printf("%d\n",a);
    }
    return 0;
}