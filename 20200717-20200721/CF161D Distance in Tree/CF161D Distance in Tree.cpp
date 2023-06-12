# include <cstdio>
# include <algorithm>
# define N 50000
# define reg register
using namespace std;

typedef long long LL;

inline int Max(const int a,const int b){return a > b ? a : b;}

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0'){x = x*10+(ch^48);ch = getchar();}
	
	return x; 
}

struct edge
{
	int Next,to;
	
	edge(const int Next_=0,const int To_=0):Next(Next_),to(To_){}
} e[(N<<1) + 42];

bool vis[N + 42];
int head[N + 42],edge_tot;
int rt,g[N + 42],Size[N + 42],dis[N + 42];
LL ans,b[542];
int tot,n,m;

inline void add_edge(const int v,const int u)
{
	e[++edge_tot] = edge(head[u],v);
	
	head[u] = edge_tot;
	
	e[++edge_tot] = edge(head[v],u);
	
	head[v] = edge_tot;
}

void Get_gc(const int u,const int fa,const int Size_root)
{
	Size[u] = 1;g[u] = 0;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != fa && !vis[e[i].to])
		{
			Get_gc(e[i].to,u,Size_root);
			
			Size[u] += Size[e[i].to];
			
			g[u] = Max(g[u],Size[e[i].to]);
		}
	
	g[u] = Max(g[u],Size_root - Size[u]);
	
	if(g[u] < g[rt] || rt == 0) rt = u;
}

void Get_dis(const int u ,const int fa,const int diss)
{
	if(diss > m) return ;
	
	dis[++tot] = diss;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != fa && !vis[e[i].to])
			Get_dis(e[i].to,u,diss+1);
}


void Check_ans(const int u)
{
	b[tot = 0] = 1;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(!vis[e[i].to])
		{
			int Last = tot+1;
			
			Get_dis(e[i].to,u,1);
			
			for(reg int j = Last; j <= tot ; ++j) ans += b[m - dis[j]];
			
			for(reg int j = Last; j <= tot ; ++j) ++b[dis[j]];
		} 
		
	for(reg int i = 1; i <= tot ; ++i) --b[dis[i]];
}

void Starch_Qualityr(const int u)
{
	vis[u] = 1;
	Check_ans(u);
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(!vis[e[i].to])
		{
			rt = 0;
			
			Get_gc(e[i].to,0,Size[e[i].to]);
			
			Starch_Qualityr(rt);
		}
}

int main()
{	
	n = Read();m = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read());
	
	g[0] = n;rt = 0;
	
	Get_gc(1,0,n);
	
	Starch_Qualityr(rt);
	
	printf("%lld\n",ans);
			
	return 0;
} 
