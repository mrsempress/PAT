#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;
int p,n,m;
int tot=0;
struct ty{
    int gp,gm,gf,g;
    string id;
    ty(){
		gp=gm=gf=-1;
		g=0;
	}
    bool operator<(const ty& o)const{
        if(g!=o.g) return g>o.g;
        return id<o.id;
    }
}st[30105];
string name;int x,a;
map<string,int>mm;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>p>>m>>n;
    // for(int i=1;i<=p+m+n;i++){
    //     st[i].id="";st[i].gp=st[i].gm=st[i].gf=st[i].g=-1;
    // }
    for(int i=1;i<=p;i++){
        cin>>name>>x;a=mm[name];
        if(a==0){
            mm[name]=++tot;a=tot;
        }
        st[a].id=name;st[a].gp=max(st[a].gp,x);
    }
    for(int i=1;i<=m;i++){
        cin>>name>>x;a=mm[name];
        if(a==0){
            mm[name]=++tot;a=tot;
        }
        st[a].id=name;st[a].gm=max(st[a].gm,x);
    }
    for(int i=1;i<=n;i++){
        cin>>name>>x;a=mm[name];
        if(a==0){
            mm[name]=++tot;a=tot;
        }
        st[a].id=name;st[a].gf=max(st[a].gf,x);
    }
    for(int i=1;i<=tot;i++){
        if(st[i].gf==-1){
            st[i].g=st[i].gm*0.4+0.5;
        }
        else if(st[i].gm>st[i].gf){
            st[i].g=st[i].gm*0.4+st[i].gf*0.6+0.5;
        }else{
            st[i].g=st[i].gf;
        }
    }
    sort(st+1,st+1+tot);
    for(int i=1;i<=tot;i++){
        if(st[i].gp<200||st[i].g<60) continue;
        cout<<st[i].id<<' '<<st[i].gp<<' '<<st[i].gm<<' '<<st[i].gf<<' '<<st[i].g<<'\n';
    }
    return 0;
}