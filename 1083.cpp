#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
struct ty{
    string name;
    string course;
}tmp,grades[105];
int n,x,a,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tmp.name>>tmp.course>>x;
        grades[x]=tmp;
    }
    cin>>a>>b;
    bool flag=false;
    for(int i=b;i>=a;i--){
        if(grades[i].name!=""){
            cout<<grades[i].name<<' '<<grades[i].course<<'\n';
            flag=true;
        }
    }
    if(!flag){
        cout<<"NONE\n";
    }
    return 0;
}