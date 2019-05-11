#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
const int maxn=305;
map<int,int>id;
string reid[maxn];
bool isman[maxn];
int edge[maxn][maxn];
string x,yy;
int a,b,c,d,e,f;
int tot=0;
int n,m,k;
vector<pair<string,string> >ans;
bool cmp(pair<string,string>a,pair<string,string>b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int to_Integer(string x){
    int len=x.length();
    int tmp=0;
    if(x[0]=='-'){
        for(int i=1;i<len;i++){
            tmp*=10;tmp+=x[i]-'0';
        }
        tmp*=-1;
    }else{
        for(int i=0;i<len;i++){
            tmp*=10;tmp+=x[i]-'0';
        }
    }
    return tmp;
}
string work(string x){
    int len=x.length();
    string tmp="";
    if(x[0]=='-'){
        for(int i=1;i<len;i++){
            tmp+=x[i];
        }
    }else tmp=x;
    return tmp;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>yy;
        a=to_Integer(x);
        b=to_Integer(yy);
        if(a<0) c=-a;else c=a;
        if(b<0) d=-b;else d=b;
        if(id[c]==0){id[c]=++tot;e=tot;reid[tot]=work(x);}
        else e=id[c];
        if(id[d]==0){id[d]=++tot;f=tot;reid[tot]=work(yy);}
        else f=id[d];
        if(x[0]!='-'){isman[e]=true;}
        if(yy[0]!='-'){isman[f]=true;}
        edge[e][f]=edge[f][e]=1; 
    }
    cin>>k;
    while(k--){
        ans.clear();
        cin>>x>>yy;
        a=to_Integer(x);
        b=to_Integer(yy);
        if(a<0) c=-a;else c=a;
        if(b<0) d=-b;else d=b;
        e=id[c];f=id[d];
        bool flag1=false,flag2=false;
        if(x[0]!='-')flag1=true;if(yy[0]!='-')flag2=true;
        for(int i=1;i<=n;i++){
            if(i==e||i==f) continue;
            if(isman[i]==flag1&&edge[e][i]==1){
                for(int j=1;j<=n;j++){
                    if(j==e||j==f) continue;
                    if(isman[j]==flag2&&edge[i][j]&&edge[j][f]){
                        ans.push_back(make_pair(reid[i],reid[j]));
                    }
                }
            }
        }
        int len=ans.size();
        cout<<len<<'\n';
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<len;i++){
            cout<<ans[i].first<<' '<<ans[i].second<<'\n';
        }
    }
    return 0;
}