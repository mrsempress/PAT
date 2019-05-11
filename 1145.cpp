#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1e5+10005;
int isprime[maxn];
int pos[maxn];
bool f[maxn];
int t,n,m,x,tot;
void Prime(){
    isprime[0]=-1;isprime[1]=-1;
    isprime[2]=1;int tmp=2;
    while(2*tmp<n+10000){
        isprime[2*tmp]=-1; tmp++;
    }
    for(int i=3;i<n+10000;i+=2){
        if(isprime[i]!=-1){
            isprime[i]=1;
            tmp=2;
            while(i*tmp<n+10000){
                isprime[i*tmp]=-1;
                tmp++;
            }
        }
    }
}
// bool Prime(int num){
//     if(num<2) return false;
//     if(num==2) return true;
//     if(num%2==0) return false;
//     for(int i=3;i*i<=num;i+=2){
//         if(num%i==0) return false;
//     }
//     return true;
// }

int main(){   
    memset(pos,-1,sizeof(pos));
    scanf("%d%d%d",&t,&n,&m);
    Prime();
    if(isprime[t]!=1){
        for(int i=t+1;i<maxn;i++){
            if(isprime[i]==1){
                t=i;break;
            }
        }
    }
    //while(Prime(t)==false) t++;
    // cout<<"t: "<<t<<endl;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        bool flag=false;
        for(int j=0;j<t;j++){
            if(f[(j*j+x%t)%t]==false){
                f[(j*j+x%t)%t]=true;
                pos[x]=(j*j+x%t)%t;
                flag=true;
                break;
            }
        }
        if(!flag){
            printf("%d cannot be inserted.\n",x);
        }
        //cout<<x<<" "<<pos[x]<<endl;
    }

    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        bool flag=false;
        for(int j=0;j<t;j++){
            tot++;
            if(f[(j*j+x%t)%t]==false){
                flag=true;
                break;
            }
            if(pos[x]==(j*j+x%t)%t){
                flag=true;
                break;
            }
        }
        if(!flag) tot++;
        //cout<<x<<" "<<tot<<endl;
    }
    printf("%.1f\n",tot*1.0/m);
    return 0;
}
