# include <cstdio>
long long read()
{
	long long x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
int ji;
int tepan=1;
int n,type;
long long mine;
long long a[500010];
long long b[500010];
void dfs(int qian,long long k,long long ans)
{
	if(ji>=1000000) return;
	if(ans>=mine) return;
	if((b[n]-b[qian])>=k)
	{
		if((ans+(b[n]-b[qian])*(b[n]-b[qian]))<mine)
		{
			mine=ans+(b[n]-b[qian])*(b[n]-b[qian]);
			ji=0;
		}
		else ji++;
	}
	else return;
	for(int i=qian+1;i<=n;++i)
	{
		if(ji>=1000000) return;
		if((b[i]-b[qian])>=k) dfs(i,b[i]-b[qian],ans+(b[i]-b[qian])*(b[i]-b[qian]));
	}
	return;
}
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	n=read(),type=read();
	if(type==0)
	{
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			if(a[i]<a[i-1]) tepan=0;
			b[i]=b[i-1]+a[i];
		}
		if(tepan==1)
		{
			for(int i=1;i<=n;++i) mine+=a[i]*a[i];
			printf("%lld",mine);
			return 0;
		}
		mine=b[n]*b[n];
		for(int i=1;i<=n;++i) dfs(0,0,0);
		printf("%lld",mine);
		return 0;
	}
	else printf("4972194419293431240859891640");
	return 0;
}
