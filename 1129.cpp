//全部用set处理就可以，不需要用k范围内的处理，每次取前k个就好了，加一次应该是logn的复杂度；
//所以总共是nlogn
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
struct ty{
    int cnt;
    int id;
    int x;
    bool operator<(const ty& o)const{
        if(cnt==o.cnt)  return x<o.x;
        return cnt>o.cnt;
    }
}tmp;
set<ty>s;
set<ty>::iterator it;
int n,k;
int cnt[50005];
int x,tot;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    cin>>x;cnt[x]++;tmp.cnt=1;tmp.id=1;tmp.x=x;s.insert(tmp);
    for(int i=2;i<=n;i++){
        cin>>x;cnt[x]++;
        //cout<<x<<" "<<cnt[x]<<endl;
        cout<<x<<":";
        for(it=s.begin();it!=s.end();it++){
            cout<<' '<<(*it).x;
        }
        cout<<'\n';
        tmp.cnt=cnt[x];tmp.id=i;tmp.x=x;
        tot++;
        if(tot<k){
            bool flag=false;
            //cout<<"tot: "<<tot<<endl;
            //cout<<s.size()<<endl;
            for(it=s.begin();it!=s.end();it++){
                if((*it).x==tmp.x){
                    s.erase(it);
                    s.insert(tmp);
                    flag=true;
                    break;
                }
            }
            if(!flag){
                s.insert(tmp);
                //cout<<s.size()<<endl;
            }
        }else{
            bool flag=false;
            //cout<<"tot: "<<tot<<endl;
            //cout<<s.size()<<endl;
            for(it=s.begin();it!=s.end();it++){
                if((*it).x==tmp.x){
                    s.erase(it);
                    s.insert(tmp);
                    flag=true;
                    break;
                }
            }
            if(!flag){
                it=s.end();it--;
                if(!((*it)<tmp)){
                    s.erase(*it);
                    s.insert(tmp);
                }
            }
        }
//        cout<<i<<": \n";
//        for(it=s.begin();it!=s.end();it++){
//            cout<<(*it).x<<' ';
//        }
//        cout<<endl;
    }
    return 0;
}
