# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;
long long _dfs(long long a,long long b)
{
	if(a==1&&b==1)
	return 0;
	if(a==1&&b==2)
	return 1;
	long long mark=1;
	for(long long i=1;i<=a;i++)
	mark*=2;
	if(b<=mark/2)
	return _dfs(a-1,b);
	else
	{
		return _dfs(a-1,mark+1-b)+mark/2;
	}
	
}
int keep[65];
long long n,k;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&k);
	k++;
	int sum=0;
	long long ans=_dfs(n,k);
	while(ans>0)
	{
		keep[++sum]=ans%2;
		ans/=2;
	}
	for(int i=n;i>sum;i--)
	cout<<"0";
	for(int i=sum;i>=1;i--)
	printf("%d",keep[i]);
	return 0;
}
