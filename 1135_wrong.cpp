#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=100;
int pre[maxn],in[maxn];
int tot,n,k;
struct ty{
    int key;
    int l;
    int r;
    bool isblack;
}node[maxn];
void build(int l,int r,int L,int R,int root,bool isleft){
 //cout<<"shunxu: "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
    if(l>r||L>R) return ;
    node[++tot].key=abs(pre[l]);node[tot].l=node[tot].r=0;
    if(pre[l]>0) node[tot].isblack=true;
    else node[tot].isblack=false;

    ///if(root!=-1)cout<<"root:"<<abs(pre[l])<<" "<<node[root].key<<" "<<isleft<<endl;
    int idx=L;
    while(in[idx]!=abs(pre[l])) idx++;
    if(root!=-1){
        if(isleft) node[root].l=tot;
        else node[root].r=tot;
    }
    int x=tot;
    build(l+1,idx-L+l,L,idx-1,x,1);
    build(idx-L+l+1,r,idx+1,R,x,0);
}
int countblack(int root){
    //cout<<root<<" "<<node[root].key<<endl;
    int l=node[root].l;
    int r=node[root].r;
    if(node[root].isblack==false){
        if(l!=0&&!node[l].isblack){
            //cout<<node[l].key<<" l\n";
            return -1;
        }
        if(r!=0&&!node[r].isblack){
            //cout<<node[root].key<<" "<<node[r].key<<" r\n";
            return -1;
        }
    }

    int lc=0,rc=0;
    if(l!=0) lc=countblack(l);
    if(r!=0) rc=countblack(r);
   // cout<<root<<" "<<lc<<" "<<rc<<endl;
    if(lc==-1||rc==-1||lc!=rc) return -1;
    return lc+rc+node[root].isblack;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k;
    while(k--){
        cin>>n;tot=0;
        for(int i=1;i<=n;i++){
            cin>>pre[i];in[i]=abs(pre[i]);
        }
        sort(in+1,in+1+n);
        build(1,n,1,n,-1,0);
        int tmp=countblack(1);
        if(tmp==-1) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}