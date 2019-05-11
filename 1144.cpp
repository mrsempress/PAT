#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
int x;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x>0){
            v.push_back(x);
        }
    }
    sort(v.begin(),v.end());
    int len=v.size();
    if(len==0){
        cout<<1<<'\n';
    }else{
        int ans=1;bool flag=false;
        for(int i=0;i<len;i++){
            if(v[i]>ans){
                cout<<ans<<'\n';flag=true;
                break;
            }else if(v[i]==ans){
                ans++;
            }
        }
        if(!flag){
            cout<<v[len-1]+1<<'\n';
        }
    }
    return 0;
}