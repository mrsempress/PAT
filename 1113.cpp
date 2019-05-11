#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=1e5+10;
int n,x;
vector<int>v;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) {cin>>x;v.push_back(x);}
    sort(v.begin(),v.end());
    

    int s1=0,s2=0;
    for(int i=0;i<n/2;i++){
        s1+=v[i];
    }

    for(int i=0;i<n/2;i++){
        s2+=v[n-1-i];
    }

    if(n%2==0){
        cout<<"0 "<<s2-s1<<'\n';
    }
    else{
        cout<<"1 "<<s2+v[n/2]-s1<<'\n';
    }
    return 0;
}