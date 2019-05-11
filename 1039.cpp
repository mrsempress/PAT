#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;
map<string,set<int> >course;
set<int>::iterator it;
int n,k;
int id,num;
string x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>id>>num;
        for(int j=1;j<=num;j++){
            cin>>x;
            course[x].insert(id);
        }
    }
    for(int i=1;i<=n;i++){
        cin>>x;
        int len=course[x].size();
        cout<<x<<" "<<len;
        for(it=course[x].begin();it!=course[x].end();it++){
            cout<<' '<<(*it);
        }
        cout<<'\n';
    }
    return 0;
}