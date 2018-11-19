#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=2005;
struct grade{
    double num;
    int id;
    bool operator<(const grade& o)const{
        return num>o.num;
    }
}C[maxn],M[maxn],E[maxn],A[maxn];
map<string,int>student;
map<int,string>res;
map<string,pair<int, char> >ans;
int n,m;
string name;
int c,mm,e;
void work(char x,double last,grade yy[]){
    int rank=1;
    for(int i=1;i<=n;i++){
        name=res[yy[i].id];
        if(yy[i].num!=last){
            rank=i;last=yy[i].num;
        }
        
        if(ans[name].first!=0&&ans[name].first<=rank) continue;
        else{
            ans[name].first=rank;
            ans[name].second=x;
        }
        // cout<<x<<" "<<rank<<" "<<name<<" "<<ans[name].first<<" "<<ans[name].second<<endl;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>name>>c>>mm>>e;
        student[name]=i;res[i]=name;
        C[i].id=i;C[i].num=c;
        M[i].id=i;M[i].num=mm;
        E[i].id=i;E[i].num=e;
        A[i].id=i;A[i].num=(c+mm+e)/3.0;
    }
    sort(C+1,C+1+n);
    sort(M+1,M+1+n);
    sort(E+1,E+1+n);
    sort(A+1,A+1+n);
    
    work('A',A[1].num,A);
    work('C',C[1].num,C);
    work('M',M[1].num,M);
    work('E',E[1].num,E);
    
    
    while(m--){
        cin>>name;
        if(ans[name].first<=0){
            cout<<"N/A"<<endl;
        }else{
            cout<<ans[name].first<<' '<<ans[name].second<<endl;
        }
    }
    return 0;
}
