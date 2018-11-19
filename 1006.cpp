#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int maxn=1e6+10;
struct Time{
    int h,m,s;
    bool operator<(const Time& o)const{
        if(h==o.h){
            if(m==o.m) return s<o.s;
            else return m<o.m;
        }else return h<o.h;
    }
};

struct ty{
    string name_in,name_out;
    Time in;
    Time out;
}man,two;
int n;
string x,y;

int main(){
    cin>>n;
    cin>>man.name_in>>x>>y;
    man.in.h=(x[0]-'0')*10+(x[1]-'0');
    man.in.m=(x[3]-'0')*10+(x[4]-'0');
    man.in.s=(x[6]-'0')*10+(x[7]-'0');

    man.out.h=(y[0]-'0')*10+(y[1]-'0');
    man.out.m=(y[3]-'0')*10+(y[4]-'0');
    man.out.s=(y[6]-'0')*10+(y[7]-'0');
    man.name_out=man.name_in;

    for(int i=1;i<n;i++){
        cin>>two.name_in>>x>>y;
        two.in.h=(x[0]-'0')*10+(x[1]-'0');
        two.in.m=(x[3]-'0')*10+(x[4]-'0');
        two.in.s=(x[6]-'0')*10+(x[7]-'0');

        two.out.h=(y[0]-'0')*10+(y[1]-'0');
        two.out.m=(y[3]-'0')*10+(y[4]-'0');
        two.out.s=(y[6]-'0')*10+(y[7]-'0');
        
        if(two.in<man.in){
            man.in.h=two.in.h;
            man.in.m=two.in.m;
            man.in.s=two.in.s;
            man.name_in=two.name_in;
        }
        if(!(two.out<man.out)){
            man.out.h=two.out.h;
            man.out.m=two.out.m;
            man.out.s=two.out.s;
            man.name_out=two.name_in;
        }
    }
    
    cout<<man.name_in<< " "<<man.name_out<<endl;
    return 0;
}