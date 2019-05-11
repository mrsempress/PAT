// //一根链的时候，比如只含有左子树，则会TLE
// #include <iostream>
// #include <cstdio>
// #include <map>
// using namespace std;
// const int maxn=1e4+10;
// int tot=1,n,m,x,yy;
// map<int,int>pos;
// int pre[maxn];
// void Print(int l,int r,int u,int v){
//     int x=pre[l];
//     if(u==x){
//         printf("%d is an ancestor of %d.\n",u,v);
//         // cout<<u<<" is an ancestor of "<<v<<'.'<<'\n';
//         return ;
//     }if(v==x){
//         printf("%d is an ancestor of %d.\n",v,u);
//         // cout<<v<<" is an ancestor of "<<u<<'.'<<'\n';
//         return ;
//     }
//     int idx=l+1;
//     while(idx<=r&&pre[idx]<x) idx++;

//     if(u<x&&v<x){
//         Print(l+1,idx-1,u,v);
//     }else if(u>x&&v>x){
//         Print(idx,r,u,v);
//     }else{
//         printf("LCA of %d and %d is %d.\n",u,v,x);
//         // cout<<"LCA of "<<u<<" and "<<v<<" is "<<x<<".\n";
//     }
// }

// int main(){
//     // cin>>m>>n;
//     scanf("%d%d",&m,&n);
//     for(int i=1;i<=n;i++){
//         // cin>>x;
//         scanf("%d",&x);
//         pre[i]=x;pos[x]=i;
//     }
//     while(m--){
//         // cin>>x>>yy;
//         scanf("%d%d",&x,&yy);
//         //cout<<x<<" "<<yy<<endl;
//         if(pos[x]==0&&pos[yy]==0){
//             printf("ERROR: %d and %d are not found.\n",x,yy);
//             // cout<<"ERROR: "<<x<<" and "<<yy<<" are not found.\n";
//         }else if(pos[x]==0){
//             printf("ERROR: %d is not found.\n",x);
//             //cout<<"ERROR: "<<x<<" is not found.\n";
//         }else if(pos[yy]==0){
//             printf("ERROR: %d is not found.\n",yy);
//             //cout<<"ERROR: "<<yy<<" is not found.\n"; 
//         }else{
//             Print(1,n,x,yy);
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int,bool> mp;
int main(){
	int m,n,u,v,a;
	cin>>m>>n;
	vector<int> pre(n);
	for (int i=0;i<n;i++){
		cin>>pre[i];
		mp[pre[i]]=true;
	}
	for (int i=0;i<m;i++)
	{
		cin>>u>>v;
		for (int j=0;j<n;j++)
		{
			a=pre[j];
			if ((a>u&&a<v)||(a>v&&a<u)||(a==u)||(a==v))break;
		}
		if (mp[u]==false&&mp[v]==false)
			printf("ERROR: %d and %d are not found.\n",u,v);
		else if (mp[u] == false || mp[v] == false)
			printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
		else if (a == u || a == v)
			printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
		else
			printf("LCA of %d and %d is %d.\n", u, v, a);
	}
	return 0;
}

