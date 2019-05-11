#include <iostream>
#include <cstdio>
using namespace std;
int order[60];
int position[60];//这个位置的数字的编号
int tmp[60];
int n;
void change(){
    for(int i=1;i<=54;i++){
        tmp[order[i]]=position[i];
    }
    for(int i=1;i<=54;i++)
        position[i]=tmp[i];
}
void Print(int id){
    int a=id/13,b=id%13;
    if(b==0) b=13,a--;
    if(a==0){
        cout<<'S';
    }else if(a==1){
        cout<<'H';
    }else if(a==2){
        cout<<'C';
    }else if(a==3){
        cout<<'D';
    }else{
        cout<<'J';
    }
    cout<<b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=54;i++) position[i]=i;
    cin>>n;
    for(int i=1;i<=54;i++) cin>>order[i];
    for(int i=1;i<=n;i++) change();
    // for(int i=1;i<=54;i++){
    //     cout<<position[i]<<" ";
    //     Print(position[i]);cout<<endl;
    // }
    for(int i=1;i<54;i++){
        Print(position[i]);
        cout<<' ';
    }
    Print(position[54]);
    cout<<'\n';
    return 0;
}