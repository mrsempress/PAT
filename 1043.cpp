// 二叉树不是完全二叉树，所以不可以确定点
// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int maxn=1e3+10;
// int node[maxn];
// int n;
// void Print(int l,int r){
//     if(l>r) return ;
//     Print(l+1,(r+l)/2);
//     Print((r+l)/2+1,r);
//     if(l!=1) cout<<node[l]<<' ';
//     else cout<<node[l]<<'\n';
// }
// bool check1(int l,int r){
//     if(l>=r) return true; 
//     if(!check1(l+1,(r+l)/2)||!check1((r+l)/2+1,r)) return false;
//     return node[l]>node[(r+l)/2]&&node[l]<=node[(r+l)/2+1];
// }
// bool check2(int l,int r){
//     if(l>=r) return true; 
//     if(!check2(l+1,(r+l)/2)||!check2((r+l)/2+1,r)) return false;
//     return node[l]<=node[(r+l)/2]&&node[l]>node[(r+l)/2+1];
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++) cin>>node[i];
//     if(check1(1,n)||check2(1,n)){
//         cout<<"YES\n";
//         Print(1,n);
//     }else{
//         cout<<"NO\n";
//     }
//     return 0;
// }

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define inc(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
typedef struct node{
    int key;int l,r;
}node;
node d[1005];
int a[1005],n,fa[1005],tot,rt;
int st[1005],cnt;
void update(int &x,int key){
    if(!x){x=++tot;d[x].key=key;d[x].l=d[x].r=0;return ;}
    if(key<d[x].key)update(d[x].l,key);
    else update(d[x].r,key);
}
void preorder(int x){
    if(!x)return ;
    st[++st[0]]=d[x].key;
    preorder(d[x].l);
    preorder(d[x].r);
}
void other(int x){
    if(!x)return ;
    st[++st[0]]=d[x].key;
    other(d[x].r);
    other(d[x].l);
}
void ans1(int x){
    if(!x)return ;
    ans1(d[x].l);
    ans1(d[x].r);
    st[++st[0]]=d[x].key;
}
void ans2(int x){
    if(!x)return ;
    ans2(d[x].r);
    ans2(d[x].l);
    st[++st[0]]=d[x].key;
}
int main(){
    scanf("%d",&n);
    inc(i,1,n)scanf("%d",&a[i]);
    if(n==1){
        printf("YES\n%d\n",a[1]);
        return 0;
    }
    rt=0;
    inc(i,1,n)update(rt,a[i]);

    bool flag=false;preorder(rt);
    for(int i=1;i<=n;i++){
        if(a[i]!=st[i]){
            flag=true;
            break;
        }
    }
    if(flag){
        st[0]=0;
        flag=false;other(rt);
        for(int i=1;i<=n;i++){
            if(a[i]!=st[i]){
                flag=true;
                break;
            }
        }
        if(!flag){
            st[0]=0;
            ans2(rt);
        }
    }else{
        st[0]=0;
        ans1(rt);
    }

    if(!flag){
        printf("YES\n");
        for(int i=1;i<=n;i++){
            if(i==1)printf("%d",st[i]);
            else printf(" %d",st[i]);
        }
        printf("\n");
    }
    else printf("NO\n");
    return 0;
}