#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct ty{
    int l,r;
}node[15];
int n,x;
string a,b;
queue<int>q;
vector<int>ans;
bool vis[15];
int to_int(string x){
    int len=x.length();
    int tmp=0;
    for(int i=0;i<len;i++){
        tmp*=10;tmp+=x[i]-'0';
    }
    return tmp;
}
void levelorder(int root){
    q.push(root);cout<<root;
    while(!q.empty()){
        x=q.front();q.pop();
        if(node[x].r!=-1){
            cout<<' '<<node[x].r;q.push(node[x].r);
        }
        if(node[x].l!=-1){
            cout<<' '<<node[x].l;q.push(node[x].l);
        }
    }
    cout<<'\n';
}
void dfs(int now){
    if(node[now].r!=-1) dfs(node[now].r);
    ans.push_back(now);
    if(node[now].l!=-1) dfs(node[now].l);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a=="-") node[i].l=-1;
        else{
            x=to_int(a);
            node[i].l=x;vis[x]=1;
        }
        if(b=="-") node[i].r=-1;
        else{
            x=to_int(b);
            node[i].r=x;vis[x]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            levelorder(i);
            dfs(i);break;
        }
    }
    for(int i=0;i<n;i++){
        if(!i) cout<<ans[i];
        else cout<<' '<<ans[i];
    }
    cout<<'\n';
    return 0;
}   