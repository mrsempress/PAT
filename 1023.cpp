#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int cnt[10],cnt1[10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string in;cin>>in;
    int len=in.l ength();
    int add=0,nex;
    string ans="";
    for(int i=len-1;i>=0;i--){
        cnt[in[i]-'0']++;
        nex=(in[i]-'0')*2+add;
        ans+=(char)(nex%10+'0');
        cnt1[nex%10]++;
        add=nex/10;
    }
    if(add){
        ans+=(char)(add+'0');
        cnt1[add]++;
    }
    for(int i=0;i<10;i++){
        if(cnt[i]!=cnt1[i]){
            cout<<"No\n";
            reverse(ans.begin(),ans.end());
            cout<<ans<<'\n';
            return 0;
        }
    }
    cout<<"Yes\n";
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
    return 0;
}