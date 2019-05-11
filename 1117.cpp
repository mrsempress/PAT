#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int sum[maxn];
int n,x;
int ans=1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>sum[i];
    }
    sort(sum+1,sum+1+n);
    int idx=n,cnt=0;
    while(idx>=1&&sum[idx]>cnt+1) idx--,cnt++;
    cout<<cnt<<'\n';
    return 0;
}