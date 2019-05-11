#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a,b;
bool check(string x){
    int len=x.length();
    int i=0,j=len-1;
    while(i<j){
        if(x[i]!=x[j]) return false;
        i++;j--;
    }
    return true;
}
void add(string &x,string y){
    int len=x.length();
    int add=0;
    string tmp="";int c;
    for(int i=len-1;i>=0;i--){
        c=x[i]-'0'+y[i]-'0'+add;
        tmp+=(char)(c%10+'0');
        add=c/10;
    }
    if(add) tmp+=(char)(add+'0');
    reverse(tmp.begin(),tmp.end());
    x=tmp;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a;
    for(int i=0;i<10;i++){
        if(check(a)){
            cout<<a<<" is a palindromic number.\n";
            return 0;
        }
        b=a;
        reverse(a.begin(),a.end());
        cout<<b<<" + "<<a<<" = ";
        add(a,b);
        cout<<a<<'\n';
    }
    cout<<"Not found in 10 iterations.\n";
    return 0;
}