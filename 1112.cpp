#include <iostream>
#include <string>
using namespace std;
const int maxn=205;
int k;
bool vis[maxn];//认为是重复的字符
bool vivis[maxn];//被确认过了
bool output[maxn];
string s;
int len;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k;
    cin>>s;
    len=s.length();
    for(int i=0;i<len;){
        if(vivis[s[i]]){
            if(vis[s[i]]){//如果之前认为是，进行检查
                for(int j=0;j<k;j++){
                    if(s[i]!=s[i+j]){
                        vis[s[i]]=0;break;
                    }
                }
                i+=k;
            }else i++;
        }else{
            int j;
            for(j=0;j<k;j++){
                if(s[i]!=s[i+j]) break;
            }
            if(j>=k){vivis[s[i]]=vis[s[i]]=1;}
            else vivis[s[i]]=1;
        }
    }
    for(int i=0;i<len;i++){
        if(vis[s[i]]&&!output[s[i]]){
            cout<<s[i];output[s[i]]=1;
        }
    }
    cout<<'\n';
    for(int i=0;i<len;){
        if(!vis[s[i]]) cout<<s[i++];
        else{
            cout<<s[i];
            i+=k;
        }
    }
    cout<<'\n';
    return 0;
}