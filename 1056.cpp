/*
25 
18 0 46 
37 3 19 
22 57 56
10
6  0 8 7  10 5 9   1 4  2   3    

19 25 57
22 10 3
56 18 37
0 46

57 22 56
46

57 46

5 5 5 2 5 5 5 3 1 3 5 
*/

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct ty{
    int id;
    int weight;
    bool operator<(const ty& o)const{
        return weight<o.weight;
    }
}node[1005],tmp;
priority_queue<ty>q;
queue<ty>p[2];
int cnt,num;
int n,m,k;
int ans[1005];
int a,b;
bool flag;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>node[i].weight;
        node[i].id=i;
    }
    cnt=0;num=0;flag=false;
    for(int i=1;i<=n;i++){
        cin>>a;p[flag].push(node[a]);
    }
    flag=true;
    while(true){
        flag=(!flag);
        k=p[flag].size();
        cnt=k/m+(k%m!=0);
        if(k==1){
            b=p[flag].front().id;
            ans[b]=cnt;
            break;
        }
        
        for(int i=1;i<=k;i++){
            tmp=p[flag].front();p[flag].pop();
            q.push(tmp);
            num++;
            if(num==m){
                tmp=q.top();
                //cout<<cnt<<' '<<tmp.id<<' '<<tmp.weight<<endl;
                p[!flag].push(tmp);
                q.pop();
                while(!q.empty()){
                    b=q.top().id;
                    //cout<<cnt<<' '<<b<<' '<<q.top().weight<<endl;
                    ans[b]=cnt+1;
                    q.pop();
                }
                ///cout<<endl;
                num=0;
            }
        }
        if(num!=0){
            tmp=q.top();
            q.pop();
            //cout<<cnt<<' '<<tmp.id<<' '<<tmp.weight<<endl;
            p[!flag].push(tmp);
            while(!q.empty()){
                b=q.top().id;
                //cout<<cnt<<' '<<b<<' '<<q.top().weight<<endl;
                ans[b]=cnt+1;
                q.pop();
            }
            num=0;
        }
    }
    for(int i=0;i<n;i++){
        if(i==0) cout<<ans[i];
        else cout<<' '<<ans[i];
    }
    cout<<'\n';
    return 0;
}