#include <iostream>
#include <iomanip>
#include <set>
using namespace std;
const int maxn=1e5+10;
int d[maxn];
bool vis[maxn];
int x[10005];
int n,m;
int a,b;
set<int>ans;
set<int>::iterator it;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        d[a]=b;d[b]=a;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>x[i];
        vis[x[i]]=1;
    }
    for(int i=1;i<=m;i++){
        if(!vis[d[x[i]]]) ans.insert(x[i]);
    }
    cout<<ans.size()<<'\n';
    if(!ans.size()) return 0;
    it=ans.begin();cout<<setfill('0')<<setw(5)<<(*it);
    for(it++;it!=ans.end();it++){
        cout<<' '<<setfill('0')<<setw(5)<<(*it);
    }
    cout<<'\n';
    return 0;
}