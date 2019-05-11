#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e3+5;
struct ty{
    int key;
    int l,r;
}node[maxn];
int n,tot,a;
int cnt[maxn];
void build(int now,int x,int f,bool left,int layer){
    if(now==-1){
        node[++tot].key=x;node[tot].l=node[tot].r=-1;
        if(left) node[f].l=tot;
        else node[f].r=tot;
        cnt[layer]++;
        return ;
    }
    if(x<=node[now].key){
        build(node[now].l,x,now,1,layer+1);
    }else{
        build(node[now].r,x,now,0,layer+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;cin>>a;
    node[++tot].key=a;node[tot].l=node[tot].r=-1;cnt[1]=1;
    for(int i=2;i<=n;i++){
        cin>>a;
        build(1,a,0,0,1);
    }
    if(cnt[2]==0){
        cout<<cnt[1]<<" + 0 = "<<cnt[1]<<'\n';
        return 0;
    }
    int n1=cnt[2],n2=cnt[1];
    int idx=3;
    while(true){
        if(!cnt[idx]) break;
        n2=n1;n1=cnt[idx];
        idx++;
    }
    cout<<n1<<" + "<<n2<<" = "<<(long long )(n1+n2)<<'\n';
    return 0;
}