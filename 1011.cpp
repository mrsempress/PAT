#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    double x,y,z;
    double ans=1;
    for(int i=0;i<3;i++){
        cin>>x>>y>>z;
        if(x>y&&x>z) cout<<"W"<<" ";
        else if(y>x&&y>z) cout<<"T"<<" ";
        else cout<<"L ";
        ans*=max(x,max(y,z));
    }
    ans=(ans*0.65-1)*2;
    printf("%.2lf\n",ans);
    return 0;
}