#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;
int n;
double sum;
double x,b;
string a;
bool flag,f;
int cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        x=0;flag=false;f=false;
        int len=a.length();
        int j=0;b=0;
        if(a[j]=='-') j++,flag=true;
        for(;j<len;j++){
            if(a[j]=='.'){
                if(!f){
                    b=1;f=true;
                }else{
                    break;
                }
            }else if(a[j]<='9'&&a[j]>='0'){
                if(b!=0){
                    b/=10;
                    if(b==0.001) break;
                    x+=(a[j]-'0')*b;
                }else{
                    x*=10;x+=a[j]-'0';

                }
            }else break;
        }
        if(flag) x*=-1;
        if(j>=len&&x<=1000&&x>=-1000){
            sum+=x;cnt++;
        }
        else{
            cout<<"ERROR: "<<a<<" is not a legal number\n";
        }
    }
    cout.setf(ios::fixed);
    if(cnt==0) cout<<"The average of 0 numbers is Undefined\n";
    else if(cnt==1) cout<<"The average of 1 number is "<<setprecision(2)<<sum<<'\n';
    else cout<<"The average of "<<cnt<<" numbers is "<<setprecision(2)<<sum/cnt<<'\n';
    return 0;
}