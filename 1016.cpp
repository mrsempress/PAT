#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
set<string>name;
set<string>::iterator it;
map<string,int>customer;
int money[24];
struct node{
    int mon,day,h,m;
    bool on_line;
    bool operator<(const node& o)const{
        if(mon==o.mon){
            if(day==o.day){
                if(h==o.h){
                    return m<o.m;
                }return h<o.h;
            }return day<o.day;
        }return mon<o.mon;
    }
};
vector<node>C[1005];
int n,cnt,id;
string x,y,z;
bool flag;
int mon,day,h,m;
int sum;
double charge(int day1,int h1,int m1,int day2,int h2,int m2){
    double ans;
    if(day1!=day2){
        ans=(60-m1)*money[h1]/100.0;
        for(int i=h1+1;i<24;i++){
            ans+=60*money[i]/100.0;
        }
        for(int i=day1+1;i<day2;i++){
            ans+=sum*60/100.0;
        }
        for(int i=0;i<h2;i++){
            ans+=60*money[i]/100.0;
        }
        ans+=m2*money[h2]/100.0;
        return ans;
    }else{
        if(h1!=h2){
            ans=(60-m1)*money[h1]/100.0;
            for(int i=h1+1;i<h2;i++){
                ans+=60*money[i]/100.0;
            }
            ans+=m2*money[h2]/100.0;
            return ans;
        }else{
            return (m2-m1)*money[h1]/100.0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    sum=0;
    for(int i=0;i<24;i++){
        cin>>money[i];
        sum+=money[i];
    }
    cin>>n;cnt=1;
    for(int i=0;i<n;i++){
        cin>>x>>y>>z;
        name.insert(x);
        if(customer[x]==0){
            customer[x]=cnt;
            cnt++;
        }
        id=customer[x];
        flag=(z=="on-line");
        mon=(y[0]-'0')*10+y[1]-'0';
        day=(y[3]-'0')*10+y[4]-'0';
        h=(y[6]-'0')*10+y[7]-'0';
        m=(y[9]-'0')*10+y[10]-'0';
        C[id].push_back((node){mon,day,h,m,flag});
    }
    
    for(int i=1;i<cnt;i++){
        sort(C[i].begin(),C[i].end());
    }
    
    for(it=name.begin();it!=name.end();it++){
        id=customer[(*it)];
        double total=0;
        flag=false;//flag=0代表需要寻找一个on-line，flag=1代表需要寻找一个off-line
        int len=C[id].size();
        for(int i=0;i<len;i++){
            if(flag==0&&C[id][i].on_line){
                day=C[id][i].day;
                h=C[id][i].h;
                m=C[id][i].m;
                flag=1;
            }else if(flag==1&&!C[id][i].on_line){
                if(total==0){
                    cout<<(*it)<<' '<<setfill('0')<<setw(2)<<C[id][i].mon<<endl;
                }
                mon=(ll)(C[id][i].day*60*24+C[id][i].h*60+C[id][i].m)-(day*60*24+h*60+m);
                double tmp=charge(day,h,m,C[id][i].day,C[id][i].h,C[id][i].m);
                cout<<setfill('0')<<setw(2)<<day<<':'<<setfill('0')<<setw(2)<<h<<':'<<setfill('0')<<setw(2)<<m<<' ';
                cout<<setfill('0')<<setw(2)<<C[id][i].day<<':'<<setfill('0')<<setw(2)<<C[id][i].h<<':'<<setfill('0')<<setw(2)<<C[id][i].m<<' ';
                cout<<mon<<' '<<'$';
                cout.setf(ios::fixed);
                cout<<setprecision(2)<<tmp<<'\n';
                // printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",day,h,m,C[id][i].day,C[id][i].h,C[id][i].m,mon,tmp);
                flag=0;total+=tmp;
            }else if(flag==1){
                day=C[id][i].day;
                h=C[id][i].h;
                m=C[id][i].m;
            }
        }
        if(total!=0){
            cout<<"Total amount: $"<<setprecision(2)<<total*1.00<<'\n';
            // printf("Total amount: $%.2lf\n",total);
        }
    }
    return 0;
}
