#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int n;string z;
long long a,b,c;
long long to_int(string x,int len,int pos){
    int lens=x.length();
    int tmp=0;
    for(int i=pos;i<pos+len;i++){
        tmp*=10;tmp+=x[i]-'0';
    }
    return tmp;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;//cout<<n<<endl;
    while(n--){
        cin>>z;
        int len=z.length();
        a=to_int(z,len,0);
        b=to_int(z,len/2,0);
        c=to_int(z,len/2,len/2);
        if(b==0||c==0){
            cout<<"No\n";
        }else if(a%(b*c)==0){
            cout<<"Yes\n";
        } else{
            cout<<"No\n";
        }
    }
    return 0;
}