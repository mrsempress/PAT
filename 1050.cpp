#include <iostream>
#include <string>
using namespace std;
bool vis[300];
string a,b;
int lena,lenb;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    getline(cin,a);
    getline(cin,b);
    lena=a.length();
    lenb=b.length();
    for(int i=0;i<lenb;i++){
        vis[b[i]]=1;
    }
    for(int i=0;i<lena;i++){
        if(!vis[a[i]]) cout<<a[i];
    }
    cout<<'\n';
    return 0;
}