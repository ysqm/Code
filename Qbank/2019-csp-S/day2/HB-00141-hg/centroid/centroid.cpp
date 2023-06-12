#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#define N 50500

using namespace std;
typedef long long ll;

int n;
ll ans;
ll ans1,ans2;

struct edge
{
	int u;
	int v;
	int nxt;
} e[N];
int head[N],tot=1;
int size[N],f[N],du[N],a[N];

void add(int u,int v)
{e[++tot]=(edge){u,v,head[u]};head[u]=tot;}

void dfs(int u,int fa)
{
	size[u]=1;
	int i;
	for(i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa || v==-1) continue;
		dfs(v,u);
		size[u]+=size[v];
	}
}

void Tarjan(int u,int fa,int faa)
{
	bool flag=1;
	int i;
	if(size[faa]-size[u]>(size[faa]/2)) flag=0;
	for(i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa || v==-1) continue;
		Tarjan(v,u,faa);
		if(size[v]>(size[faa]/2)) flag=0;
	}
	if(flag)
	{
		if(ans1) ans2=u;
		else ans1=u;
	}
} 

int top=0;

void dfs2(int u,int fa)
{
	int i;
	a[++top]=u;
	for(i=head[u];i;i=e[i].nxt)
		if(e[i].v!=fa) dfs2(e[i].v,u);
}

void solve2()
{
	int i;
	int l,r;
	top=0;memset(a,0,sizeof(a));
	for(i=1;i<=n;i++) 
		if(du[i]==1)
		{dfs2(i,i);break;}
	for(l=1;l<n;l++) 
	{
		r=l+1;
		ans+=a[(l+1)/2];
		if(l%2==0) ans+=a[l/2+1];
		ans+=a[(r+n)/2];
		if((n-r+1)%2==0) ans+=a[(r+n)/2+1];
	}
	printf("%lld\n",ans);
	return;
}

void solve()
{
	int i;
	bool flag=1;
	ans=0;
	memset(e,0,sizeof(e));
	memset(head,0,sizeof(head));
	memset(du,0,sizeof(du));
	tot=1;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
		du[u]++;du[v]++;
		if(u!=v-1 && v!=u-1) flag=0;
		//printf("%d %d\n",u,v);
	}
	
	if(flag) {solve2();return;}
	
	/*printf("%d %d\n",e[2].v,e[3].v);
	return;*/
	for(i=2;i<=tot;i+=2)
	{
		int last1=e[i].v,last2=e[i^1].v;
		//printf("%d %d\n",last1,last2);
		e[i].v=e[i^1].v=-1;
		ans1=ans2=0;
		dfs(last1,0);Tarjan(last1,last1,last1);
		//printf("%d %d\n",ans1,ans2);
		ans+=ans1,ans+=ans2;
		ans1=ans2=0;
		dfs(last2,0);Tarjan(last2,last2,last2);
		//printf("%d %d\n",ans1,ans2);
		ans+=ans1,ans+=ans2;
		e[i].v=last1;e[i^1].v=last2;
	}
	printf("%lld\n",ans);
	return;
}

int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int i,j;
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
