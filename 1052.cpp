#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
const int maxn=1e6+10;
struct ty{
    int key;
    int nex;
    int add;
    bool vis;
    bool operator<(const ty& o)const{
        return key<o.key;
    }
}node[maxn];
vector<ty>Node;
int n;
int x,a;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a;
    for(int i=1;i<=n;i++){
        cin>>x;
        node[x].add=x;
        cin>>node[x].key;
        cin>>node[x].nex;
        node[x].vis=1;
    }

    while(true){
        if(node[a].vis==0) break;
        Node.push_back(node[a]);
        if(node[a].nex==-1) break;
        a=node[a].nex;
    }
    sort(Node.begin(),Node.end());
    int len=Node.size();
    if(len==0){
        cout<<0<<" "<<-1<<'\n';
    }else{
        cout<<len<<' '<<setfill('0')<<setw(5)<<Node[0].add<<'\n';
        for(int i=1;i<len;i++){
            cout<<setfill('0')<<setw(5)<<Node[i-1].add<<' '<<Node[i-1].key<<' '<<setfill('0')<<setw(5)<<Node[i].add<<'\n';
        }
        cout<<setfill('0')<<setw(5)<<Node[len-1].add<<' '<<Node[len-1].key<<' '<<-1<<'\n';
    }
    return 0;
}