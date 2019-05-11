// -12.10E-3
// 0.00000121412E+10
#include <iostream>
#include <string>
using namespace std;
string in;
int idx,len;
int exps;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>in;len=in.length();
    while(in[idx]!='E') idx++;
    for(int i=idx+1;i<len;i++){
        if(in[i]<='9'&&in[i]>='0'){
            exps*=10;exps+=in[i]-'0';
        }
    }
    if(in[idx+1]=='-') exps*=-1;

    if(exps<0){
        int i=0;
        if(in[i]=='-') cout<<in[i++];
        else if(in[i]=='+') i++;

        int j=0;
        while(in[i+j]!='.') j++;

        if(j>=-exps){
            for(int k=0;k<j+exps;k++){
                cout<<in[i++];
            }
            if(j==-exps) cout<<'0';
            cout<<'.';
            while(i<idx){
                if(in[i]=='.') i++;
                else cout<<in[i++];
            }
            cout<<'\n';
        }
        else{
            cout<<"0.";
            for(int k=0;k<-(j+exps);k++){
                cout<<'0';
            }
            while(i<idx){
                if(in[i]=='.') i++;
                else cout<<in[i++];
            }
            cout<<'\n';
        }
    }else if(exps==0){
        for(int i=0;i<idx;i++){
            cout<<in[i];
        }
        cout<<'\n';
    }else{
        int i=0;
        if(in[i]=='-') cout<<in[i++];
        else if(in[i]=='+') i++;

        bool flag=false;
        while(in[i]!='.'){
            if(in[i]!='0') flag=true;
            if(flag)
                cout<<in[i];
            i++;
        }
        i++;
        if(!flag){
            while(in[i]=='0'&&exps){
                i++;exps--;
            }
        }
        while(i<idx&&exps){
            cout<<in[i++];exps--;
        }
        while(exps>0){cout<<'0';exps--;}
        if(i<idx){
            cout<<'.';
            while(i<idx){
                if(in[i]=='.') i++;
                cout<<in[i++];
            }
        }
        cout<<'\n';
    }
    return 0;
}