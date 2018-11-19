/*
因为余数可能在1e9范围中，不可以用char表示的
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int n,b;
int orign[1000005];
int main(){
    cin>>n>>b;
    if(n==0){
        cout<<"Yes\n0\n";
        return 0;
    }
    int cnt=0;
    while(n){
        orign[cnt++]=n%b;
        n/=b;
    }
    bool flag=false;
    int x=cnt-1,y=0;
    while(x>y){
        if(orign[x]!=orign[y]){
            flag=true;
        }
        x--;y++;
    }
    if(!flag) cout<<"Yes\n";
    else cout<<"No\n";
    for(int i=cnt-1;i>0;i--){
        cout<<orign[i]<<' ';
    }
    cout<<orign[0]<<'\n';
    return 0;
}