#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const string digit[10] = {"zero","one","two","three","four",
"five","six","seven","eight","nine"};
int main(){
    string x;
    cin>>x;
    int len=x.length();
    int sum=0;
    for(int i=0;i<len;i++){
        sum+=x[i]-'0';
    }
    string ans=to_string(sum);
    len=ans.length();
    cout<<digit[ans[0]-'0'];
    for(int i=1;i<len;i++){
        cout<<" "<<digit[ans[i]-'0'];
    }
    cout<<endl;
    return 0;
}