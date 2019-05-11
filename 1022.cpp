/*
注意ID七位数，用int保存的时候前面的0会丢失
*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <iomanip>
using namespace std;
const int maxn=1e4+10;
map<string,int>x[6];//给不同的title编号
set<int>y[6][maxn];//相同title编号的ID号
set<int>::iterator it;
int bianhao[6];
int n,ID;
string in;
void work(int id,string z,int t){
    if(t==3){
        int idx=0;int len=z.length();
        string w="";
        while(idx<=len){
            if(z[idx]==' '||idx==len){
                if(x[t][w]==0){
                    x[t][w]=++bianhao[t];
                    y[t][bianhao[t]].insert(id);
                }else{
                    y[t][x[t][w]].insert(id);
                }
                w="";
            }else{
                w+=z[idx];
            }
            idx++;
        }
        return ;
    }
    if(x[t][z]==0){
        x[t][z]=++bianhao[t];
        y[t][bianhao[t]].insert(id);
    }else{
        y[t][x[t][z]].insert(id);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ID;
        cin.get();
        for(int j=1;j<=5;j++){
            getline(cin,in);
            work(ID,in,j);
        }
    }
//    cout<<x[3]["test"]<<'\n';
//    cout<<x[3]["code"]<<'\n';
//    cout<<x[3]["debug"]<<'\n';
//    cout<<x[3]["sort"]<<'\n';
//    cout<<x[3]["keywords"]<<'\n';
    int m;cin>>m;
    string tmp;int temp;
    while(m--){
        cin>>tmp;
        cin.get();
        getline(cin,in);
        cout<<tmp<<' '<<in<<'\n';
        temp=x[tmp[0]-'0'][in];
        it=y[tmp[0]-'0'][temp].begin();
        if(it==y[tmp[0]-'0'][temp].end()){
            cout<<"Not Found\n";
        }else{
            for(;it!=y[tmp[0]-'0'][temp].end();it++){
                cout<<setfill('0')<<setw(7)<<(*it)<<'\n';
            }
        }
    }
    return 0;
}
