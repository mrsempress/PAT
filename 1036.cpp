#include <iostream>
#include <string>
using namespace std;
struct stu{
    string name,ID;
    int grade;
}F,M,now;
bool FF,MM;
int n; 
char c;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>now.name>>c>>now.ID>>now.grade;
        if(c=='M'){
            if(!MM){
                MM=true;
                M.grade=now.grade;M.name=now.name;M.ID=now.ID;
            }else if(M.grade>now.grade){
                M.grade=now.grade;M.name=now.name;M.ID=now.ID;
            }
        }else{
            if(!FF){
                FF=true;
                F.grade=now.grade;F.name=now.name;F.ID=now.ID;
            }else if(F.grade<now.grade){
                F.grade=now.grade;F.name=now.name;F.ID=now.ID;
            }
        }
    }
    if(!FF){
        cout<<"Absent\n";
    }else{
        cout<<F.name<<' '<<F.ID<<'\n';
    }
    if(!MM){
        cout<<"Absent\n";
    }else{
        cout<<M.name<<' '<<M.ID<<'\n';
    }
    if(FF&&MM){
        cout<<F.grade-M.grade<<'\n';
    }else{
        cout<<"NA\n";
    }
    return 0;
}