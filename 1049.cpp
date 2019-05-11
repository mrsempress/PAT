#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
long long n,ans,lefts,rights,now;
long long base=10;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    while(true){
        lefts=n/base;
        now=n/(base/10)%10;
        rights=n%(base/10);
        if(rights==n) break;
        if(now==0){
            ans+=lefts*(base/10);
        }else if(now==1){
            ans+=lefts*(base/10)+rights+1;
        }else{
            ans+=(lefts+1)*(base/10);
        }
        base*=10;
    }
    cout<<ans<<'\n';
    return 0;
}