#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
const int maxn=1e6+10;
int n,k;
struct ty{
    string nex;
    int key;
}node[maxn];
string s;
int x,data;
vector<pair<string,int> >ans;
int to_int(string x){
    int len=x.length();
    int tmp=0;
    for(int i=0;i<len;i++){
        tmp*=10;tmp+=x[i]-'0';
    }
    return tmp;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x>>data;
        node[x].key=data;
        cin>>node[x].nex;
    }
    while(s!="-1"){
        x=to_int(s);
        ans.push_back(make_pair(s,node[x].key));
        s=node[x].nex;
    }
    n=ans.size();
    bool flag=false;
    for(int i=0;i<n;i+=k){
        if(i+k-1<n){
            for(int j=i+k-1;j>=i;j--){
                if(!flag){
                    cout<<ans[j].first<<' '<<ans[j].second<<' ';
                    flag=true;
                }else{
                    cout<<ans[j].first<<'\n'<<ans[j].first<<' '<<ans[j].second<<' ';
                }
            }
        }else{
            for(int j=i;j<n;j++){
                if(!flag){
                    cout<<ans[j].first<<' '<<ans[j].second<<' ';
                    flag=true;
                }else{
                    cout<<ans[j].first<<'\n'<<ans[j].first<<' '<<ans[j].second<<' ';
                }
            }
        }
    }
    cout<<-1<<'\n';
    return 0;
}