#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int k,n;
int d[1005];bool flag;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k;
    while(k--){
        cin>>n;
        bool vis[1005]={0};flag=false;
        bool v[100005]={0};
        for(int i=1;i<=n;i++){
            cin>>d[i];
            if(vis[d[i]]==1) flag=true;
            if(v[d[i]+i]==1) flag=true;
            if(v[d[i]-i+5000]==1) flag=true;
            vis[d[i]]=v[d[i]+i]=v[d[i]-i+5000]=1;
        }
        if(flag){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
    return 0;
}