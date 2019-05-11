#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;
const int maxn=1e4+10;
int pos[maxn];
int a[maxn];
bool vis[maxn];
bool prime(int x){
    if(x<2) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0) return false;
    }
    return true;
}
int n,k;
int b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b;pos[b]=i;a[i]=b;
    }
    cin>>k;
    while(k--){
        cin>>b; cout<<setfill('0')<<setw(4)<<b<<": ";
        if(!pos[b]){cout<<"Are you kidding?\n";}
        else{
            if(vis[b]){cout<<"Checked\n";}
            else{
                if(pos[b]==1){cout<<"Mystery Award\n";}
                else if(prime(pos[b])){cout<<"Minion\n";}
                else {cout<<"Chocolate\n";}
                vis[b]=1;
            }
        }
    }
    return 0;
}
