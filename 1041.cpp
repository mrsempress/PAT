#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=1e5+10;
int vis[maxn];
int n,x;
queue<int>q;
int top;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(vis[x]==0){
            q.push(x);
        }
        vis[x]++;
    }

    while(!q.empty()){
        top=q.front();
        q.pop();
        if(vis[top]==1){
            cout<<top<<'\n';
            return 0;
        }
    }
    cout<<"None\n";
    return 0;
}