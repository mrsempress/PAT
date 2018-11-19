#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1005;
int n,m,k;
bool connected[maxn][maxn];
bool vis[maxn];
int x,y,loss;
int ans[maxn];
void dfs(int z){
    for(int i=1;i<=n;i++){
        if(i==loss) continue;
        if(!vis[i]&&connected[i][z]){
            vis[i]=1;
            dfs(i);
        }
    }
}

int work(){
    memset(vis,0,sizeof(vis));
    int num=0;
    for(int i=1;i<=n;i++){
        if(i==loss) continue;
        if(!vis[i]){
            num++;
            vis[i]=1;
            dfs(i);
        }
    }
    ans[loss]=num-1;
    return num-1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        connected[x][y]=connected[y][x]=1;
    }
    while(k--){
        cin>>loss;
        if(ans[loss])cout<<ans[loss]<<endl;
        else cout<<work()<<endl;
    }
    return 0;
}