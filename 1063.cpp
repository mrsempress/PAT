#include <iostream>
#include <cstdio>
#include <set>
#include <iomanip>
using namespace std;
const int maxn=1e4+10;
int n,k;
int a,b,c,d;
set<int>s[60];
set<int>::iterator it;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        for(int j=1;j<=a;j++){
            scanf("%d",&b);
            s[i].insert(b);
        }
    }
    scanf("%d",&k);
    while(k--){
        scanf("%d%d",&a,&b);
        c=d=0;
        d=s[a].size();
        for(it=s[b].begin();it!=s[b].end();it++){
            if(s[a].find((*it))!=s[a].end()){
                c++;
            }else d++;
        }
        printf("%.1lf%%\n",c*100.0/d);
    }
    return 0;
}