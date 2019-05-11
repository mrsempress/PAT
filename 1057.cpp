//PeekMedian -- return the median "value" of all the elements in the stack. 
// //分块的思想
// #include <iostream>
// #include <string>
// #include <stack>
// using namespace std;
// const int maxn=1e5+10;
// const int sqrn = 316;
// const string a[]={"Push","Pop","PeekMedian","Invalid"};
// stack<int> st;
// int top=0;
// int n,x;
// string b;
// int block[sqrn];
// int table[maxn];
// void peekMedian(int k) {
//     int sum = 0;
//     int idx = 0;
//     while(sum + block[idx] < k) {
//         sum += block[idx++];
//     }
//     int num = idx * sqrn;
//     while(sum + table[num] < k) {
//         sum += table[num++];
//     }
//     cout<<num<<'\n';
// }
// void Push(int x) {
//     st.push(x);
//     block[x / sqrn]++;
//     table[x]++;
// }
// void Pop() {
//     int x = st.top();
//     st.pop();
//     block[x / sqrn]--;
//     table[x]--;
//     cout<<x<<'\n';
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n;
//     while(n--){
//         cin>>b;
//         if(b==a[1]){
//             if(st.size()==0){
//                 cout<<a[3]<<'\n';
//             }else{
//                 Pop();
//             }
//         }else if(b==a[2]){
//             if(st.size()==0){
//                 cout<<a[3]<<'\n';
//             }else{
//                 int k = st.size();
//                 k = (k + 1) / 2;
//                 peekMedian(k);
//             }
//         }else{
//             cin>>x;
//             Push(x);
//         }
//     }
//     return 0;
// }

#include<iostream>
#include<stack>
#define lowbit(i) ((i)&(-i))
using namespace std;
const int maxn = 1e5 + 10;
int c[maxn] = { 0 }, n;
stack<int>st;
void update(int x, int v){
    for (int i = x; i <= maxn; i += lowbit(i))
        c[i] += v;
}

int getsum(int x){
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))ans += c[i];
    return ans;
}

void PeekMedian(int K){
    int l = 0, r = maxn;
    while (l < r){
        int mid = (l + r) / 2;
        if (getsum(mid) >= K)r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
}
int main(){
    scanf("%d", &n);
    while (n--){
        char s[10];
        scanf("%s", s);
        if (s[1] == 'o'){
            if (st.size() == 0)printf("Invalid\n");
            else{
                int x = st.top();
                st.pop();
                update(x, -1);
                printf("%d\n",x);
            }
        }
        else if (s[1] == 'u'){
            int num;
            scanf("%d", &num);
            st.push(num);
            update(num, 1);
        }
        else if (s[1] == 'e'){
            if (st.size() == 0)printf("Invalid\n");
            else{
                int k;
                if (st.size() % 2 == 0)k = st.size() / 2;
                else k = (st.size() + 1) / 2;
                PeekMedian(k);
            }
        }
    }
    return 0;
}