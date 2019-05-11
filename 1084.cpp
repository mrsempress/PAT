// #include <iostream>
// #include <string>
// #include <vector>
// #include <set>
// using namespace std;
// string a,b;
// bool vis[200];
// set<char>ans;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>a>>b;
//     int lena=a.length();
//     int lenb=b.length();
//     for(int i=0;i<lenb;i++){
//         if(b[i]>='a'&&b[i]<='z') b[i]=b[i]-'a'+'A';
//         vis[b[i]]=1;
//     }
//     int len=ans.size();
//     for(int i=0;i<lena;i++){
//         if(a[i]>='a'&&a[i]<='z') a[i]=a[i]-'a'+'A';
//         if(!vis[a[i]]){
//             if(ans.find(a[i])==ans.end()){
//                 cout<<a[i];
//                 ans.insert(a[i]);
//             }
//         }
//     }
//     cout<<'\n';
//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string a,b;
bool vis[200];
vector<char>ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b;
    int lena=a.length();
    int lenb=b.length();
    int idxa=0,idxb=0;
    while(true){
        while(idxa<lena&&idxb<lenb&&a[idxa]==b[idxb]) idxa++,idxb++;
        if(idxa>=lena||idxb>=lenb) break;
        while(idxa<lena&&a[idxa]!=b[idxb]){
            if(a[idxa]>='a'&&a[idxa]<='z'){
                a[idxa]+=-'a'+'A';
            }
            if(!vis[a[idxa]]){
                vis[a[idxa]]=1;
                ans.push_back(a[idxa]);
            }
            idxa++;
        }
    }
    if(idxa<lena){//可能lena的最后几个都不行
        while(idxa<lena){
            if(a[idxa]>='a'&&a[idxa]<='z'){
                a[idxa]+=-'a'+'A';
            }
            if(!vis[a[idxa]]){
                vis[a[idxa]]=1;
                ans.push_back(a[idxa]);
            }
            idxa++;
        }
    }
    int len=ans.size();
    for(int i=0;i<len;i++){
        cout<<ans[i];
    }
    cout<<'\n';
    return 0;
}