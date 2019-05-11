#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=205;
const int maxx=1e4+10;
int color[maxn];
int pos[maxn];
int order[maxn];
int dp[maxx];
int n,m,L,ans,x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>order[i];
        pos[order[i]]=i;
    } 
    cin>>L;
    for(int i=1;i<=L;i++){
        cin>>x;
        for(int j=pos[x];j>=1;j--){
            dp[i]=max(dp[i],color[order[j]]+1);
        }
        color[x]=dp[i];
    }
    for(int i=1;i<=n;i++) ans=max(ans,color[i]);
    cout<<ans<<'\n';
    return 0;
}