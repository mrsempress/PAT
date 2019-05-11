#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct ty{
    int key;
    int l,r;
}node[50];
int post[50],in[50];
int n,tot;
vector<int>ans[50];
int build(int l,int r,int L,int R){
    //cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
    if(l>r) return -1;
    int root=post[R];
    node[++tot].key=root;
    int tmp=tot;
    int idx=l;
    while(in[idx]!=root) idx++;
    int lkids=build(l,idx-1,L,L+idx-1-l);
    int rkids=build(idx+1,r,L+idx-l,R-1);
    node[tmp].l=lkids;
    node[tmp].r=rkids;
    return tmp;
}
void zigzagging(int layer,int now){
    if(now==-1) return ;
    ans[layer].push_back(node[now].key);
    zigzagging(layer+1,node[now].l);
    zigzagging(layer+1,node[now].r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in[i];
    for(int i=1;i<=n;i++) cin>>post[i];
    build(1,n,1,n);
    zigzagging(1,1);

    cout<<ans[1][0];
    for(int i=2;i<=n;i++){
        int len=ans[i].size();
        if(i%2==1){
            for(int j=len-1;j>=0;j--){
                cout<<' '<<ans[i][j];
            }
        }else{
            for(int j=0;j<len;j++){
                cout<<' '<<ans[i][j];
            }
        }
    }
    cout<<'\n';
    return 0;
}