#include <iostream>
using namespace std;
const int maxn=50005;
int pre[maxn],in[maxn];
int ans;int n;
void Find(int l,int r,int L,int R){
    // cout<<pre[l]<<" "<<pre[r]<<" "<<in[L]<<" "<<in[R]<<endl;
    // cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl<<endl;
    if(L==R){ans=in[L];return ;}
    //if(L==R-1){ans=pre[r];return ;}
    int root=pre[l];
    if(in[L]==root){
        Find(l+1,r,L+1,R);
        return ;
    }
    for(int i=L;i<=R;i++){
        if(in[i]==root){
            Find(l+1,i-L+l,L,i-1);
            break;
        }
    }
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>pre[i];
    for(int i=1;i<=n;i++) cin>>in[i];
    Find(1,n,1,n);
    cout<<ans<<'\n';
    return 0;
}