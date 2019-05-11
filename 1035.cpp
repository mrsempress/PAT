#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,m,len;
string name,pwd,new_pwd;
vector<string>ans;
bool flag;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    flag=false;m=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>name>>pwd;
        len=pwd.length();
        new_pwd=name;new_pwd+=' ';
        int cnt=0;
        for(int i=0;i<len;i++){
            if(pwd[i]=='1') new_pwd+='@';
            else if(pwd[i]=='0') new_pwd+='%';
            else if(pwd[i]=='l') new_pwd+='L';
            else if(pwd[i]=='O') new_pwd+='o';
            else{
                cnt++;
                new_pwd+=pwd[i];
            }
        }
        if(cnt<len){
            flag=true;m++;
            ans.push_back(new_pwd);
        }
    }
    if(!flag){
        if(n==1){
            cout<<"There is 1 account and no account is modified\n";
        }else{
            cout<<"There are "<<n<<" accounts and no account is modified\n";
        }
    }else{
        cout<<m<<'\n';
        for(int i=0;i<m;i++){
            cout<<ans[i]<<'\n';
        }
    }
    return 0;
}