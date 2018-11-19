#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
bool isleaf[105];//是否作为别人的孩子过
bool vis[105];//编号是否用过
vector<int>tree[105];//存储它的孩子的节点
int layers[105];//每个节点的叶子的个数
int n,m;
int father,k,son;
int root;
int max_layer=0;
void dfs(int now,int layer){
    max_layer=max(layer,max_layer);
    int len=tree[now].size();
    if(!len){
        layers[layer]++;
        return ;
    }
    for(int i=0;i<len;i++){
        dfs(tree[now][i],layer+1);
    }
    return ;
}

int main(){
    cin>>n>>m;
    while(m--){
        cin>>father>>k;
        vis[father]=1;
        while(k--){
            cin>>son;
            tree[father].push_back(son);
            isleaf[son]=1;vis[son]=1;
        }
    }
    for(int i=0;i<100;i++){
        if(vis[i]&&!isleaf[i]){
            root=i;
            break;
        }
    }

    dfs(root,1);
    for(int i=1;i<max_layer;i++){
        cout<<layers[i]<<" ";
    }
    cout<<layers[max_layer]<<endl;
    return 0;
}