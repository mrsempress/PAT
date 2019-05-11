#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e4+10;
bool vis[maxn];
int n,m,a,b,c;
bool prime(int x){
    if(x<2) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    while(!prime(m)) m++;
    for(int i=1;i<=n;i++){
        cin>>a;c=-1;
        for(int j=0;j<m;j++){
            b=(a+j*j)%m;
            if(!vis[b]){
                vis[b]=1;c=b;break;
            }
        }
        if(i!=1) cout<<' ';
        if(c==-1) cout<<'-';
        else cout<<c; 
    }
    return 0;
}