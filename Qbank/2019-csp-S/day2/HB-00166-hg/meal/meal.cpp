# include <cstdio>
const int mod=998244353;
long long read()
{
	long long x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
long long n,m,k,_k;
long long s[2010];
long long a[110][2010];
long long ans;
void dfs(int now,int qian,long long sum)
{
	if(now>k)
	{
		ans=(ans+sum)%mod;
		return;
	}
	for(int i=qian+1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i][j]!=0&&s[j]<_k)
			{
				++s[j];
				long long _sum=(sum*a[i][j])%mod;
				dfs(now+1,i,_sum);
				--s[j];
			}
	return;
}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) a[i][j]=read();
	for(k=2;k<=n;++k)
	{
		_k=k>>1;
		if(k>_k*m) continue;
		dfs(1,0,1);
	}
	printf("%lld",ans);
	return 0;
}
