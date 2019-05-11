// 因为m的个数较小，用m次dijkstra，而不是算floyd

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
const int maxn=1e3+100;
const int INF=1e9+10;
int edge[maxn][maxn],d[maxn];
bool vis[maxn];
int n,m,k,D;
string a,b;
int x,aa,bb;
int to_Int(string x){
    int len=x.length();
    int tmp=0;
    for(int i=0;i<len;i++){
        if(x[i]=='G') continue;
        tmp*=10;tmp+=x[i]-'0';
    }
    if(x[0]=='G') tmp+=n;
    return tmp;
} 
void Dijkstra(int s){
    memset(vis,0,sizeof(vis));
    memset(d,INF,sizeof(d));
    d[s]=0;
    while(true){
        int u=-1,Min=INF;
        for(int i=1;i<=n+m;i++){
            if(!vis[i]&&d[i]<Min) Min=d[i],u=i;
        }
        if(u==-1) return ;
        vis[u]=true;

        for(int i=1;i<=n+m;i++){
            if(!vis[i]&&edge[u][i]&&d[i]>d[u]+edge[u][i]){
                d[i]=d[u]+edge[u][i];
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // memset(edge,INF,sizeof(edge));
    cin>>n>>m>>k>>D;
    for(int i=1;i<=k;i++){
        cin>>a>>b>>x;
        aa=to_Int(a);bb=to_Int(b);
        edge[aa][bb]=edge[bb][aa]=x;
    }
    // for(int k=1;k<=n+m;k++){
    //     for(int i=1;i<=n+m;i++){
    //         for(int j=1;j<=n+m;j++){
    //             if(edge[i][j]>edge[i][k]+edge[k][j]){
    //                 edge[j][i]=edge[i][j]=edge[i][k]+edge[k][j];
    //             }
    //         }
    //     }
    // }
    
    double dis=0,dis_tmp;//as far as possible
    double avg_dis=INF,avg_tmp;//output the one with the smallest average distance to all the houses. 
    bool flag;//guarantee that all the houses are in its service range.
    int idx=-1;
    for(int i=n+1;i<=n+m;i++){
        dis_tmp=INF;flag=false;avg_tmp=0;
        Dijkstra(i);
        for(int j=1;j<=n;j++){
            if(d[j]>D){
                flag=true;break;
            }
            dis_tmp=min(dis_tmp,d[j]*1.0);
            avg_tmp+=d[j];
        }
        if(!flag&&(dis_tmp>dis||(dis_tmp==dis&&avg_tmp<avg_dis))){
            dis=dis_tmp;idx=i-n;
            avg_dis=avg_tmp;
        }
    }
    if(idx==-1){
        cout<<"No Solution\n";
    }else{
        cout<<'G'<<idx<<'\n';
        cout.setf(ios::fixed);
        cout<<setprecision(1)<<dis*1.0<<' '<<avg_dis*1.0/n<<'\n';
    }
    return 0;
}