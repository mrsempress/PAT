//TLE
// m整个的查找很慢
// #include <iostream>
// #include <vector>
// #include <map>
// #include <string>
// using namespace std;
// const int maxn=1e6+10;
// map<pair<string,string>,int>m;
// pair<string,string>tmp;
// int N,M,k;
// string x,y;
// string G[1005];
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>N>>M;
//     for(int i=1;i<=N;i++){
//         cin>>x>>y;
//         if(x>y) swap(x,y);
//         tmp.first=x;tmp.second=y;
//         m[tmp]=1;
//     }
//     while(M--){
//         cin>>k;
//         for(int i=1;i<=k;i++){
//             cin>>G[i];
//         }
//         bool flag=false;
//         for(int i=1;i<=k;i++){
//             for(int j=i+1;j<=k;j++){
//                 if(G[i]<=G[j]){
//                     tmp.first=G[i];tmp.second=G[j];
//                 }
//                 else{
//                     tmp.first=G[j];tmp.second=G[i];
//                 }
//                 if(m[tmp]==1){flag=true;break;}//这里其实不是o(1)
//             }
//             if(flag) break;
//         }
//         if(flag) cout<<"No\n";
//         else cout<<"Yes\n";
//     }
//     return 0;
// }

// 1e9
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
int n,M,k;
map<int,vector<int> >m;
int K[1005];
bool vis[100005];
int a,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>M;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    while(M--){
        cin>>k;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=k;i++){
            cin>>K[i];
            vis[K[i]]=1;//这一步很好，避免了一重循环
        }
        bool flag=false;
        for(int i=1;i<=k;i++){
            int len=m[K[i]].size();
            for(int j=0;j<len;j++){
                if(vis[m[K[i]][j]]==1) {
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}