#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,p;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int maxm=0;
	for(int i=1;i<=n;i++){
		int temp=upper_bound(a+1,a+1+n,(ll)a[i]*p)-a;
		if((temp-i)>maxm) maxm=temp-i;
	}
	cout<<maxm<<endl;
	return 0;
}



// #include <iostream>
// #include <algorithm>
// #include <set>
// using namespace std;
// typedef long long ll;
// const int maxn=1e5+10;
// int n,p;
// int a[maxn];
// int anslen=0,ansmax=0;
// int mincnt=0,min_tmp=0,max_tmp=0,maxcnt=0;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n>>p;
//     for(int i=1;i<=n;i++) cin>>a[i];
//     int l=1,r=1;
//     mincnt=maxcnt=1;min_tmp=max_tmp=a[1];
//     anslen=1;ansmax=a[1];
//     while(r<=n){
//         r++;
//         if(a[r]>max_tmp){max_tmp=a[r];maxcnt=1;}
//         else if(a[r]==max_tmp){maxcnt++;}

//         if(a[r]<min_tmp){min_tmp=a[r];mincnt=1;}
//         else if(a[r]==min_tmp){mincnt++;}

//         while(max_tmp>(ll)min_tmp*p){
//             if(a[l]==min_tmp) mincnt--;

//         }
//         if(max_tmp<=(ll)min_tmp*p){
//             if(anslen<r-l+1){
//                 anslen=r-l+1;ansmax=max_tmp;
//             }
//             continue;
//         }

        
//     }
// }