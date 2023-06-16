#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define N 2500

using namespace std;
typedef long long ll;

int read()
{
	int ans=0;
	char k;
	k=getchar();
	while(k<'0' || k>'9') k=getchar();
	while(k<='9' && k>='0') {ans*=10;ans+=(k-'0');k=getchar();}
	return ans;
}

int n;
int du[N];
struct edge
{
	int u;
	int v;
	int nxt;
} e[N*2];
int head[N],tot=1;

void add(int u,int v)
{e[++tot]=(edge){u,v,head[u]};head[u]=tot;}

int w[N];
int f[N];
bool book[N*2];

bool dfs3(int u,int k,int fa);

void dfs1(int u,int fa)
{
	int i;
	f[u]=fa;
	for(i=head[u];i;i=e[i].nxt)
	 	if(e[i].v!=fa) dfs1(e[i].v,u); 
}

int dfs2(int u,int fa)
{
	printf("*%d %d\n",fa,u);
	int i;
	int min_num=0;
	w[0]=99999999;
	for(i=head[u];i;i=e[i].nxt)
	{
		if(book[i]) continue;
		int v=e[i].v;
		if(v==f[u]) continue; 
		int tm=dfs2(v,fa);
		if(w[tm]<w[min_num]) min_num=tm;
	}
	if(u==fa) dfs3(u,min_num,u);
	if(w[min_num]>w[u]) return u;
	else return min_num;
}

bool dfs3(int u,int k,int fa)
{
	int i;
	if(u==k) {swap(w[u],w[f[u]]);return true;}
	for(i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(book[i]) continue;
		if(v==f[u]) continue;
		if(dfs3(v,k,fa) && u!=fa) {swap(w[u],w[f[u]]);book[i]=book[i^1]=1;return true;}
	}
	return false;
}

void solve1()
{
	int i,j;
	dfs1(1,0);
	w[0]=99999999;
	dfs1(1,0);
	//for(i=1;i<=n;i++) printf("%d ",f[i]); 
	for(i=1;i<=n;i++) dfs2(i,i);
	//printf("1 ");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++) if(i==w[j]) printf("%d ",j);
	printf("\n");
}

int ans[N];
int tans[N];

void dfs(int x)
{
	int i,j;
	if(x==n)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++) 
				if(w[j]==i) tans[i]=j;
		for(i=1;i<=n;i++)
		{
			if(tans[i]<ans[i]) {for(i=1;i<=n;i++) ans[i]=tans[i];return;}
			else if(tans[i]>ans[i]) return;
		}
	}
	for(i=2;i<=tot;i+=2)
	{
		if(book[i]) continue;
		swap(w[e[i].u],w[e[i].v]);book[i]=1;
		dfs(x+1);
		swap(w[e[i].u],w[e[i].v]);book[i]=0;
	}
	return;
}

void solve3()
{
	memset(ans,127,sizeof(ans));
	dfs(1);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return;
}

void solve2()
{
	int i,j;
	for(i=2;i<=tot;i++)
		swap(w[e[i].u],w[e[i].v]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(w[j]==i) {printf("%d ",j);break;}
	printf("\n");
	return;
}


void solve()
{
	memset(book,0,sizeof(book));
	memset(e,0,sizeof(e));
	memset(head,0,sizeof(head));
	memset(du,0,sizeof(du));
	int i,j;
	bool flag1=1;
	int max_du=-1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		w[t]=i;
	}
	for(i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(u!=v-1 && v!=u-1) flag1=0;
		du[u]++;du[v]++;
		max_du=max(max_du,du[u]);
		max_du=max(max_du,du[v]);
		add(u,v);add(v,u);
	}
	if(flag1) solve1();
	if(max_du==n-1) solve2();
	else solve3();
	return;
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	T=read();
	while(T--) solve();
	return 0;
}
