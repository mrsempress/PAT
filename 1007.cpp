#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll sum,tmp=0;
int s,e,x,s1,e1,a,b;
int n;
int main(){
    cin>>n;
    if(!n) return 0;
    cin>>sum;s=e=tmp=s1=e1=a=b=sum;
    bool flag=true;
    if(sum>=0) flag=false;
    for(int i=1;i<n;i++){
        cin>>x;b=x;
        if(x>=0) flag=false;
        if(tmp<0){
            s1=e1=tmp=x;
        }else{
            e1=x;tmp+=x;
        }
        if(sum<tmp){
            sum=tmp;
            s=s1;e=e1;
        }
    }
    if(flag){
        cout<<0<< " "<<a<<" "<<b<<endl;
        return 0;
    }
    cout<<sum<<" "<<s<<" "<<e<<endl;
    return 0;
}