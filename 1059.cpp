#include <cstdio>
using namespace std;
long int N;
int cnt;
bool first;
void Print(long int x,int times){
    if(first) printf("*");
    if(times==1) printf("%ld",x);
    else printf("%ld^%d",x,times);
}
int main(){
    scanf("%ld",&N);
    printf("%ld=",N);
    if(N==1||N==0){
        printf("%ld\n",N);
        return 0;
    }
    first=false;
    cnt=0;
    while(N%2==0){
        N/=2;
        cnt++;
    }
    if(cnt!=0){
        Print(2,cnt);
        first=true;
    }

    for(int i=3;(long long)i*i<=N;i+=2){
        cnt=0;
        if(N%i==0){
            while(N%i==0){
                N/=i;
                cnt++;
            }
            Print(i,cnt);
            first=true;
        }
    }
    if(N!=1) Print(N,1);
    printf("\n");
    return 0;
}