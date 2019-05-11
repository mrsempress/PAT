#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=205;
bool edge[maxn][maxn];
int n,m,k;
int a,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;edge[a][b]=edge[b][a]=1;
    }
    cin>>k;
    while(k--){
        cin>>m;bool flag=false;int cnt=0;
        int vis[maxn]={0};cin>>a;vis[a]++;
        int f=a;
        for(int i=2;i<=m;i++){
            cin>>b;
            if(!edge[a][b]){
                flag=true;
            }
            vis[b]++;a=b;
        }
        if(!flag){
            for(int i=1;i<=n;i++){
                if(!vis[i]||vis[i]>2){
                    flag=true;break;
                }else if(vis[i]==2) cnt++;
            }
        }
        if(flag||cnt!=1||f!=a) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}