#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n,d;
bool prime(long long x){
    if(x==1) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0) return false;
    }
    return true;
}

bool work(int n,int d){
    if(!prime(n)) return false;
    long long rev=0;
    while(n){
        rev*=10;
        rev+=n%d;
        n/=d;
    }
    long long ans=0,now=1;
    // cout<<rev<<endl;
    while(rev){
        ans+=now*(rev%10);
        rev/=10;
        now*=d;
    }
    // cout<<ans<<endl;
    return prime(ans);
}

int main(){
    int n,d;
    while(cin>>n){
        if(n<0) break;
        cin>>d;
        if(work(n,d))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}