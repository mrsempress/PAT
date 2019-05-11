#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
const int maxn=1e5+10;
struct ty{
    string now;
    string nex;
    int data;
}node[maxn];
int n,k;
vector<ty>neg;
vector<ty>ins;
vector<ty>big;
string f,now,nex;
map<string,int>m;
int d,tot=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>f>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>now>>d>>nex;
        m[now]=++tot;
        node[tot].now=now;node[tot].nex=nex;
        node[tot].data=d;
    }
    now=f;
    while(now!="-1"){
        d=m[now];
        if(node[d].data<0){
            neg.push_back(node[d]);
        }else if(node[d].data<=k){
            ins.push_back(node[d]);
        }else{
            big.push_back(node[d]);
        }
        now=node[d].nex;
    }
    bool f=false;int len=neg.size();
    for(int i=0;i<len;i++){
        if(!f){
            cout<<neg[i].now<<' '<<neg[i].data<<' ';
            f=true;
        }else{
            cout<<neg[i].now<<'\n'<<neg[i].now<<' '<<neg[i].data<<' ';
        }
    }
    len=ins.size();
    for(int i=0;i<len;i++){
        if(!f){
            f=true;
            cout<<ins[i].now<<' '<<ins[i].data<<' ';
        }else{
            cout<<ins[i].now<<'\n'<<ins[i].now<<' '<<ins[i].data<<' ';
        }
    }
    len=big.size();
    for(int i=0;i<len;i++){
        if(!f){
            f=true;
            cout<<big[i].now<<' '<<big[i].data<<' ';
        }else{
            cout<<big[i].now<<'\n'<<big[i].now<<' '<<big[i].data<<' ';
        }
    }
    cout<<-1<<'\n';
    return 0;
}