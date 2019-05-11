#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int n;
int cnt;
int len;
string now,nex;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>now>>n;
    for(int i=2;i<=n;i++){
        len=now.length();nex="";
        for(int j=0;j<len;){
            cnt=1;
            while(j+cnt<len&&now[j]==now[j+cnt]){
                cnt++;
            }
            nex+=now[j];nex+=(char)(cnt+'0');
            j+=cnt;
        }
        now=nex;
        //cout<<now<<' '<<i<<endl;
    }
    cout<<now<<'\n';
    return 0;
}