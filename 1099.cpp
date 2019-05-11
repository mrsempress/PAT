#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int a[105];
struct ty{
    int l,r;
    int key;
}node[105];
int cnt=1,x;
queue<int>q;
void work(int now){
    if(node[now].l!=-1) work(node[now].l);
    node[now].key=a[cnt++];
    if(node[now].r!=-1) work(node[now].r);
}
void Print(){
    q.push(0);cout<<node[0].key;
    while(!q.empty()){
        x=q.front();q.pop();
        if(node[x].l!=-1){
            cout<<' '<<node[node[x].l].key;
            q.push(node[x].l);
        }
        if(node[x].r!=-1){
            cout<<' '<<node[node[x].r].key;
            q.push(node[x].r);
        }
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>node[i].l>>node[i].r;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);    
    work(0);
    Print();
    return 0;
}