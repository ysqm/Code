# include <cstdio>
# include <cstring>
# include <iostream>
using namespace std;
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
int t;
int n;
int tepan;
int s[2010],_s[2010];
struct tree
{
	int u,v;
}e[2010];
int ans[2010];
int pan[2010];
void dfs(int now)
{
	if(tepan>=50) return;
	if(now==n)
	{
		tepan++;
		for(int i=1;i<=n;++i) _s[s[i]]=i;
		for(int i=1;i<=n;++i)
		{
			if(ans[i]<_s[i]) return;
			if(ans[i]>_s[i]) break;
		}
		tepan=0;
		for(int i=1;i<=n;++i) ans[i]=_s[i];
		return;
	}
	for(int i=1;i<n;++i)
	{
		if(tepan>=50) return;
		if(!pan[i])
		{
			pan[i]=true;
			swap(s[e[i].u],s[e[i].v]);
			dfs(now+1);
			swap(s[e[i].u],s[e[i].v]);
			pan[i]=false;
		}
	}
	return;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	t=read();
	while(t--)
	{
		tepan=0;
		n=read();
		memset(ans,0x7f,sizeof(ans));
		for(int i=1;i<=n;++i) {int a=read();s[a]=i;}
		for(int i=1;i<n;++i) {e[i].u=read();e[i].v=read();}
		dfs(1);
		for(int i=1;i<=n;++i) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
