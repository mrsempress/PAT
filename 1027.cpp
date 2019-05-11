#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
int r,g,b;
void work(int x){
    int yy;
    char z,_z;

    yy=x%13;
    if(yy>=10) z=yy-10+'A';
    else z=yy+'0';

    x/=13;
    if(x>=10) _z=x-10+'A';
    else _z=x+'0';
    cout<<_z<<z;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>r>>g>>b;
    cout<<'#';
    work(r);work(g);work(b);
    cout<<'\n';
    return 0;
}