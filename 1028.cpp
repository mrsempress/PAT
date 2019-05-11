#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int maxn=1e5+10;
struct ty{
    string id;
    string name;
    int grades;
}stu[maxn];
bool cmp1(ty a,ty b){
    return a.id<b.id;
}
bool cmp2(ty a,ty b){
    if(a.name==b.name) return a.id<b.id;
    return a.name<b.name;
}
bool cmp3(ty a,ty b){
    if(a.grades==b.grades) return a.id<b.id;
    return a.grades<b.grades;
}
int n,c;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>stu[i].id>>stu[i].name>>stu[i].grades;
    }
    if(c==2){
        sort(stu+1,stu+1+n,cmp2);
        for(int i=1;i<=n;i++){
            cout<<stu[i].id<< ' '<<stu[i].name<<' '<<stu[i].grades<<'\n';
        }
    }else if(c==3){
        sort(stu+1,stu+1+n,cmp3);
        for(int i=1;i<=n;i++){
            cout<<stu[i].id<< ' '<<stu[i].name<<' '<<stu[i].grades<<'\n';
        }
    }else{
        sort(stu+1,stu+1+n,cmp1);
        for(int i=1;i<=n;i++){
            cout<<stu[i].id<< ' '<<stu[i].name<<' '<<stu[i].grades<<'\n';
        }
    }
    return 0;
}