#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn=205;
const string out[]={" (TS simple cycle)", " (TS cycle)", " (Not a TS cycle)"};
int n,m,k;
int dis[maxn][maxn];
int ans,id,tmp;
int a,b,c;
bool flag,f;
int vis[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        dis[a][b]=dis[b][a]=c;
    }
    cin>>k;
    ans=1e9;
    for(int j=1;j<=k;j++){
        cout<<"Path "<<j<<": ";
        memset(vis,0,sizeof(vis));
        cin>>m;cin>>a;b=a;flag=f=false;tmp=0;vis[b]++;
        for(int i=2;i<=m;i++){
            cin>>c;vis[c]++;
            if(dis[b][c]==0){
                flag=true;//这里不可以break啊！！！！
            }
            tmp+=dis[b][c];
            b=c;
        }
        if(flag){
            cout<<"NA"<<out[2]<<'\n';
        }else{
            cout<<tmp;
            for(int i=1;i<=n;i++){
                if(i==a){
                    if(vis[i]==2) continue;
                    else if(vis[i]==1){
                        f=true;break;
                    }else{
                        flag=true;
                    }
                    continue;
                } 
                if(vis[i]==0){
                    f=true;break;
                }else if(vis[i]>1){
                    flag=true;
                }
            }
            if(b!=a) f=true;
            if(f){
                cout<<out[2]<<'\n';
            }else if(flag){
                if(ans>tmp){ans=tmp;id=j;}
                cout<<out[1]<<'\n';
            }else{
                if(ans>tmp){ans=tmp;id=j;}
                cout<<out[0]<<'\n';
            }
        }
    }
    cout<<"Shortest Dist("<<id<<") = "<<ans<<'\n';
    return 0;
}