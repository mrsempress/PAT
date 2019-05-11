#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
priority_queue<double, vector<double>, greater<double> >q;
int n;
double x,a,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;q.push(x);
    }
    while(!q.empty()){
        a=q.top();q.pop();
        if(!q.empty()){b=q.top();q.pop();}
        else break;

        x=(a+b)/2.0;
        q.push(x);
    }
    
    cout<<(int)a<<'\n';
    return 0;
}
