#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=1e4+10;
// bool check(string a,string b){
//     string now=a+b;
//     string after=b+a;
//     if(now<=after) return false;
//     return true;
// }
bool cmp(string a,string b){
    return a+b<=b+a;
}
int n;
string a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    // bool flag=false;
    // for(int i=1;i<n;i++){
    //     flag=false;
    //     for(int j=1;j<n-i+1;j++){
    //         if(check(a[j],a[j+1])){
    //             flag=true;
    //             swap(a[j],a[j+1]);
    //         }
    //     }
    //     if(!flag) break;
    // }
    sort(a+1,a+1+n,cmp);
    string ans="";
    for(int i=1;i<=n;i++) ans+=a[i];
    int len=ans.length();
    int idx=0;
    while(idx<len&&ans[idx]=='0') idx++;
    if(idx==len) cout<<"0\n";
    else{
        for(;idx<len;idx++) cout<<ans[idx];
        cout<<'\n';
    }
    return 0;
}