#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string>c[2505];
int n,k,C,x;
string name;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>name>>C;
        for(int j=1;j<=C;j++){
            cin>>x;
            c[x].push_back(name);
        }
    }
    for(int i=1;i<=k;i++){
        sort(c[i].begin(),c[i].end());
        int len=c[i].size();
        cout<<i<<' '<<len<<'\n';
        for(int j=0;j<len;j++){
            cout<<c[i][j]<<'\n';
        }
    }
    return 0;
}