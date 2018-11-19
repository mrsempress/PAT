#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;
const int maxn=505;
int Cmax,Cavg,Sp,N,M,x,yy,z;
bool vis[maxn];
int S[maxn];
int dis[maxn][maxn];
int ans_dis,ans_send,ans_back;
string ans_path;
void dfs(int now,int dist,int send,int back,string path){
    if(dist>ans_dis||(dist==ans_dis&&now!=Sp)) return ;
    if(now==Sp){
        if(dist<ans_dis||(dist==ans_dis
                          &&(send<ans_send||(send==ans_send
                                             &&back<ans_back)))){
            ans_dis=dist;
            ans_send=send;
            ans_back=back;
            ans_path=path;
        }
        return ;
    }
    for(int i=1;i<=N;i++){
        if(!vis[i]&&dis[i][now]!=-1){
            vis[i]=1;
            if(S[i]<=Cavg){
                int tmp=min(back,Cavg-S[i]);
                dfs(i,dist+dis[i][now],send+(Cavg-S[i]-tmp),back-tmp,path+"->"+to_string(i));
            }
            else
                dfs(i,dist+dis[i][now],send,back+(S[i]-Cavg),path+"->"+to_string(i));
            vis[i]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>Cmax>>N>>Sp>>M;
    Cavg=Cmax/2;ans_dis=INT_MAX;
    for(int i=1;i<=N;i++) cin>>S[i];
    memset(dis,-1,sizeof(dis));
    for(int i=1;i<=M;i++){
        cin>>x>>yy>>z;
        dis[x][yy]=dis[yy][x]=z;
    }
    dfs(0,0,0,0,"0");
    cout<<ans_send<<' '<<ans_path<<' '<<ans_back<<'\n';
    return 0;
}
