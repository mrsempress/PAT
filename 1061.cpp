#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;
const string week[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
    ios::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    int lena=a.length();
    int lenb=b.length();
    int i;
    for(i=0;i<lena&&i<lenb;i++){
        if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G'){
            cout<<week[a[i]-'A']<<' ';
            break;
        }
    }
    for(i++;i<lena&&i<lenb;i++){
        if(a[i]==b[i]){
            if(a[i]>='0'&&a[i]<='9'){
                cout<<0<<a[i]<<":";
            }else if(a[i]>='A'&&a[i]<='N'){
                //cout<<a[i]<<" "<<a[i]-'A'+10<<endl;
                cout<<to_string(a[i]-'A'+10)<<":";
            }
            else{
                continue;
            }
            break;
        }
    }

    cin>>a>>b;
    lena=a.length();
    lenb=b.length();
    for(i=0;i<lena&&i<lenb;i++){
        if(a[i]==b[i]&&isalpha(a[i])){
            cout<<setfill('0')<<setw(2)<<i<<'\n';
            break;
        }
    }
    return 0;
}