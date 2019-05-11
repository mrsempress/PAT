#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int vis[1005];
int n,m,x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {cin>>a[i]; if(a[i]<=1000) vis[a[i]]++;}
    bool flag=false;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]>1000||a[i]>m) break;
        if(m-a[i]>1000) continue;
        // cout<<a[i]<<" "<<m-a[i]<<'\n';
        if(a[i]==m-a[i]&&vis[a[i]]>=2){
            flag=true;
            cout<<a[i]<<' '<<m-a[i]<<'\n';
            break;
        }
        if(a[i]!=m-a[i]&&vis[m-a[i]]){
            flag=true;
            cout<<a[i]<<' '<<m-a[i]<<'\n';
            break;
        }
    }
    if(!flag) cout<<"No Solution\n";
    return 0;
}