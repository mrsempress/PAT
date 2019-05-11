/*
这道题有很多坑点：
1. 九点服务的不算
2. round up是四舍五入，不是向上取整
3.  It is assumed that every pair of players can play for at most 2 hours.
超过两个小时的只可以服务两个小时
4. When a VIP table is open, the first VIP pair in the queue will have the priviledge to take it. 
However, if there is no VIP in the queue, the next pair of players can take it.
On the other hand, if when it is the turn of a VIP pair, 
yet no VIP table is available, they can be assigned as any ordinary players.
这说的是，VIP桌子存在的时候，有VIP在等待队列中给VIP用，没有就给普通人用；
这后面一句话我没有看到- -，如果不存在VIP桌子的时候，VIP按照普通会员对待，也就是说按
到达先后的顺序来排优先级
5. P是分钟给的，最后输出是秒
6. 对于一个时间点，可能之前已经堆积了很多人了，所以需要while，比如刚开始很多人都在开门之前
早到了，则要将他们都安排了，而不是只处理一个人
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct ty{
    int arrive;
    int p;
    bool operator<(const ty& o)const{
        return arrive>o.arrive;
    }
}tmp,tmp1,tmp2;
struct leave{
    int go_out;
    int table_id;
    bool operator<(const leave& o)const{
        return go_out>o.go_out;
    }
}temp;
priority_queue<leave>playing;
priority_queue<ty>ordinary;
priority_queue<ty>VIP;
bool is_v_table[105];
bool vis[105];
int cnt[105];
int n,k,m;
int x,yy;
string a;
int to_seconds(string x){
    return (((x[0]-'0')*10+(x[1]-'0'))*60*60+
            ((x[3]-'0')*10+(x[4]-'0'))*60+
            (x[6]-'0')*10+(x[7]-'0'));
}
void Print_seconds(int seconds){
    int s=seconds%60;seconds/=60;
    int m=seconds%60;seconds/=60;
    int h=seconds;
    cout<<setfill('0')<<setw(2)<<h<<':';
    cout<<setfill('0')<<setw(2)<<m<<':';
    cout<<setfill('0')<<setw(2)<<s<<' ';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>x>>yy;
//        cout<<a<<" "<<to_seconds(a)<<" "<<to_seconds(a)+x*60<<'\n';
        if(x>120) x=120;
        if(yy==0){
            ordinary.push((ty){to_seconds(a),x*60});
        }else{
            VIP.push((ty){to_seconds(a),x*60});
        }
    }
    
    cin>>k>>m;
    for(int i=0;i<m;i++) {cin>>x;is_v_table[x]=1;}
    
    memset(vis,0,sizeof(vis));
    int now=8*60*60;int end=21*60*60;
    while(now<end){
        while(!playing.empty()){
            temp=playing.top();
            if(temp.go_out<=now){
                playing.pop();
                vis[temp.table_id]=0;
            }
            else break;
        }
        
        while(!VIP.empty()){
            tmp=VIP.top();
            if(tmp.arrive<=now){//我们可以对其服务
                //先找VIP桌子
                bool flag=false;
                for(int i=1;i<=k;i++){
                    if(is_v_table[i]&&!vis[i]){
                        vis[i]=1;cnt[i]++;
                        playing.push((leave){now+tmp.p,i});
                        Print_seconds(tmp.arrive);
                        Print_seconds(now);
                        cout<<round((now-tmp.arrive)/60.0)<<'\n';
                        flag=true;break;
                    }
                }
                if(flag){
                    VIP.pop();
                }else break;
            }else break;
        }
        while(!ordinary.empty()||!VIP.empty()){
            if(ordinary.empty()){
                tmp=VIP.top();x=1;
            }else if(VIP.empty()){
                tmp=ordinary.top();x=2;
            }else{
                tmp1=VIP.top();
                tmp2=ordinary.top();
                if(tmp1.arrive<tmp2.arrive){
                    tmp=tmp1;x=1;
                }else{
                    tmp=tmp2;x=2;
                }
            }
            
            if(tmp.arrive<=now){//我们可以对其服务
                bool flag=false;
                for(int i=1;i<=k;i++){
                    if(!vis[i]){
                        vis[i]=1;cnt[i]++;
                        playing.push((leave){now+tmp.p,i});
                        Print_seconds(tmp.arrive);
                        Print_seconds(now);
                        cout<<round((now-tmp.arrive)/60.0)<<'\n';
                        flag=true;break;
                    }
                }
                if(flag){
                    if(x==1) VIP.pop();
                    else ordinary.pop();
                }else break;
            }else break;
        }
        now++;
    }
    for(int i=1;i<k;i++){
        cout<<cnt[i]<<' ';
    }
    cout<<cnt[k]<<'\n';
    return 0;
}
