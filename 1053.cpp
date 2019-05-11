#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n,m,s;
vector<int>v[105];
vector<int>ans;
int weight[105];
int a,b,k,cnt=0;
bool cmp(int x,int y){
    return weight[x]>weight[y];
}

void check(int nowid,int tmp){
    tmp=tmp-weight[nowid];
    if(tmp<0) return ;
    int len=v[nowid].size();
    if(tmp==0&&len==0){
        ans.push_back(weight[nowid]);
        len=ans.size();
        for(int i=0;i<len;i++){
            if(!i) cout<<ans[i];
            else cout<<' '<<ans[i];
        }
        cout<<'\n';
        ans.pop_back();
        return ;
    }
    if(len==0||tmp==0) return ;
    ans.push_back(weight[nowid]);
    for(int i=0;i<len;i++){
        check(v[nowid][i],tmp);
    }
    ans.pop_back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++) cin>>weight[i];
    for(int i=1;i<=m;i++){
        cin>>a>>k;
        for(int j=1;j<=k;j++){
            cin>>b;
            v[a].push_back(b);
        }
    }
    for(int i=0;i<n;i++){
        sort(v[i].begin(),v[i].end(),cmp);
    }
    check(0,s);
    return 0;
}




// // 段错误
// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;
// int n,m,s;
// vector<int>v[105];
// vector<string>ans;
// vector<vector<int> >out;
// vector<int>tttt;
// int weight[105];
// int a,b,k;
// bool cmp(vector<int>a,vector<int>b){
//     int lena=a.size(),lenb=b.size();
//     int idx=0;
//     while(idx<lena&&idx<lenb){
//         if(a[idx]>b[idx]) return true;
//         else if(a[idx]<b[idx]) return false;
//         idx++;
//     }
//     if(idx<lena) return false;
//     return true;
// }
// void check(int nowid,int tmp,string path){
//     tmp=tmp-weight[nowid];
//     if(tmp<0) return ;
//     int len=v[nowid].size();
//     path+=to_string(weight[nowid]);
//     if(tmp==0&&len==0){
//         ans.push_back(path);
//         return ;
//     }
//     if(len==0||tmp==0) return ;
//     path+=" ";
//     for(int i=0;i<len;i++){
//         check(v[nowid][i],tmp,path);
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n>>m>>s;
//     for(int i=0;i<n;i++) cin>>weight[i];
//     for(int i=1;i<=m;i++){
//         cin>>a>>k;
//         for(int j=1;j<=k;j++){
//             cin>>b;
//             v[a].push_back(b);
//         }
//     }
//     check(0,s,"");
//     int len=ans.size();
//     string x="";int Len;
//     for(int i=0;i<len;i++){
//         Len=ans[i].length();
//         x="";tttt.clear();
//         for(int j=0;j<Len;j++){
//             if(ans[i][j]==' '){
//                 tttt.push_back(atoi(x.c_str()));
//                 x="";continue;
//             }
//             x+=ans[i][j];
//         }
//         tttt.push_back(atoi(x.c_str()));
//         out.push_back(tttt);
//     }
//     sort(out.begin(),out.end(),cmp);
//     for(int i=0;i<len;i++){
//         Len=out[i].size();
//         for(int j=0;j<Len;j++){
//             if(!j) cout<<out[i][j];
//             else cout<<' '<<out[i][j];
//         }
//         cout<<'\n';
//     }
//     return 0;
// }