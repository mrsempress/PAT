#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=1005;
int n,m,k,s,e,len;
bool vis[maxn];
vector<int>pre[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    // cout<<n<<" "<<m<<endl;
    for(int i=1;i<=m;i++){
        cin>>s>>e;
        // cout<<s<<" "<<e<<endl;
        pre[e].push_back(s);
    }
    cin>>k;bool flag=false;bool f=false;
    for(int K=0;K<k;K++){
        flag=false;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            cin>>e;
            vis[e]=1;
            // cout<<"e: "<<e<<endl;
            len=pre[e].size();
            for(int j=0;j<len&&!flag;j++){
                if(vis[pre[e][j]]==0){
                    flag=true;
                }
            }
        }
        if(flag){
            if(!f) {cout<<K;f=true;}
            else cout<<' '<<K;
        }
    }
    cout<<'\n';
    return 0;
}