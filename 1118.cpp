#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1e5+10;
int idtree[maxn];
int tot=0;
int n,q,k,x,t;
int f[maxn],cnt[maxn];
bool vis[maxn];
void init(){
    for(int i=0;i<maxn;i++){
        f[i]=i;
    }
}
int find(int x){
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
void merge(int a,int b){
    int c=find(a),d=find(b);
    if(c==d) return ;
    if(cnt[c]<cnt[d]){
        f[c]=d;
        cnt[d]+=cnt[c];
    }else{
        f[d]=c;cnt[c]+=cnt[d];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;init();
    for(int i=1;i<=n;i++){
        cin>>k;
        if(k==1){cin>>x;vis[x]=1;continue;}
        cin>>x;vis[x]=1;
        for(int j=2;j<=k;j++){
            cin>>t;vis[t]=1;
            merge(x,t);x=t;
        }
        // for(int j=0;j<maxn;j++){
        //     if(vis[j]){
        //         cout<<j<<" "<<find(j)<<endl;
        //     }
        // }
        // cout<<endl;
    }
    int ans1=0,ans2=0;
    for(int i=0;i<maxn;i++){
        if(vis[i]){
            ans2++;
            //cout<<i<< " "<<find(i)<<endl;
            if(find(i)==i){
                ans1++;
            }
        }
    }
    cout<<ans1<<' '<<ans2<<'\n';
    cin>>q;
    while(q--){
        cin>>x>>t;
        if(find(x)!=find(t)){cout<<"No\n";}
        else cout<<"Yes\n";
    }
    return 0;
}