#include <iostream>
#include <cstring>
using namespace std;
int n;
int a,b;
int say[105];
int lie[105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>say[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            memset(lie,0,sizeof(lie));
            int cnt=0;
            for(int k=1;k<=n;k++){
                if(say[k]<0){
                    if(!(-say[k]==i||-say[k]==j))lie[k]=1,cnt++;
                }else{
                    if(say[k]==i||say[k]==j) lie[k]=1,cnt++;
                }
            }
            if((lie[i]+lie[j])==1&&cnt==2){
                cout<<i<<' '<<j<<'\n';
                return 0;
            }
        }
    }
    cout<<"No Solution\n";
    return 0;
}