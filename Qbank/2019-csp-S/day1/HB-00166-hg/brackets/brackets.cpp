# include <cstdio>
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
int n;
char c;
int fa[500010];
bool tepan=true;
long long s[500010];
int u[500010],v[500010],w[500010],head[500010];
long long ans;
void fd(int x)
{
	s[x]=s[fa[x]];
	int now=0;
	for(int i=x;i;i=fa[i])
	{
		now+=w[i];
		if(now<0) break;
		if(now==0) ++s[x];
	}
	ans^=(x*s[x]);
	return;
}
void dfs(int x)
{
	for(int i=head[x];i;i=u[i])
	{
		fd(v[i]);
		dfs(v[i]);
	}
	return;
}
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
	{
		c=getchar();
		if(c==')') w[i]=1;
		else w[i]=-1;
	}
	for(int i=2;i<=n;++i)
	{
		fa[i]=read();
		u[i-1]=head[fa[i]];
		v[i-1]=i;
		head[fa[i]]=i-1;
		if(fa[i]!=(i-1)) tepan=false;
	}
	if(tepan==true)
	{
		for(int i=1;i<=n;++i)
		{
			int now=0;
			s[i]=s[i-1];
			for(int j=i;j>=1;--j)
			{
				now+=w[j];
				if(now<0) break;
				if(now==0) ++s[i];
			}
			ans^=(i*s[i]);
		}
		printf("%lld",ans);
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
