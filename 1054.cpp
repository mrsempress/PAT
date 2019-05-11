#include <iostream>
#include <map>
using namespace std;
map<int,int>m;
map<int,int>::iterator it;
int n,k;
int a;
int ans,cnt=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cin>>a;m[a]++;
        }
    }
    for(it=m.begin();it!=m.end();it++){
        if((*it).second>cnt){
            cnt=(*it).second;
            ans=(*it).first;
        }
    }
    cout<<ans<<'\n';
    return 0;
}