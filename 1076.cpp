#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=1005;
vector<int>follwer[maxn];
queue<pair<int, int> > q;
bool vis[maxn];
int n,L,k;
int m,x;
pair<int,int>tmp;
int work(){
    int ans=0;
    q.push(make_pair(x,0));
    while(!q.empty()){
        tmp=q.front();q.pop();
        x=tmp.first;m=tmp.second;
        if(m==L) continue;
        int len=follwer[x].size();
        for(int i=0;i<len;i++){
            if(!vis[follwer[x][i]]){
                vis[follwer[x][i]]=1;
                q.push(make_pair(follwer[x][i],m+1));
                //cout<<ans<<" "<<follwer[x][i]<<endl;
                ans++;
            }
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>L;
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=1;j<=m;j++){
            cin>>x;follwer[x].push_back(i);
        }
    }
    cin>>k;
    while(k--){
        cin>>x;
        memset(vis,0,sizeof(vis));
        vis[x]=1;
        cout<<work()<<'\n';
    }
    return 0;
}



//比如对于一个点，因为深度优先遍历先便利到，但是由于深度的层数过大
//他的子结点就不可以加入了；但是实际上他的层次可以小一点，所以实际上
//他的孩子也可以加入其中，但是因为vis，就加不进去了
// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include <cstring>
// #include <set>
// #include <algorithm>
// using namespace std;
// const int maxn=1005;
// vector<int>follwer[maxn];
// // bool vis[maxn];
// set<int>vis;
// int n,L,k;
// int m,x;
// int work(int x,int layer){
//     if(layer>L) return 0;
//     int len=follwer[x].size();
//     //int sum=1;
//     for(int i=0;i<len;i++){
//         //cout<<x<<" "<<follwer[x][i]<<endl;
//         // if(!vis[follwer[x][i]]){
//         //     vis[follwer[x][i]]=1;
//         //     sum+=work(follwer[x][i],layer+1);
//         // }
//         if(vis.find(follwer[x][i])==vis.end()){
//             //cout<<follwer[x][i]<<endl;
//             vis.insert(follwer[x][i]);
//             work(follwer[x][i],layer+1);
//         }
//     }
//     //cout<<x<<' '<<layer<<' '<<sum<<endl;
//     //return sum;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n>>L;
//     for(int i=1;i<=n;i++){
//         cin>>m;
//         for(int j=1;j<=m;j++){
//             cin>>x;follwer[x].push_back(i);
//         }
//     }
//     cin>>k;
//     while(k--){
//         cin>>x;
//         //memset(vis,0,sizeof(vis));
//         vis.clear();
//         //cout<<work(x,0)-1<<'\n';
//         work(x,1);
//         cout<<vis.size()<<'\n';
//     }
//     return 0;
// }