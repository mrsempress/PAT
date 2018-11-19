// Note that since the bank is closed everyday after 17:00, 
// for those customers who cannot be served before 17:00, 
// you must output Sorry instead.
// 说明，如果17:00之前开始办理业务，但是17:00之后才完成的人，也必须让他完成业务
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
int n,m,k,Q,x,y;
int e[25];//每个窗口最后一个人结束的时间
int ans[1005];
struct node{
    int windows;
    int ends;
    bool operator<(const node& o)const{
        if(ends==o.ends) return windows>o.windows;
        return ends>o.ends;
    }
}now;

priority_queue<node>q;

void Print(int minutes){
    int h=minutes/60+8,m=minutes%60;
    if(minutes==-1) cout<<"Sorry\n";
    else printf("%02d:%02d\n",h,m);
}

int main(){
    cin>>n>>m>>k>>Q;
    if(m==0){
        for(int i=1;i<=k;i++){
            cin>>x;
            cout<<"Sorry\n";
        }
        return 0;
    }
    
    y=0;
    for(int i=1;i<=min(n*m,k);i++){
        cin>>x;
        y++;
        if(y==n+1) y=1;
        if(e[y]>=540){
            ans[i]=-1;
        }
        else{
            e[y]+=x;
            q.push((node){y,e[y]});
            ans[i]=e[y];
        }
    }
    for(int i=min(n*m,k)+1;i<=k;i++){
        cin>>x;
        if(!q.empty()){
            now=q.top();
            q.pop();
            if(e[now.windows]>=540){
                ans[i]=-1;
                continue;
            }
            e[now.windows]+=x;
            q.push((node){now.windows,e[now.windows]});
            ans[i]=e[now.windows];
        }else{
            ans[i]=-1;
        }
    }
    
    while(Q--){
        cin>>x;
        Print(ans[x]);
    }
    return 0;
}
