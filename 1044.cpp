#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=1e5+10;
int d[maxn];
int n,m;
vector<pair<int,int> >ans;
int M;
bool work(int x){
    int l=1,r=1,tmp=0;bool flag=false;
    M=1e8;
    while(r<=n){
        tmp+=d[r];
//        cout<<l<<" "<<r<<" "<<tmp<<endl;
        if(tmp==x){
            flag=true;
            cout<<l<<'-'<<r<<'\n';
        }
        if(tmp<=x){r++;continue;}
        if(tmp>x) M=min(M,tmp);
        while(tmp>x){
            tmp-=d[l];
            if(tmp>x) M=min(M,tmp);
            l++;
//            cout<<l<<"- "<<r<<" "<<tmp<<endl;
        }
        tmp-=d[r];
    }
    if(flag) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>d[i];
    if(!work(m)){
        // cout<<M<<endl;
        work(M);
    }
    return 0;
}
