#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s[120];
int len[120];
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin.get();
    for(int i=1;i<=n;i++){
        getline(cin,s[i]);
        len[i]=s[i].length();
        //cout<<i<<' '<<len[i]<<" "<<s[i]<<endl;
    }
    string ans="";int idx=1;
    char c;
    while(true){
        //cout<<len[1]<<' '<<idx<<endl;
        if(len[1]-idx<0) break;
        c=s[1][len[1]-idx];
        //cout<<idx<<' '<<c<<endl;
        int i=2;
        for(;i<=n;i++){
            if(len[i]-idx<0||s[i][len[i]-idx]!=c)break;
        }
        if(i>n){
            ans+=c;
            idx++;
        }else break;
    }
    if(ans=="") cout<<"nai\n";
    else{
        reverse(ans.begin(),ans.end());
        cout<<ans<<'\n';
    }
    return 0;
}