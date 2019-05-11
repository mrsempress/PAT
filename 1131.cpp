#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
const int maxn=100;
const int maxx=1e4+10;
set<int>id[maxx];//每个id所在的Line
int n,k;
int m[maxn];
int station[maxn][maxn];
int st[maxx];
vector<pair<int, int> >ans;
int a,b;
int ans_changes,ans_times;
void dfs(int now,int to,int changes，int times){
    if(now==to){
        if(times<ans_times||(times==ans_times&&changes<ans_changes)){
            ans.clear();
            
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i];
        for(int j=1;j<=m[i];j++){
            cin>>station[i][j];
            id[station[i][j]].insert(i);
        }
    }
    cin>>k;
    while(k--){
        cin>>a>>b;

    }

}