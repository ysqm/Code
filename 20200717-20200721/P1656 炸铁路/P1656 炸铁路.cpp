# include <algorithm>
# include <cstring>
# include <cstdio>
# include <queue>
# define LL long long
# define reg register
# define N 10000
# define M 50000

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = x*10 + (ch^48);ch = getchar();}
	
	return x;
} 

inline int Min(const int a,const int b){return a < b ? a : b;}
inline int Max(const int a,const int b){return a > b ? a : b;}

struct edge
{
	int Next,to;
	
	edge(const int Next_=0,const int To_=0):Next(Next_),to(To_){}
	
} e[(M<<1) + 42];

int head[N + 42],edge_tot;

inline void add_edge(const int v,const int u)
{
	e[++edge_tot] = edge(head[u],v);
	
	head[u] = edge_tot;
	
	e[++edge_tot] = edge(head[v],u);
	
	head[v] = edge_tot;
}

struct Edge
{
	int u,v;
	
	Edge(const int Next_=0,const int To_=0):u(Next_),v(To_){}
	
	friend bool operator < (const Edge& a,const Edge& b)
	{
		if(a.u != b.u) return a.u < b.u;
		return a.v < b.v;
	}
	
} E[N + 42];

int ans;

int dfn[N + 42],t,low[N + 42],n,m;

void Tarjan(const int u,const int fa)
{
	low[u] = dfn[u] = ++t;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
	{
		if(e[i].to != fa && dfn[e[i].to]) low[u] = Min(dfn[e[i].to],low[u]);
		if(dfn[e[i].to] == 0)
		{
			Tarjan(e[i].to,u);
			
			if(dfn[u] < low[e[i].to]) E[++ans] = Edge(Min(u,e[i].to),Max(e[i].to,u));
			
			low[u] = Min(low[u],low[e[i].to]);
		}	
	}	
} 


int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read());
	
	Tarjan(1,1);
	
	std::sort(E + 1,E + ans + 1);
	
	for(reg int i = 1; i <= ans ; ++i) printf("%d %d\n",E[i].u,E[i].v);
	
	return 0;
}


