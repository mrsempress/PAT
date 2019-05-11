#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
const int maxn=1e4+10;
bool vis[maxn];
int cnt[10],cnts[10];
int x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>x;
    int idx=1;
    while(true){
        int num=0;
        while(x){cnt[x%10]++;cnts[x%10]++;x/=10;num++;}
        while(num<4) {cnt[0]++;cnts[0]++;num++;}
        int a=0,b=0;
        for(int i=9;i>=0;i--){
            while(cnt[i]){
                a*=10;a+=i;
                cnt[i]--;
            }
        }
        for(int i=0;i<=9;i++){
            while(cnts[i]){
                b*=10;b+=i;
                cnts[i]--;
            }
        }
        if(idx==1&&a-b==0){
            cout<<setfill('0')<<setw(4)<<a<<" - "<<setfill('0')<<setw(4)<<b<<" = "<<setfill('0')<<setw(4)<<a-b<<'\n';
            break;
        }
        idx++;
        
        cout<<setfill('0')<<setw(4)<<a<<" - "<<setfill('0')<<setw(4)<<b<<" = "<<setfill('0')<<setw(4)<<a-b<<'\n';
        x=a-b;
        if(a-b==6174){
            break;
        }
    }
    return 0;
}
