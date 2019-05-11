// //WA了
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <string>
// using namespace std;
// const int maxn=1e4+10;
// int n,k;
// struct ty{
//     string name;
//     int h;
//     bool operator<(const ty& o)const{
//         if(h!=o.h) return h<o.h;
//         return name>o.name;
//     }
// }node[maxn];
// string b[15];
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n>>k;
//     for(int i=1;i<=n;i++) cin>>node[i].name>>node[i].h;
//     sort(node+1,node+1+n);
//     int l=n/k*k-k+1,r=n;
//     while(true){
//         int tot=(r-l+1);
//         if(tot%2==0){
//             int idx=1;
//             for(int i=l;i<=r;i+=2){
//                 b[idx]=node[i].name;
//                 b[tot-idx+1]=node[i+1].name;
//                 idx++;
//             }
//         }else{
//             int idx=1;
//             for(int i=l;i<r;i+=2){
//                 b[tot-idx+1]=node[i].name;
//                 b[idx]=node[i+1].name;
//                 idx++;
//             }
//             b[idx]=node[r].name;
//         }
//         for(int i=1;i<=tot;i++){
//             if(i==1) cout<<b[i];
//             else cout<<' '<<b[i];
//         }
//         cout<<'\n';
//         if(l==1) break;
//         r=l-1;l=r-k+1;
//     }
//     return 0;
// }

// /*
// 双端队列
// #pragma warning(disable:4996)
// #include <iostream>
// #include <queue>
// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;
// class per {
// public:
// 	string name;
// 	int high;
// };
// vector<per> varr;
// bool cmp(const per& a, const per& b) {
// 	if (a.high == b.high) {
// 		return a.name > b.name;
// 	}
// 	return a.high < b.high;
// }
// deque<string> vname[12];
// int main() {
// 	int n, k;
// 	cin >> n >> k;
// 	for (int i = 0; i < n; ++i) {
// 		per x;
// 		cin >> x.name >> x.high;
// 		varr.push_back(x);
// 	}
// 	sort(varr.begin(), varr.end(), cmp);
// 	int num = n / k;
// 	for (int i = 0; i < k-1; ++i) {
// 		for (int j = num-1; j >=0; --j) {
// 			if ((num-1-j) % 2 == 0) vname[i].push_back(varr[i*num + j].name);
// 			else vname[i].push_front(varr[i*num + j].name);
// 		}
// 	}
// 	for (int j = n-1; j >= (k-1)*num; --j) {
// 		if ((n-1-j) % 2 == 0) vname[k-1].push_back(varr[j].name);
// 		else vname[k-1].push_front(varr[j].name);
// 	}
// 	for (int i = k-1; i >= 0; --i) {
// 		for (int j = 0; j < vname[i].size(); ++j) {
// 			if (j != 0) cout << ' ';
// 			cout << vname[i][j];
// 		}
// 		cout << endl;
// 	}
// 	system("pause");
// 	return 0;
// }


// 中间开始的
// #include<iostream>
// #include<cstdio>
// #include<algorithm>
// using namespace std;
// const int maxn = 1e4+10;
// int group[12][10010];
// int len[14], cnt;
// struct Stu{
// 	string name;
// 	int height;
// }stu[maxn];
// int cmp(Stu a, Stu b){
// 	return a.height != b.height ?  a.height > b.height : a.name < b.name;
// }
// void formGroup(int row, int tot){
// 	int mid = int(tot*1.0/2+1.4);
// 	group[row][mid] = cnt++;
// 	int l = mid-1, r = mid+1;
// 	while(l>=1 || r<=tot){
// 		if(l >= 1) group[row][l--] = cnt++;
// 		if(r <= tot) group[row][r++] = cnt++; 
// 	}
// }
// int main(){
// 	ios::sync_with_stdio(false);
// 	int n, k;
// 	cin >> n >> k;
// 	for(int i = 0; i<n; i++){
// 		cin >> stu[i].name >> stu[i].height;
// 	}
// 	sort(stu, stu+n, cmp);
// 	int m = int(n*1.0/k+0.5);
// 	for(int i = 0; i<k; i++){
// 		len[i] = i == 0 ? n-(k-1)*m : m;
// 		formGroup(i, len[i]);
// 	}
// 	for(int i = 0; i<k; i++){
// 		for(int j = 1; j<=len[i]; j++){
// 			cout << stu[group[i][j]].name;
// 			j != len[i] ? cout << " " : cout << '\n';
// 		}
// 	}
// 	return 0;
// } 
// */