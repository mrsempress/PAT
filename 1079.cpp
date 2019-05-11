#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
const int maxn=1e5+10;
int n,m,x;
double p,r,ans;
vector<int>v[maxn];
bool hasfather[maxn];
int retailer[maxn];
void work(int now,double money){
    //cout<<now<<' '<<money<<' ';
    int len=v[now].size();
    for(int i=0;i<len;i++){
        work(v[now][i],money*(1+r/100));
    }
    if(!len){
        ans+=retailer[now]*money;
    }
    //cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>p>>r;
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=1;j<=m;j++){
            cin>>x; v[i].push_back(x);
            hasfather[x]=1;
        }
        if(!m){
            cin>>retailer[i];
        }
    }

    for(int i=0;i<n;i++){
        if(!hasfather[i]){
            work(i, p);
        }
    }
    cout.setf(ios::fixed);
    cout<<setprecision(1)<<ans<<'\n';
    return 0;
}