# include <cstdio>
# include <algorithm>
# include <cstring>
# define M 20000
# define N 40000
# define lowbit(x) (x&(-x))
# define reg register
using namespace std;

inline int Max(const int a,const int b){return a > b ? a : b;}
inline int Min(const int a,const int b){return a < b ? a : b;}

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0'){x = x*10+(ch^48);ch = getchar();}
	
	return x; 
}

struct edge
{
	int Next,to,wi;
	
	edge(const int Next_=0,const int To_=0,const int wi_=0):Next(Next_),to(To_),wi(wi_){}
} e[(N<<1) + 42];

bool vis[N + 42],flag;
int head[N + 42],edge_tot,U;
int g[N + 42],Size[N + 42];
int rt,dis[N + 42],path[N + 42],ans,tr[M + 42];
int tot,n,m;

inline void Insert(int x,const int Increment)
{
	while(x <= m)
	{
		tr[x] += Increment;
		x += lowbit(x);
	}
}

inline int Get_Sum(int x)
{
	int res = 0;
	
	while(x)
	{
		res += tr[x];
		x -= lowbit(x);
	}
	
	return res;
}

inline void add_edge(const int wi,const int v,const int u)
{
	e[++edge_tot] = edge(head[u],v,wi);
	
	head[u] = edge_tot;
	
	e[++edge_tot] = edge(head[v],u,wi);
	
	head[v] = edge_tot;
}

void Get_gc(const int u,const int fa)
{
	Size[u] = 1;g[u] = 0;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != fa && !vis[e[i].to])
		{
			Get_gc(e[i].to,u);
			
			Size[u] += Size[e[i].to];
			
			g[u] = Max(g[u],Size[e[i].to]);
		}
	
	g[u] = Max(g[u],U - Size[u]);
	
	if(g[u] < g[rt] || rt == 0) rt = u;
}

void Get_dis(const int u ,const int fa,const int diss)
{
	if(diss > m) return;
	
	dis[++tot] = diss;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != fa && !vis[e[i].to]) 
			Get_dis(e[i].to,u,diss+e[i].wi);
}

void Check_ans(const int u)
{
	tot = 0;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(!vis[e[i].to] && e[i].wi <= m)
		{
			int Last = tot+1;
			
			Get_dis(e[i].to,u,e[i].wi);
			
			for(reg int j = Last; j <= tot ; ++j) ans += Get_Sum(m-dis[j]);
			
			for(reg int j = Last; j <= tot ; ++j) {Insert(dis[j],1);++ans;}
		}
	
	for(reg int i = 1; i <= tot ; ++i) Insert(dis[i],-1);
}

void Starch_Qualityr(const int u)
{
	vis[u] = 1;
	Check_ans(u);
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(!vis[e[i].to] && ans != 1)
		{
			rt = 0;
			
			U = Size[e[i].to];
			
			Get_gc(e[i].to,0);
			
			Starch_Qualityr(rt);
		}
}

signed main()
{
	n = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read(),Read()); 
	
	m = Read();
	
	U = g[0] = n+1;rt = 0;
	
	Get_gc(1,0);
	
	Starch_Qualityr(rt);
	
	printf("%d\n",ans);
			
	return 0;
} 
