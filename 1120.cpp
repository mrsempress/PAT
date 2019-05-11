#include <iostream>
#include <set>
#include <string>
using namespace std;
set<int>ans;
set<int>::iterator it;
int n;
string in;
void to_int(string in){
    int len=in.length();
    int tmp=0;
    for(int i=0;i<len;i++){
        tmp+=in[i]-'0';
    }
    ans.insert(tmp);
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    while(n--){
        cin>>in; to_int(in);
    }
    cout<<ans.size()<<'\n';
    it=ans.begin();
    cout<<(*it);
    for(it++;it!=ans.end();it++){
        cout<<' '<<(*it);
    }
    cout<<'\n';
    return 0;
}