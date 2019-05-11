#include <iostream>
#include <string>
#include <set>
using namespace std;
string x[1005];
set<string>win;
int m,n,s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n>>s;
    for(int i=1;i<=m;i++) cin>>x[i];
    int idx=s;
    while(idx<=m){
        if(win.find(x[idx])==win.end()){
            cout<<x[idx]<<'\n';
            win.insert(x[idx]);
            idx+=n;
        }else{
            idx++;
        }
    }
    if(!win.size()) cout<<"Keep going...\n";
    return 0;
}