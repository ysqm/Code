# include <cstdio>
# include <algorithm>
# include <cstring>
# define M 1000000
# define N 200000
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
int rt,dis[N + 42],path[N + 42],ans,b[M + 42];
int tot,n,m;

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

void Get_dis(const int u ,const int fa,const int diss,const int paths)
{
	if(diss > m) return;
	
	dis[++tot] = diss;path[tot] = paths;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != fa && !vis[e[i].to]) 
			Get_dis(e[i].to,u,diss+e[i].wi,paths+1);
}

void Check_ans(const int u)
{
	b[tot = 0] = 0;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(!vis[e[i].to] && e[i].wi <= m)
		{
			int Last = tot+1;
			
			Get_dis(e[i].to,u,e[i].wi,1);
			
			for(reg int j = Last; j <= tot ; ++j) ans = Min(ans,b[m - dis[j]] + path[j]);
			
			for(reg int j = Last; j <= tot ; ++j) b[dis[j]] = Min(b[dis[j]],path[j]);
		}
	
	for(reg int i = 1; i <= tot ; ++i) b[dis[i]] = 0x3f3f3f3f;
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
	//freopen("P4149_7.in","r",stdin);
	
	n = Read();m = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read()+1,Read()+1); 
	
	U = g[0] = n+1;rt = 0;ans = 0x3f3f3f3f;
	
	Get_gc(1,0);
	
	memset(b,0x3f,sizeof(b));
	
	Starch_Qualityr(rt);
	
	if(ans < 0x3f3f3f3f) printf("%d\n",ans);
	else puts("-1"); 
			
	return 0;
} 
