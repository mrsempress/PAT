#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
using namespace std;
vector<int> v1;
vector<int> v2;
int num(string s,int x){
    int i=0;
    int sum=0;
    bool flag=0;
    // 0000.00001
    while(s[i]=='0'||s[i]=='.'){
        if(flag==1)
            sum++;
        if(s[i]=='.')
            flag=1;
		i++;
		if(i>=s.length()-1){
		  if(s[i]=='0') //0000.00000
		    sum=0;
			break;
		}
    }
    if(flag==1)
        sum=-sum;
    for(;i<s.length();i++){
        if(s[i]=='.'){
            flag=1;
            continue;
        }
        if(x==1)
            v1.push_back(s[i]-'0');
        else
            v2.push_back(s[i]-'0');
        if(flag==0)
            sum++;
    }
    return sum;
}
int main(){
    int n;
	scanf("%d",&n);
    string s1,s2;
    cin>>s1>>s2;
    int sum1=num(s1,1);
    int sum2=num(s2,2);
    v1.resize(n,0); //good
    v2.resize(n,0);
    if(sum1==sum2&&v1==v2)
        printf("YES ");
    else
        printf("NO ");
    printf("0.");
    for(int i=0;i<n;i++)
        printf("%d",v1[i]);
    printf("*10^%d",sum1);
	if(sum1!=sum2||v1!=v2){
		printf(" 0.");
		for(int i=0;i<n;i++)
			printf("%d",v2[i]);
		printf("*10^%d",sum2);
    }
}

