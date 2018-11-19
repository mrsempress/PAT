#include <iostream>
#include <vector>
using namespace std;
vector<int>layer[35];
int posor[35],inor[35];
int N;
void dfs(int l,int r,int L,int R,int cnt){
    if(l>r||L>R) return ;
    N=max(N,cnt);
    int now=posor[r];layer[cnt].push_back(now);
    for(int i=L;i<=R;i++){
        if(inor[i]==now){
            dfs(l,l+i-L-1,L,i-1,cnt+1);
            dfs(l+i-L,r-1,i+1,R,cnt+1);
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    N=0;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>posor[i];
    }
    for(int i=0;i<n;i++) cin>>inor[i];

    dfs(0,n-1,0,n-1,1);
    for(int i=1;i<N;i++){
        int len=layer[i].size();
        for(int j=0;j<len;j++){
            cout<<layer[i][j]<<' ';
        }
    }
    int len=layer[N].size();
    for(int j=0;j<len-1;j++){
        cout<<layer[N][j]<<' ';
    }
    cout<<layer[N][len-1]<<'\n';
    return 0;
}
