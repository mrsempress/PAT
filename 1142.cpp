#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=2005;
bool e[maxn][maxn];
int m,ne,nv,k,a,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>nv>>ne;
    for(int i=1;i<=ne;i++){cin>>a>>b;e[a][b]=e[b][a]=1;}
    cin>>m;
    while(m--){
        cin>>k;
        int vis[maxn];bool f[maxn]={0};
        for(int j=0;j<k;j++){
            cin>>a;vis[j]=a;f[a]=1;
        }
        //for(int i=0;i<k;i++) cout<<vis[i]<<endl;
        bool isclique=true;
        for(int j=0;j<k;j++){
            for(int x=j+1;x<k;x++){
                if(e[vis[j]][vis[x]]==0){
                    isclique=false;
                    break;
                }
            }
            if(!isclique) break;
        }
        if(!isclique){
            cout<<"Not a Clique\n";
        }else{
            bool ismaxclique=true;
            for(int i=1;i<=nv;i++){
                if(f[i]) continue;
                //cout<<endl;
                for(int j=0;j<k;j++){
                    //cout<<i<<" "<<vis[j]<<endl;
                    if(i==vis[j]) continue;
                    if(e[i][vis[j]]==0) {break;}
                    if(j==k-1){ismaxclique=false;}
                }
                //cout<<i<<" "<<ismaxclique<<endl;
                if(!ismaxclique) break;
            }
            if(!ismaxclique) cout<<"Not Maximal\n";
            else cout<<"Yes\n";
        }
    }
    return 0;
}