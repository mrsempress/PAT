#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string add(string a,string b){
    int len=a.length();
    string ans="";int x=0;
    for(int i=len-1;i>=0;i--){
        int tmp=(a[i]-'0'+b[i]-'0'+x);
        ans+=(char)(tmp%10+'0');
        x=tmp/10;
    }
    if(x) ans+=(char)(x+'0');
    reverse(ans.begin(),ans.end());
    return ans;
}
bool check(string a){
    string b=a;
    reverse(a.begin(),a.end());
    return a==b;
}
int main(){
    string x,y;
    int K;
    cin>>x>>K;
    if(check(x)){
        cout<<x<<'\n'<<0<<'\n';
        return 0;
    }
    for(int i=1;i<=K;i++){
        y=x;
        reverse(x.begin(),x.end());
        x=add(x,y);
        if(check(x)){
            cout<<x<<'\n'<<i<<'\n';
            return 0;
        }
    }
    cout<<x<<'\n'<<K<<'\n';
    return 0;
}