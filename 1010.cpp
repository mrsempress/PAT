#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
string N1,N2;
int tag,radix;
ll work(string x, ll r){
    int len=x.length();
    ll tmp=1,ans=0;
    for(int i=len-1;i>=0;i--){
        if(x[i]<='9'&&x[i]>='0')
            ans+=tmp*(x[i]-'0');
        else
            ans+=tmp*(x[i]-'a'+10);
        tmp*=r;
    }
    return ans;
}

int main(){
    cin>>N1>>N2>>tag>>radix;
    if(tag==2){
        swap(N1,N2);
    }

    ll n1 = work(N1, radix);
    ll n2;
    char it=*max_element(N2.begin(),N2.end());
    ll l=(isdigit(it)?it-'0':it-'a'+10)+1,r=max(n1,l);
    int ans=-1;
    while(l<=r){
        ll mid=(l+r)/2;
        n2=work(N2,mid);
        if(n2>n1||n2<0) r=mid-1;    //n2<0表示溢出
        else if(n2==n1){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    if(ans==-1) cout<<"Impossible\n";
    else cout<<ans<<'\n';
    return 0;
}