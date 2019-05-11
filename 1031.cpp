#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string in;cin>>in;
    int N=in.length();
    int n1,n2;
    if(N%3==1){
        n1=n2=(N+2)/3;
    }else if(N%3==2){
        n2=(N+4)/3;
        n1=(N+1)/3;
    }else{
        n2=(N+6)/3;
        n1=N/3;
    }
    int idx=0;
    for(int i=1;i<n1;i++){
        cout<<in[idx];
        for(int j=2;j<n2;j++){
            cout<<' '; 
        }
        cout<<in[N-idx-1]<<'\n';
        idx++;
    }
    for(int i=1;i<=n2;i++){
        cout<<in[idx++];
    }
    cout<<'\n';
    return 0;
}