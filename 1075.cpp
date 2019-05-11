#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;
const int maxn=1e4+10;
int n,k,m;
int p[10];
struct ty{
    string id;
    int a[10];
    int sum;
    int perfect;
    bool operator<(const ty& o)const{
        if(sum!=o.sum) return sum>o.sum;
        if(perfect!=o.perfect) return perfect>o.perfect;
        return id<o.id;
    }
}node[maxn];
int to_int(string x){
    int len=x.length();
    int tmp=0;
    for(int i=0;i<len;i++){
        tmp*=10;tmp+=x[i]-'0';
    }
    return tmp;
}
int x,id,b;
string a;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            node[i].a[j]=-2;
        }
    }
    for(int i=1;i<=k;i++){ cin>>p[i];}
    while(m--){
        cin>>a>>id>>x;
        b=to_int(a);
        node[b].id=a;
        node[b].a[id]=max(node[b].a[id],x);
    }

    for(int i=1;i<=n;i++){
        bool flag=false;
        for(int j=1;j<=k;j++){
            if(node[i].a[j]>0){
                node[i].sum+=node[i].a[j];
            }
            if(node[i].a[j]==p[j]){
                node[i].perfect++;
            }
            if(node[i].a[j]>=0){
                flag=true;
            }
            if(node[i].a[j]==-1) node[i].a[j]=0;
        }
        if(!flag) node[i].sum=-1;
    }

    sort(node+1,node+1+n);
    int sum=0,rank=0;
    for(int i=1;i<=n;i++){
        if(node[i].sum==-1) break;
        if(node[i].sum!=sum) rank=i;
        cout<<rank<<' '<<node[i].id<<' '<<node[i].sum;
        for(int j=1;j<=k;j++){
            if(node[i].a[j]==-2) cout<<' '<<'-';
            else cout<<' '<<node[i].a[j];
        }
        cout<<'\n';
        sum=node[i].sum;
    }
    return 0;
}