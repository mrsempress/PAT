#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct ty{
    double d;double m;
    bool operator<(const ty& o)const{
        return m*o.d>o.m*d;
    }
}mooncake[1005];
int n;
double d;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>mooncake[i].d;
    }
    for(int i=1;i<=n;i++) cin>>mooncake[i].m;
    sort(mooncake+1,mooncake+1+n);
    double now=d;double money=0;
    for(int i=1;i<=n;i++){
        if(now>=mooncake[i].d){
            now-=mooncake[i].d;
            money+=mooncake[i].m;
            //cout<<money<<endl;
        }else{
            money+=mooncake[i].m*now/mooncake[i].d;
            //cout<<money<<endl;
            now=0;
            break;
        }
    }
    //printf("%.2lf\n",money);
    cout.setf(ios::fixed);
    cout<<setprecision(2)<<money*1.00<<'\n';
    return 0;
}