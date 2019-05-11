#include <iostream>
#include <vector>
using namespace std;
const int maxn=1e4+10;
vector<pair<int,int> >v;
pair<int,int>tmp;
int x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>tmp.first>>tmp.second;
        v.push_back(tmp);
    }
    int k;int t;
    cin>>k;
    while(k--){
        cin>>t;
        bool vis[maxn]={0};
        for(int i=1;i<=t;i++){
            cin>>x;vis[x]=1;
        }
        bool flag=false;
        for(int i=0;i<m;i++){
            //cout<<v[i].first<<" "<<v[i].second<<" "<<!vis[v[i].first]<< " "<<!vis[v[i].second]<<endl;
            if(!vis[v[i].first]&&!vis[v[i].second]){
                flag=true;break;
            }
        }
        if(!flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}