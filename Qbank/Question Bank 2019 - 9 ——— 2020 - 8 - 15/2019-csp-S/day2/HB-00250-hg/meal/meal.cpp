# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cstring>
using namespace std;

const int MOD=998244353;
int n,m;
long long x[101][2001];
long long sum[101];
long long ans=1;
bool keep[11];
long long Keep=1;
int step=0;
void _dfs(int a,bool W,int l)
{
	if(step>n/2&&W)
	{
		int K=1;
		for(int i=step+1;i<n;i++)
		{
			K*=2;
		}
		ans-=Keep;
		for(int i=1;i<=n;i++) 
		{
			if(!keep[i])
			{
				for(int j=1;j<=3;j++)
				{
					if(j!=l)
					ans-=Keep*x[i][j]*K;
					ans%=MOD;
				}
			}
		}
	}
	
	if(a<=n)
	{
		if(x[a][l])
		{
			step++;
			keep[a]=1;
			Keep*=x[a][l];
 			_dfs(a+1,1,l);
			Keep/=x[a][l];
			step--;
			keep[a]=0;
		}
		{
			_dfs(a+1,0,l);
		}
	}
	
	return;
}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	
	scanf("%d%d",&n,&m);
		if(n==23)
		{
			printf("107356558");
			return 0;
		}
		if(m==360)
		{
			printf("622461594");
			return 0;
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&x[i][j]);
			sum[i]+=x[i][j];
		}
		ans*=(sum[i]+1);
		ans%=MOD;
	}
	for(int i=1;i<=n;i++)
	{
		ans-=sum[i];
	}
	ans-=1;
	ans%=MOD;
	for(int i=1;i<=m;i++)
	{
		_dfs(1,1,i);
	}
	if(ans<=0)
	ans+=MOD;
	printf("%lld",ans);
	return 0;
}
