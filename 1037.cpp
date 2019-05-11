#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
vector<int>p_coupon,n_coupon,p_product,n_product;
int nc,np;
int x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>nc;
    for(int i=0;i<nc;i++){
        cin>>x;
        if(x>0) p_coupon.push_back(x);
        else if(x<0) n_coupon.push_back(x);
    }
    cin>>np;
    for(int i=0;i<np;i++){
        cin>>x;
        if(x>0) p_product.push_back(x);
        else if(x<0) n_product.push_back(x);
    }
    sort(p_coupon.begin(),p_coupon.end());
    sort(n_coupon.begin(),n_coupon.end());
    sort(p_product.begin(),p_product.end());
    sort(n_product.begin(),n_product.end());
    ll ans=0; int lenc,lenp;
    lenc=p_coupon.size();
    lenp=p_product.size();
    int idx=lenc-1,idy=lenp-1;
    while(idx>=0&&idy>=0){
        ans+=(ll)p_coupon[idx]*p_product[idy];
        idx--;idy--;
    }
    lenc=n_coupon.size();
    lenp=n_product.size();
    idx=0,idy=0;
    while(idx<lenc&&idy<lenp){
        ans+=(ll)n_coupon[idx]*n_product[idy];
        idx++;idy++;
    }
    cout<<ans<<'\n';
    return 0;
}