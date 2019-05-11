#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int d[maxn];
int n,ans=0,idx;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>d[i];
    idx=1;
    while(true){
        while(d[0]!=0){
            swap(d[0],d[d[0]]);
            ans++;
        }
        while(idx<n&&d[idx]==idx) idx++;
        if(idx>=n) break;
        swap(d[0],d[idx]);ans++;
        if(d[0]!=0){
            swap(d[0],d[d[0]]);ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}