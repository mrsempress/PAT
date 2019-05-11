#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=35;
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
    if(root>=1){
        if(isleft) node[root].l=tot;
        else node[root].r=tot;
    }
    if(l==r) return ;//???????不可以少
    int x=tot;
    //if(L<=idx-1)
        build(l+1,idx-L+l,L,idx-1,x,1);
    //if(idx+1<=R)
        build(idx-L+l+1,r,idx+1,R,x,0);
}
bool judge1(int root) {
    if (root <= 0) return true;
    if (node[root].isblack == false) {
        if (node[root].l != 0 && node[node[root].l].isblack ==false) return false;
        if (node[root].r != 0 && node[node[root].r].isblack ==false) return false;
    }
    return judge1(node[root].l) && judge1(node[root].r);
}
int getNum(int root) {
    if (root <= 0) return 0;
    int l = getNum(node[root].l);
    int r = getNum(node[root].r);
    return node[root].isblack ? max(l, r) + 1 : max(l, r);
}
bool judge2(int root) {
    if (root <= 0) return true;
    int l = getNum(node[root].l);
    int r = getNum(node[root].r);
    if(l != r) return false;
    return judge2(node[root].l) && judge2(node[root].r);
}
// int countblack(int root){
//     //cout<<root<<" "<<node[root].key<<endl;
//     int l=node[root].l;
//     int r=node[root].r;
//     int lc=0,rc=0;
//     if(l!=0) lc=countblack(l);
//     if(r!=0) rc=countblack(r);
//    // cout<<root<<" "<<lc<<" "<<rc<<endl;
//     return lc+rc+node[root].isblack;
// }
// bool check(int root){
//     int l=node[root].l;
//     int r=node[root].r;
//     if(node[root].isblack==false){
//         if(l!=0&&!node[l].isblack){
//             //cout<<node[l].key<<" l\n";
//             return false;
//         }
//         if(r!=0&&!node[r].isblack){
//             //cout<<node[root].key<<" "<<node[r].key<<" r\n";
//             return false;
//         }
//     }

//     int lc=0,rc=0;
//     if(l!=0) {if(!check(l)) return false;lc=countblack(l);}
//     if(r!=0) {if(!check(r)) return false;rc=countblack(r);}
//     //cout<<node[root].key<<" "<<lc<<" "<<rc<<endl;
//     if(lc!=rc) return false;
//     return true;
// }

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
        // for(int i=1;i<=tot;i++){
        //     cout<<i<<" "<<node[i].key<<" "<<node[i].l<<" "<<node[i].r<<" "<<node[i].isblack<<endl;
        // }
        // if(node[1].isblack==false){
        //     cout<<"No\n";continue;
        // }
        // if(!check(1)) cout<<"No\n";
        // else cout<<"Yes\n";
         if (node[1].isblack==false || judge1(1) == false || judge2(1) == false)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}