#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int maxn=1e5+10;
struct ty{
    char c;
    int nex;
}node[maxn];
int one,two;
int n,x;
bool vis[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>one>>two>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        cin>>node[x].c>>node[x].nex;
    }
    x=one;
    while(x!=-1){
        vis[x]=1;
        x=node[x].nex;
    }
    x=two;
    int ans=two;
    while(x!=-1){
        if(!vis[x]){
            ans=node[x].nex;
        }
        x=node[x].nex;
    }
    if(ans==-1) cout<<"-1\n";
    else cout<<setfill('0')<<setw(5)<<ans<<'\n';
    return 0;
}