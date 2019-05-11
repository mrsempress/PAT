#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
const int INF=1e9+10;
map<string,int>name;
vector<int>ans,tmp;
int edge[250][250];
int h[250];
int anscost,anslen,anshappy,ansnum;
bool vis[250];
int rom;
int n,k,x;
string s,na,nb;
string rname[250];
void dfs(int now,int cost,int len,int happy){
    if(cost>anscost) return ;
    if(now==rom&&cost==anscost) ansnum++;
    if(cost==anscost&&(happy<anshappy||(happy==anshappy&&len>anslen))) return ;
    if(now==rom){
        if(anscost!=cost) ansnum=1;
        anscost=cost;anshappy=happy;anslen=len;
        ans=tmp;return ;
    }
    for(int i=2;i<=n;i++){
        if(!vis[i]&&edge[now][i]){
            vis[i]=1;
            tmp.push_back(i);
            dfs(i,cost+edge[now][i],len+1,happy+h[i]);
            tmp.pop_back();
            vis[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>s;name[s]=1;rname[1]=s;
    for(int i=2;i<=n;i++){
        cin>>na;name[na]=i;cin>>h[i];
        if(na=="ROM") rom=i;
        rname[i]=na;
    }
    for(int i=1;i<=k;i++){
        cin>>na>>nb>>x;
        edge[name[na]][name[nb]]=edge[name[nb]][name[na]]=x;
    }
    anscost=anslen=INF;anshappy=ansnum=0;
    dfs(name[s],0,0,0);
    cout<<ansnum<<' '<<anscost<<' '<<anshappy<<' '<<anshappy/anslen<<'\n';
    cout<<s;
    for(int i=0;i<anslen;i++){
        cout<<"->"<<rname[ans[i]];
    }
    cout<<'\n';
    return 0;
}