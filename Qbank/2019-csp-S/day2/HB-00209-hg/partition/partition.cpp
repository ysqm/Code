#include<iostream>
#include<cstdio>
using namespace std;
const int M=5e3+10;
int a[M];
long long s[M],ans=999999999999;
int m;
long long f(long long x)
{
	long long s=x*x;
	return s;
}
int b[M],tot;
long long t;
void dfs(int step,long long p,long long sum)
{
	if(t>5e5) return;
	t++;
	if(sum>ans) return;
	if(step==m) ans=min(ans,sum);
	for(int i=step+1;i<=m;i++)
	{
		if(s[i]-s[step]>=p)
		dfs(i,s[i]-s[step],sum+f(s[i]-s[step]));
	}
}
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int n;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	cin>>a[i],s[i]=s[i-1]+a[i];
	for(int i=0;i<m;i++)
	{
		t=0;
		dfs(i,s[i],f(s[i]));
	}
	cout<<ans;
	return 0;
}
