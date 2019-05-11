/*
联通图哦connected graphs all vertices of even degree --Eulerian
two vertices of odd degree这里变奇数了！！！ --semi-Eulerian
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const string ans[]={"Eulerian", "Semi-Eulerian", "Non-Eulerian"};
int n,m;
int a,b;
int degree[600];
vector<int>edge[600];
bool vis[600];
void dfs(int x){
    vis[x]=1;
    int len=edge[x].size();
    for(int i=0;i<len;i++){
        if(!vis[edge[x][i]]){
            dfs(edge[x][i]);
        }
    }
}
bool check(){
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(!flag){
                dfs(i); flag=true;
            }else{
                return false;
            }
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        degree[a]++;degree[b]++;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int even=0;
    for(int i=1;i<=n;i++){
        if(degree[i]%2==0) even++;
        if(i==1) cout<<degree[i];
        else cout<<' '<<degree[i];
    }
    cout<<'\n';
    if(even==n&&check()){cout<<ans[0]<<'\n';}//第二个点
    else if((n-even)==2) {cout<<ans[1]<<'\n';}//第一个点
    else cout<<ans[2]<<'\n';
    return 0;
}