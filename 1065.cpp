/*
判断a+b是否大于c。
这里需要注意的是a+b可能溢出，如果a大于0且b大于0，但相加得到的却是小于等于0的说明是正溢出，这时肯定比c大（因为c肯定在long long的范围内）。
如果a小于0且b小于0，但相加得到的却是大于等于0的说明是负溢出，这是肯定比c小。
其他情况就和平常计算一样。这里还要注意a+b要赋值给一个变量再和c比较。
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;
 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		bool istrue;
		long long res=a+b;
		if(a>0&&b>0&&res<=0) istrue=true;
		else if(a<0&&b<0&&res>=0) istrue=false;
		else if(res>c) istrue=true;
		else istrue=false;
		printf("Case #%d: %s\n",i,istrue?"true":"false");
	}
}

