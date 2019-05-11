#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=1e5+10;
map<string,int>mm;
struct ty{
    string name;
    int sa,sb,st;
    int num;
    int total;
    bool operator<(const ty& o)const{
        if(total==o.total){
            if(num==o.num) return name<o.name;
            return num<o.num;
        }
        return total>o.total;
    }
}u[maxn];
string name,university;
int score,n,cnt=0,x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>name>>score>>university;
        int len=university.length();
        for(int j=0;j<len;j++){
            if(university[j]>='A'&&university[j]<='Z'){
                university[j]+='a'-'A';
            }
        }
        // cout<<name<<" "<<score<<" "<<university<<endl;
        x=mm[university];
        if(x==0){
            mm[university]=++cnt;
            x=cnt;
        }
        u[x].name=university;u[x].num++;
        // cout<<u[x].name<<" "<<u[x].num<<endl;
        if(name[0]=='A'){ 
            u[x].sa+=score;
        }else if(name[0]=='B'){
            u[x].sb+=score; 
        }else{
            u[x].st+=score;
        }
    }
    for(int i=1;i<=cnt;i++){
        u[i].total=u[i].sb/1.5+u[i].sa+u[i].st*1.5;
    }
    sort(u+1,u+1+cnt);
    cout<<cnt<<'\n';
    int rank=1;
    for(int i=1;i<=cnt;i++){
        rank=i;
        cout<<rank<<' '<<u[i].name<<' '<<u[i].total<<' '<<u[i].num<<'\n';
        while(i+1<=cnt&&u[i].total==u[i+1].total){
            i++;cout<<rank<<' '<<u[i].name<<' '<<u[i].total<<' '<<u[i].num<<'\n';
        }
    }
    return 0;
}