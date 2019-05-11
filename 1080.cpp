#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=4e4+10;
int n,m,k;
int choose[maxn][6];
int school[105];
int rankschool[105];//进这个学校的最后一个人的rank的值
vector<int>ans[105];
int a,b;
struct ty{
    int ge,gi;
    int f;
    int id;
    bool operator<(const ty& o)const{
        if(o.f!=f) return f>o.f;
        return ge>o.ge;
    }
}stu[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(rankschool,-1,sizeof(rankschool));
    cin>>n>>m>>k;
    for(int i=0;i<m;i++) cin>>school[i];
    for(int i=0;i<n;i++){
        cin>>stu[i].ge>>stu[i].gi;
        stu[i].f=stu[i].ge+stu[i].gi;
        stu[i].id=i;
        for(int j=0;j<k;j++){
            cin>>choose[i][j];
        }
    }
    sort(stu,stu+n);
    int rank=-1;int ge=0,f=0;
    for(int i=0;i<n;i++){
        //cout<<stu[i].id<<" "<<stu[i].f<<' '<<f<<' '<<stu[i].ge<<' '<<ge<<" ";
        if(!(stu[i].f==f&&stu[i].ge==ge)){
            rank=i;f=stu[i].f;ge=stu[i].ge;
        }
        //cout<<rank<<endl;
        for(int j=0;j<k;j++){
            //cout<<stu[i].id<<" "<<choose[stu[i].id][j]<<" "<<school[choose[stu[i].id][j]]<<" "<<rankschool[choose[stu[i].id][j]]<<endl;
            if(school[choose[stu[i].id][j]]){
                school[choose[stu[i].id][j]]--;
                ans[choose[stu[i].id][j]].push_back(stu[i].id);
                rankschool[choose[stu[i].id][j]]=rank;
                break;
            }else if(rankschool[choose[stu[i].id][j]]==rank){
                ans[choose[stu[i].id][j]].push_back(stu[i].id);
                break;
            }
        }
    }
    for(int i=0;i<m;i++){
        int size=ans[i].size();
        sort(ans[i].begin(),ans[i].end());
        for(int j=0;j<size;j++){
            if(!j) cout<<ans[i][j];
            else cout<<' '<<ans[i][j];
        }
        cout<<'\n';
    }
    return 0;
}