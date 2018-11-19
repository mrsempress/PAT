/*
首先，最深的肯定在最深的叶子节点处，这些叶子节点肯定包含
但这样kennel会漏调，由叶子节点为根，之前作为分支的
比如，
    *
   / \
  *   *
 /
*

这样只会找到左下角的点，会忽略右下角的那个点
而至于为什么不可以找所有叶子结点
    * 
   /|\
  * * *
 /     \
*       *
中间的叶子节点就不可以
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1e4+10;
int n, maxheight = 0;
vector<int>v[maxn];
vector<int> temp;
bool vis[10010];
set<int> s;
set<int>::iterator it;
void dfs(int now, int height){
    if(height>maxheight){
        temp.clear();
        temp.push_back(now);
        maxheight = height;
    }else if(height==maxheight){
        temp.push_back(now);
    }
    vis[now] = true;
    for(int i=0;i<v[now].size();i++){
        if(vis[v[now][i]]==false)
            dfs(v[now][i],height+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,cnt=0,root=0;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,1);
            if(i==1){
                int len=temp.size();
                if(len!=0) root=temp[0];
                for(int j=0;j<len;j++)
                    s.insert(temp[j]);
            }
            cnt++;
        }
    }

    if(cnt>1){
        printf("Error: %d components", cnt);
    }else{
        temp.clear();
        maxheight=0;
        memset(vis,0,sizeof(vis));
        dfs(root,1);
        int len=temp.size();
        for(int i=0;i<len;i++){
            s.insert(temp[i]);
        }
        for(it=s.begin();it!=s.end();it++){
            cout<<(*it)<<'\n';
        }
    }
    return 0;
}