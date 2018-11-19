#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
bool a[1005];
map<int,double>ans;
int main(){
    // memset(a,0,sizeof(a));
    int k,n;
    double an;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>n>>an;
        if(!a[n]){
            ans[n]=an;
            a[n]=1;
        }
        else ans[n]+=an;
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>n>>an;
        if(!a[n]){
            ans[n]=an;
            a[n]=1;
        }
        else ans[n]+=an;
    }
    int len=0;
    for(int i=0;i<=1000;i++){
        if(a[i]==1&&ans[i]!=0) len++;
    }
    printf("%d",len);
    for(int i=1000;i>=0;i--){
        if(a[i]==1&&ans[i]!=0) 
            printf(" %d %.1f",i,ans[i]);
    }
    printf("\n");
    return 0;
}