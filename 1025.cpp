#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int maxn=3e4+10;
struct node{
    string id;
    int l_number;
    int l_rank;
    int grades;
    bool operator<(const node& o)const{
        if(grades==o.grades)
            return id<o.id;
        return grades>o.grades;
    }
}stu[maxn];
struct ty{
    string id;
    int grades;
    bool operator<(const ty& o)const{
        if(grades==o.grades)
            return id<o.id;
        return grades>o.grades;
    }
}st[305];
int n,k,tot;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    tot=0;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>st[j].id>>st[j].grades;
        }
        sort(st+1,st+1+k);
        int la=st[1].grades,lb=1;
        for(int j=1;j<=k;j++){
            if(st[j].grades!=la){
                la=st[j].grades;
                lb=j;
            }
            stu[++tot].id=st[j].id;
            stu[tot].l_number=i;
            stu[tot].l_rank=lb;
            stu[tot].grades=la;
        }
    }
    sort(stu+1,stu+tot+1);
    cout<<tot<<'\n';
    int la=stu[1].grades,lb=1;
    for(int i=1;i<=tot;i++){
        if(stu[i].grades!=la){
            la=stu[i].grades;
            lb=i;
        }
        cout<<stu[i].id<<' '<<lb<<' '<<stu[i].l_number<<' '<<stu[i].l_rank<<'\n';
    }
    return 0;
}