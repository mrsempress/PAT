#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const int maxn=1e4+10;
int pre[maxn],in[maxn];
map<int,int>pos;
int n,m;
void LCA(int l,int r,int L,int R,int u,int v){
    int root=pre[L];
    if(root==u){
        cout<<u<<" is an ancestor of "<<v<<".\n";
        return ;
    }
    if(root==v){
        cout<<v<<" is an ancestor of "<<u<<".\n";
        return ;
    }
    int idroot=pos[root],idu=pos[u],idv=pos[v];
    if(idu<idroot&&idv<idroot){
        LCA(l,idroot-1,L+1,L+idroot-l,u,v);
    }else if(idu>idroot&&idv>idroot){
        LCA(idroot+1,r,R-r+idroot+1,R,u,v);
    }else{
        cout<<"LCA of "<<u<<" and "<<v<<" is "<<root<<".\n";//忘记点了！！！！
    }
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>in[i];
        pos[in[i]]=i;//这个很棒呢，就不用每次寻找位置了
    }
    for(int i=1;i<=n;i++) cin>>pre[i];
    int a,b;
    while(m--){
        cin>>a>>b;
        if(!pos[a]&&!pos[b]){
            cout<<"ERROR: "<<a<<" and "<<b<<" are not found.\n";
        }else if(!pos[a]){
            cout<<"ERROR: "<<a<<" is not found.\n";
        }else if(!pos[b]){
            cout<<"ERROR: "<<b<<" is not found.\n";
        }else{
            LCA(1,n,1,n,a,b);
        }
    }
    return 0;
}