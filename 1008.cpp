#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int now=0;
int n,to;
ll ans=0;
int up=6,down=4;
int main(){
    cin>>n;
    ans+=5*n;
    for(int i=0;i<n;i++){
        cin>>to;
        if(to>now)
            ans+=(to-now)*up;
        else ans+=(now-to)*down;
        now=to;
    }
    cout<<ans<<endl;
    return 0;
}