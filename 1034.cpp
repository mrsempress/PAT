#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2005;
struct G{
    int cnt;//人数
    int weight;//总重量
    int max_weight;//最重的重量
    int id;//最重的id
}group[maxn];
int f[maxn],cnt[maxn];
int vis[maxn];
map<string,int>id;//编号
int weight[maxn];//每个人的权重
string name[maxn];
struct ty{
    string name;
    int cnt;
    bool operator<(const ty& o)const{
        return name<o.name;
    }
};
vector<ty>ans;
int n,k,z;
string x,y;
void init(){
    for(int i=1;i<=2*n;i++){
        f[i]=i;
        cnt[i]=1;
    }
}
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
void join(int a,int b){
    int x=find(a),y=find(b);
    if(x==y) return ;
    if(cnt[x]<cnt[y]){
        f[x]=y;cnt[y]+=cnt[x];
    }else{
        f[y]=x;cnt[x]+=cnt[y];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    init();
    int num_id=1,num_group=1;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>z;
        if(id[x]==0&&id[y]==0){
            id[x]=num_id;weight[num_id]=z;name[num_id]=x;
            num_id++;
            id[y]=num_id;weight[num_id]=z;name[num_id]=y;
            num_id++;
        }else if(id[x]==0){
            id[x]=num_id;weight[num_id]=z;name[num_id]=x;
            num_id++;
            weight[id[y]]+=z;
        }else if(id[y]==0){
            id[y]=num_id;weight[num_id]=z;name[num_id]=y;
            num_id++;
            weight[id[x]]+=z;
        }else{
            weight[id[x]]+=z;weight[id[y]]+=z;
        }
        join(id[x],id[y]);
    }
    for(int i=1;i<num_id;i++){
        int fa=find(i);
        if(!vis[fa]){
            vis[fa]=num_group;
            group[num_group].cnt=1;
            group[num_group].weight=weight[i];
            group[num_group].max_weight=weight[i];
            group[num_group].id=i;
            num_group++;
        }else{
            group[vis[fa]].cnt+=1;
            group[vis[fa]].weight+=weight[i];
            if(group[vis[fa]].max_weight<weight[i]){
                group[vis[fa]].max_weight=weight[i];
                group[vis[fa]].id=i;
            }
        }
    }
    int K=0;
    for(int i=1;i<num_group;i++){
        if(group[i].weight>2*k&&group[i].cnt>2){
            K++;ans.push_back((ty){name[group[i].id],group[i].cnt});
        }
    }
    cout<<K<<'\n';
    sort(ans.begin(),ans.end());
    for(int i=0;i<K;i++){
        cout<<ans[i].name<<' '<<ans[i].cnt<<'\n';
    }
    return 0;
}
