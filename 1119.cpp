#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=35;
bool flag=false;
vector<int>ans;
int tot=0,n;
int pre[maxn],post[maxn];
void work(int l,int r,int L,int R){
    //cout<<l<< " "<<r<<" "<<L<<" "<<R<<endl;
    if(l>r||L>R) return ;
    if(l==r){
        ans.push_back(pre[l]);
        return ;
    }
    if(l==r-1){
        flag=true;
        ans.push_back(pre[l]);
        ans.push_back(pre[r]);
        return ;
    }
    int root=pre[l];
    int lroot=pre[l+1];
    int idx=L;
    while(post[idx]!=lroot) idx++;
    work(l+1,idx-L+l+1,L,idx);
    ans.push_back(root);
    int rroot=post[R-1];
    work(idx-L+l+2,r,idx+1,R-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>pre[i];
    for(int i=1;i<=n;i++) cin>>post[i];
    work(1,n,1,n);
    if(flag){
        cout<<"No\n";
    }else cout<<"Yes\n";
    for(int i=0;i<n;i++){
        if(!i) cout<<ans[i];
        else cout<<' '<<ans[i];
    }
    cout<<'\n';
    return 0;
}