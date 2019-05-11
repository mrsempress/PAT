#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
map<string,int>m;
map<string,int>::iterator it;
string in,x;
int len;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    getline(cin,in);
    len=in.length();
    int i=0;x="";
    while(i<len){
        if(in[i]=='\\'&&i+1<len&&in[i+1]=='n'){
            if(x!="") m[x]++;
            x="";
            i++;
        }
        else if((in[i]<='9'&&in[i]>='0')||(in[i]<='Z'&&in[i]>='A')
        ||(in[i]<='z'&&in[i]>='a')){
            if(in[i]<='Z'&&in[i]>='A') x+=in[i]-'A'+'a';
            else x+=in[i];
        }else{
            if(x!="")
                m[x]++;
            x="";
        }
        i++;
    }
    if(x!="") m[x]++;//注意这里
    x="";len=0;
    for(it=m.begin();it!=m.end();it++){
        if((*it).second>len||((*it).second==len&&(*it).first<(*it).first)){
            x=(*it).first;
            len=(*it).second;
        }
    }
    cout<<x<<' '<<len<<'\n';
    return 0;
}