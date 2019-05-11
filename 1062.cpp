#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int maxn=1e5+10;
int n,l,h,m;
struct ty{
    string ID;
    int vg;
    int tg;
    int kind;// 1:sages 2:nobleman 3:fool men 5:small man 
    bool operator<(const ty& o)const{
        if(kind!=o.kind) return kind<o.kind;
        if((vg+tg)!=(o.vg+o.tg)) return (vg+tg)>(o.vg+o.tg);
        if(vg!=o.vg) return vg>o.vg;
        return ID<o.ID;
    }
}tmp;
vector<ty>v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l>>h;
    for(int i=1;i<=n;i++){
        cin>>tmp.ID>>tmp.vg>>tmp.tg;
        if(tmp.vg<l||tmp.tg<l) continue;
        if(tmp.vg>=h&&tmp.tg>=h){
            tmp.kind=1;v.push_back(tmp);
            continue;
        }
        if(tmp.vg>=h){
            tmp.kind=2;v.push_back(tmp);
            continue;
        }
        if(tmp.tg>=h){
            tmp.kind=5;v.push_back(tmp);
            continue;
        }
        if(tmp.vg>=tmp.tg){
            tmp.kind=3;v.push_back(tmp);
            continue;
        }
        tmp.kind=5;v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    int len=v.size();
    cout<<len<<'\n';
    for(int i=0;i<len;i++){
        cout<<v[i].ID<<' '<<v[i].vg<<' '<<v[i].tg<<'\n';
    }
    return 0;
}