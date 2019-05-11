//AC
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const string a[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
const string b[]={"Yi","Qian","Bai","Shi","Wan","Qian","Bai","Shi",""};
vector<string>ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string in;
    cin>>in;
    int len=in.length();
    int i=0;
    if(in[i]=='-') ans.push_back("Fu"),i++;
    int cnt=9-len+i;
    bool f=false;
    bool flag=false;
    int no=cnt-1;
    for(;i<len;i++){
        if(!i){
            if(in[i]=='0'){
                if(cnt==0) {ans.push_back("Yi");flag=true;}
                else if(no>0&&cnt==4) {ans.push_back("Wan");flag=true;}
                else f=true;
            }else{
                if(!f){
                ans.push_back(a[in[i]-'0']);ans.push_back(b[cnt]);flag=true;}
                else {ans.push_back("ling");ans.push_back(a[in[i]-'0']);ans.push_back(b[cnt]);flag=true;}
                f=false;
                no=cnt;
            }
            
        }
        else{
            if(in[i]=='0'){
                if(no>0&&cnt==4) {ans.push_back("Wan");flag=true;}
                else if(cnt==0) {ans.push_back("Yi");flag=true;}
                else f=true;
            }
            else{
                if(!f){
                ans.push_back(a[in[i]-'0']);ans.push_back(b[cnt]);flag=true;}
                else {ans.push_back("ling");ans.push_back(a[in[i]-'0']);ans.push_back(b[cnt]);flag=true;}
                f=false;
                no=cnt;
            }
        }
        cnt++;
    }
    if(!flag){
        if(in[0]=='-')
            cout<<"Fu ling";
        else cout<<"ling";
    }else{
        int len=ans.size();
        int cnt=0;
        for(int i=0;i<len;i++){
            if(ans[i]!=""){
                if(!cnt){
                    cout<<ans[i];cnt++;
                }else cout<<' '<<ans[i];
            }
        }
    }
    cout<<'\n';
    return 0;
}

//AC
//以四个为一个循环的
// #include <iostream>
// #include <vector>
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// using namespace std;
 
// int main()
// {
//     string str;
//     cin>>str;
//     string a[]={"","yi","er","san","si","wu","liu","qi","ba","jiu"};
//     string b[] = { "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi" };
//     vector<string> vec;
//     for(int i=str.size()-1,k=0;i>=0;i--,k++)
//     {
//     	if(str[i] == '0'){
//     		if(k == 4){
//     			string s = str.substr(0,i+1);//判断是否需要加"Wan",比如一亿
//     			int n = abs(stoi(s));
//     			if(n % 10000){//如101000000,需要加,100000010不需要
//     				vec.push_back("Wan");
//     			}
//     		}
//     		if(vec.empty() || vec[vec.size()-1] == "ling" || vec[vec.size()-1] == "Wan")
//     		{
// 				continue;
//     		}
//     		vec.push_back("ling");
//     		continue;
//     	}
//     	if(str[i] == '-'){
//     		vec.push_back("Fu");
//     		break;
//     	}
//         if(k)
//             vec.push_back(b[k]);
//         vec.push_back(a[str[i]-'0']);
//     }
 
// 	for(int i=vec.size()-1;i>=0;i--)
// 	{
// 		cout<<vec[i];
// 		if(i != 0)
// 			cout<<" ";
// 	}
// 	if(vec.size() == 0)
//         cout<<"ling";
 
//     return 0;
// }