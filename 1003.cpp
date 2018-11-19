#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cstdlib>
using namespace std;
int dist[505][505];
int teams[505];
int ans_paths=INT_MAX,ans_teams=0,cnt=0;
int n,m,c1,c2;
int s,e,L;
bool vis[505];
void dfs(int from,int to,int dis,int team){
    if(dis>ans_paths) return ;
    if(from == to){
        if(dis==ans_paths){
            cnt++;
            ans_teams=max(ans_teams,team);
        }
        else if(dis<ans_paths){
            cnt=1;
            ans_paths=dis;ans_teams=team;
        }
        return ;
    }

    for(int i=0;i<n;i++){
        if(!vis[i]&&dist[from][i]!=-1){
            vis[i]=1;
            dfs(i,to,dis+dist[from][i],team+teams[i]);
            vis[i]=0;
        }
    }
}

int main(){
    memset(dist,-1,sizeof(dist));
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>c1>>c2;
    for(int i=0;i<n;i++) cin>>teams[i];
    while(m--){
        cin>>s>>e>>L;
        if(dist[s][e]==-1) dist[s][e]=dist[e][s]=L;
        else dist[e][s]=dist[s][e]=min(dist[s][e],L);
    }
    dfs(c1,c2,0,teams[c1]);
    cout<<cnt<<' '<<ans_teams<<endl;
    return 0;
}