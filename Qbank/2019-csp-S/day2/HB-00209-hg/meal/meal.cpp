#include<iostream>
#include<cstdio>
using namespace std;
const int M=2000;
const int mod=998244353;
int a[M][M];
int m,n,k;
long long ans;
int book2[M];
void dfs(int step,int p,long long sum)
{
	if(step==k+1)
	{
		ans+=sum;
		ans%=mod;
	}
	for(int i=p+1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(book2[j]<(k/2)&&a[i][j]!=0)
			{
				book2[j]++;
				dfs(step+1,i,(sum*a[i][j])%mod);
				book2[j]--;
			}
		}
	}
}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		cin>>a[i][j];
	}
	for(k=2;k<=m;k++)
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
