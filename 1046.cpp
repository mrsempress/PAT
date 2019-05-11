#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m;
int d[maxn];//1-i的距离
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>d[i];
        d[i]+=d[i-1];
        // cout<<"1 - "<<i<<" "<<d[i]<<endl;
    }
    cin>>d[n+1];//n-1的距离
    // cout<<n<<" - "<<1<<" "<<d[n+1]<<endl;
    cin>>m;
    int a,b;
    while(m--){
        cin>>a>>b;
        if(a>b) swap(a,b);
        // cout<<d[n]<<" "<<d[b]<<" "<<d[n-1]<<" "<<d[a]
        // cout<<d[b]<<" "<<d[a]<<" "<<d[n]-d[b]+d[n-1]+d[a]<<endl;
        cout<<min(d[b]-d[a],d[n]-d[b]+d[n+1]+d[a])<<'\n';
    }
    return 0;
}