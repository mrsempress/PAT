#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k,x;
int st[1005];
int top;
bool flag;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n>>k;
    for(int i=1;i<=k;i++){
        top=0;int now=1;flag=false;
        for(int j=1;j<=n;j++){
            cin>>x;
            while(!flag&&st[top]!=x){
                st[++top]=now;
                // cout<<top<<" "<<now<<endl;
                now++;
                if(top==m+1) {flag=true;break;}
                if(now==n+2) {flag=true;break;} 
            }
            if(!flag&&st[top]==x){
                // cout<<"Pop: "<<x<<" "<<top-1<<endl;
                top--;
            }
            // cout<<endl;
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}