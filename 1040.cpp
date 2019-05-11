#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string in;
int len;
int ans=1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    getline(cin,in);
    len=in.length();
    for(int i=0;i<len;i++){
        int idx=1;
        while(i-idx>=0&&i+idx<len&&in[i-idx]==in[i+idx]) idx++;
        ans=max(ans,2*idx-1);
        idx=0;
        while(i-idx>=0&&i+idx+1<len&&in[i-idx]==in[i+1+idx]) idx++;
        ans=max(ans,2*idx);
    }
    cout<<ans<<'\n';
    return 0;
}