#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>a;
vector<int>ans;
int n,m,x,len;
long long sum=0;
bool flag=false;
void dfs(int idx,int now_sum){//return的顺序很重要呀！！！
    if(flag) return ;
    if(now_sum==m){
        flag=true;
        int len=ans.size();
        for(int i=0;i<len;i++){
            if(!i) cout<<ans[i];
            else cout<<' '<<ans[i];
        }
        cout<<'\n';
        return ;
    }
    if(idx>=len) return ;
    for(int i=idx;i<len;i++){
        if(now_sum+a[i]>m) break;
        //if(now_sum+a[len-1]*(len-idx)<m) break;
        ans.push_back(a[i]);
        dfs(i+1,now_sum+a[i]);
        if(flag) return ;
        ans.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x>m) continue;
        sum+=x;a.push_back(x);
    }
    len=a.size();
    if(sum<m||len==0){
        cout<<"No Solution\n";
        return 0;
    }
    sort(a.begin(),a.end());
    if(a[len-1]*n<m){
        cout<<"No Solution\n";
        return 0;
    }
    dfs(0,0);
    if(!flag){
        cout<<"No Solution\n";
    }
    return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int dp[10010], w[10010];
// bool choice[10010][110];
// int cmp1(int a, int b){return a > b;}
// int main() {
//     int n, m;
//     scanf("%d%d", &n, &m);
//     for(int i = 1; i <= n; i++)
//         scanf("%d", &w[i]);
//     sort(w + 1, w + n + 1, cmp1);
//     for(int i = 1; i <= n; i++) {
//         for(int j = m; j >= w[i]; j--) {
//             if(dp[j] <= dp[j-w[i]] + w[i]) {
//                 choice[i][j] = true;
//                 dp[j] = dp[j-w[i]] + w[i];
//             }
//         }
//     }
//     if(dp[m] != m) printf("No Solution");
//     else {
//         vector<int> arr;
//         int v = m, index = n;
//         while(v > 0) {
//             if(choice[index][v] == true) {
//                 arr.push_back(w[index]);
//                 v -= w[index];
//             }
//             index--;
//         }
//         for(int i = 0; i < arr.size(); i++) {
//             if(i != 0) printf(" ");
//             printf("%d", arr[i]);
//         }
//     }
//     return 0;
// }

