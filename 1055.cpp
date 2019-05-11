#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
struct man{
    string name;
    int age;
    int worth;
    bool operator<(const man& o)const{
        if(worth==o.worth&&age==o.age) return name<o.name;
        if(worth==o.worth) return age<o.age;
        return worth>o.worth;
    }
}P[maxn];
int n,k,m;
int cnt;
int a,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>P[i].name>>P[i].age>>P[i].worth;
    }
    sort(P+1,P+1+n);
    for(int i=1;i<=k;i++){
        cnt=0;
        cin>>m>>a>>b;
        cout<<"Case #"<<i<<":\n";
        for(int j=1;j<=n;j++){
            if(P[j].age<=b&&P[j].age>=a){
                cout<<P[j].name<<' '<<P[j].age<<' '<<P[j].worth<<'\n';
                cnt++;
            }
            if(cnt==m) break;
        }
        if(cnt==0) cout<<"None\n";
    }
    return 0;
}