/*
注意，未符合要求的当然不能在算平均数的时候，考虑了呢！
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=1e4+10;
struct node{
    int seconds;//到达时间离00:00：00的秒数
    int process;//处理过程时间
    bool operator<(const node& o)const{
        return seconds<o.seconds;
    }
}customer[maxn];
int windows[105];//每个窗口最后一个人结束的时间
int n,k;
int h,m,s,p;
int maxx;
int main(){
    scanf("%d %d",&n,&k);
    int cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%d:%d:%d %d",&h,&m,&s,&p);
        customer[i].seconds=h*60*60+m*60+s;
        customer[i].process=p*60;
    }
    sort(customer+1,customer+1+n);
    for(int i=1;i<=k;i++){
        windows[i]=8*60*60;
    }
    maxx=17*60*60;
    double ans=0;
    for(int i=1;i<=min(n,k);i++){
        if(customer[i].seconds>maxx) break;
        cnt++;
        ans+=max(windows[i]-customer[i].seconds,0);
        windows[i]=max(windows[i],customer[i].seconds)+customer[i].process;
    }
    for(int i=min(n,k)+1;i<=n;i++){
        if(customer[i].seconds>maxx) break;
        cnt++;
        int tmp=1;
        for(int j=2;j<=k;j++){
            if(windows[tmp]>windows[j]){
                tmp=j;
            }
        }
        ans+=max(windows[tmp]-customer[i].seconds,0);
        windows[tmp]=max(windows[tmp],customer[i].seconds)+customer[i].process;
    }
    ans/=(cnt*60);
    printf("%.1lf\n",ans);
    return 0;
}
