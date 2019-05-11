#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int m,n,tot,x,layer,cnt;
bool Mh,mh;
int node[1005];
void post(int root){
    if(root*2<=n) post(root*2);
    if(root*2+1<=n) post(root*2+1);
    if(root==1) cout<<node[root]<<'\n';
    else cout<<node[root]<<' ';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    while(m--){
        tot=0;Mh=mh=false;
        for(int i=1;i<=n;i++){
            cin>>x;
            node[i]=x;
            int f=i/2;
            if(f==0) continue;
            if(node[f]>x) Mh=true;
            else if(node[f]<x) mh=true;
        }
        if(Mh&&mh){
            cout<<"Not Heap\n";
        }else if(Mh){
            cout<<"Max Heap\n";
        }else{
            cout<<"Min Heap\n";
        }
        post(1);
    }
    return 0;
}