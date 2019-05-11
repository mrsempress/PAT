//需要单独的diss数组记录，不然会因为更新了dist，而不知道具体的路径
//会跳过中间的节点，注意if(dist[i][nex]!=INF)这句话，否则，会使得爆int
//考前还是要看看Dijkstra的
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=510;
const int INF=0x3f3f3f3f;
int dist[maxn][maxn];
int cost[maxn][maxn];
int diss[maxn];
bool vis[maxn];
vector<int>pre[maxn];
vector<int>path,ans;
int n,m,s,d;
int x,yy,z,w;
int min_cost=INF;
void dijkstra(){
    int num=1;
    diss[s]=0;
    while(num<=n){
        int nex=-1,nex_dist=INF;
        for(int i=0;i<n;i++){
            if(!vis[i]&&diss[i]<nex_dist){
                nex_dist=diss[i];
                nex=i;
            }
        }
        if(nex==-1) break;
        vis[nex]=1;
        for(int i=0;i<n;i++){
            if(dist[i][nex]!=INF){
//                cout<<diss[i]<<' '<<diss[nex]<<' '<<dist[i][nex]<<endl;
                if(!vis[i]&&diss[i]>diss[nex]+dist[nex][i]){
                    diss[i]=diss[nex]+dist[nex][i];
//                    cout<<"new: "<<i<<" "<<nex<<endl;
                    pre[i].clear();
                    pre[i].push_back(nex);
                }else if(!vis[i]&&diss[i]==diss[nex]+dist[nex][i]){
//                    cout<<"     "<<i<<" "<<nex<<endl;
                    pre[i].push_back(nex);
                }
            }
        }
        
        num++;
    }
}

void dfs(int now){
    path.push_back(now);
    if(now==s){
        int sum=0,len=path.size();
        for(int i=0;i<len-1;i++){
            x=path[i];yy=path[i+1];
            sum+=cost[x][yy];
        }
        if(min_cost>sum){
            min_cost=sum;
            ans=path;
        }
        return ;
    }
    int len=pre[now].size();
    for(int i=0;i<len;i++){
        dfs(pre[now][i]);
        path.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dist,INF,sizeof(dist));
    memset(diss,INF,sizeof(diss));
    memset(cost,INF,sizeof(cost));
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>s>>d;
    for(int i=0;i<m;i++){
        cin>>x>>yy>>z>>w;
        if(dist[x][yy]>z||(dist[x][yy]==z&&w<cost[x][yy])){
            dist[x][yy]=dist[yy][x]=z;
            cost[x][yy]=cost[yy][x]=w;
        }
    }
    dijkstra();
    dfs(d);
    int len=ans.size();
    for(int i=len-1;i>=0;i--)
        cout<<ans[i]<<' ';
    cout<<diss[d]<<' '<<min_cost<<'\n';
    return 0;
}
