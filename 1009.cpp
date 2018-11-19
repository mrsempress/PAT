#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool vis[2005];
double exp[2005];
pair<int,double>a[15],b[15];
int k1,k2;
int x;double y;
int main(){
    cin>>k1;
    for(int i=0;i<k1;i++){
        cin>>a[i].first>>a[i].second;
    }
    cin>>k2;
    for(int i=0;i<k2;i++){
        cin>>b[i].first>>b[i].second;
    }
    for(int i=0;i<k1;i++){
        for(int j=0;j<k2;j++){
            x=a[i].first+b[j].first;
            y=a[i].second*b[j].second;
            vis[x]=1;exp[x]+=y;
        }
    }
    int len=0;
    for(int i=0;i<=2000;i++){
        if(vis[i]&&exp[i]!=0) len++;
    }
    printf("%d",len);
    for(int i=2000;i>=0;i--){
        if(vis[i]&&exp[i]!=0)
            printf(" %d %.1f",i,exp[i]);
    }
    printf("\n");
    return 0;
}