#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int maxn=35;
int st[maxn];
int top=0;
int pre[maxn],in[maxn];
int p=0,ins=0;
int n;
string a;
int x;
void Print(int l,int r,int L,int R){
    if(l>r||L>R) return ;
    int root=pre[l];
    int idx=L;
    while(in[idx]!=root) idx++;
    Print(l+1,idx-L+l,L,idx-1);
    Print(idx-L+l+1,r,idx+1,R);
    if(l==0)
        cout<<root<<'\n';
    else cout<<root<<' ';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>a;
        if(a=="Pop"){
            in[ins++]=st[--top];  
        }else{
            cin>>x;
            st[top++]=x;
            pre[p++]=x;
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<pre[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<in[i]<<" ";
    // }
    // cout<<endl;
    Print(0,n-1,0,n-1);
    return 0;
}
