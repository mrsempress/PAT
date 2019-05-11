#include <iostream>
#include <string>
using namespace std;
struct ty{
    string now;
    int l,r;
}node[100];
bool vis[100];
int n;
void dfs(int root){
    if(node[root].l==-1&&node[root].r==-1){
        cout<<node[root].now; return ;
    }
    cout<<'(';
    if(node[root].l!=-1)dfs(node[root].l);
    cout<<node[root].now;
    if(node[root].r!=-1)dfs(node[root].r);
    cout<<')';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>node[i].now>>node[i].l>>node[i].r;
        if(node[i].l!=-1) vis[node[i].l]=1;
        if(node[i].r!=-1) vis[node[i].r]=1;
    } 
    for(int i=1;i<=n;i++){
        if(!vis[i]) {
            if(node[i].l!=-1)
            dfs(node[i].l);
            cout<<node[i].now;
            if(node[i].r!=-1)
            dfs(node[i].r);
            break;
        }
    }
    return 0;
}