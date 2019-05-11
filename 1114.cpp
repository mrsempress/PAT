#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int maxn=1e4+10;
typedef long long ll;
int n;
int mes[maxn],area[maxn],f[maxn],m[maxn];
int family[maxn],cnt[maxn];
bool vis[maxn];
struct ty{
    int small_id;
    int num;
    int sets;
    int area;
    double avg_sets;
    double avg_area;
    bool operator<(const ty& o)const{
        if(avg_area==o.avg_area) return small_id<o.small_id;
        return avg_area>o.avg_area;
    }
}node[maxn];
int id[maxn];
int a,b,c,k,x;
int tot=0;
void init(){
    for(int i=0;i<maxn;i++){
        family[i]=i;cnt[i]=0;
    }
}
int find(int x){
    if(x!=family[x]) return family[x]=find(family[x]);
    return family[x];
}

void merge(int x,int y){
    int a=find(x),b=find(y);
    if(a!=b){
        if(cnt[a]<cnt[b]){
            family[a]=b;
            cnt[b]+=cnt[a];
        }else{
            family[b]=a;
            cnt[a]+=cnt[b];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;init();
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>k;f[a]=b;m[a]=c;
        vis[a]=1;
        if(b!=-1) {vis[b]=1;merge(b,a);}
        if(c!=-1) {vis[c]=1;merge(c,a);}
        for(int j=0;j<k;j++){
            cin>>x;vis[x]=1;
            merge(a,x);
        }
        cin>>b>>c;
        mes[a]=b;area[a]=c;
    }
    for(int i=0;i<10000;i++){
        if(vis[i]){
            int fff=find(i);
            int tmp=id[fff];
            if(tmp==0){
                id[fff]=++tot;
                tmp=tot;
                node[tmp].small_id=i;
            }
            //cout<<i<<" "<<family[i]<<endl;
            node[tmp].small_id=min(i,node[tmp].small_id);
            node[tmp].num++;
            node[tmp].sets+=mes[i];
            node[tmp].area+=area[i];
        }
    }
    for(int i=1;i<=tot;i++){
        node[i].avg_sets=node[i].sets*1.0/node[i].num;//居然不可以用先乘，再除，估计爆精度了吧！！！
        node[i].avg_area=node[i].area*1.0/node[i].num;
    }
    sort(node+1,node+1+tot);
    cout<<tot<<'\n';
    cout.setf(ios::fixed);
    for(int i=1;i<=tot;i++){
        cout<<setfill('0')<<setw(4)<<node[i].small_id<<' '<<node[i].num<<' '<<setprecision(3)<<node[i].avg_sets<<' '<<setprecision(3)<<node[i].avg_area<<'\n';
    }
    return 0;
}
