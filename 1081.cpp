#include <iostream>
#include <cstdio>
using namespace std;
long long a,b,c=0,d=1,e;
long long zsh=0;
int n;
long long gcd(long long a,long long b){
    if(b!=0) return gcd(b,a%b); 
    else return a;
}
void optimation(){
    long long tmp=gcd(c,d);
    c/=tmp;d/=tmp;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%ld/%ld",&a,&b);
        e=gcd(a,b);
        a/=e;b/=e;
        c=c*b+a*d;
        d=b*d;
        e=gcd(c,d);
        c/=e;d/=e;
    }
    if(c==0) printf("0\n");
    else{
        zsh=c/d;
        c=c%d;
        if(zsh!=0){
            if(c!=0)
            printf("%d %lld/%lld\n",zsh,c,d);
            else printf("%d\n",zsh);
        }
        else  printf("%lld/%lld\n",c,d);
    }
    return 0;
}
 