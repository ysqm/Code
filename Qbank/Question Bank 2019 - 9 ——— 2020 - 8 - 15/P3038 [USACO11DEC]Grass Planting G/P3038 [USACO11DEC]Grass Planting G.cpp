# include <cstdio>
# include <cstring>
# define reg register
# define N 300000
# define LL long long
# define mod 998244353

inline int Read()
{
	 int x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

inline int Min(const int a,const int b){return a < b ? a : b;}
inline int Max(const int a,const int b){return a > b ? a : b;}

struct edge
{
	int next,to,wi;
	
	edge(const int next_=0,const int to_=0,const int wi_=0):next(next_),to(to_),wi(wi_){}
} e[(N << 1) + 42];

int head[N + 42],tot_edge=1,S=1,n,m;

inline void add_edge(const int u,const int v)
{
	e[++tot_edge] = edge(head[u],v);
	
	head[u] = tot_edge;
	
	e[++tot_edge] = edge(head[v],u);
	
	head[v] = tot_edge;
}


inline LL Pow(LL x,int p)
{
	LL res = 1;
	
	while(p)
	{
		if(p & 1) res = (res * x) % mod;
		p >>= 1;
		x = (x * x) % mod;
	}
	return res;
}

LL deep[N + 42],dp[N + 5][51];
int fa[N + 42][22];

void dfs_1(const int& u)
{
	for(reg int i = 0; (1 << i) <= deep[u] ; ++i) fa[u][i+1] = fa[fa[u][i]][i];
	
	for(reg int i = 1; i <= 50 ; ++i) dp[u][i] = (dp[fa[u][0]][i] + Pow(deep[u],i));
	
	++deep[u];
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa[u][0])
		{
			deep[e[i].to] = deep[u];
			
			fa[e[i].to][0] = u;
			
			dfs_1(e[i].to);
	 	}
	
	--deep[u];
}

inline int LCA(int x,int y)
{
	if(deep[x] < deep[y]) x ^= y ^= x ^= y;
	
	reg int d = deep[x] - deep[y];
	
	for(reg int i = 0; d ; ++i,d >>= 1)
		if(d & 1) x = fa[x][i];
	
	
	if(x == y) return x;
	
	for(reg int i = 20; ~i ; --i)
		if(fa[x][i] != fa[y][i])
		{
			x = fa[x][i];
			y = fa[y][i];
		}
	return fa[x][0];
}

int main()
{
	n = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read());
	
	dfs_1(S);
	
	int x,y,k,m = Read(),ans,lca;
	
	while(m--)
	{
		x = Read();y = Read();k = Read();
		
		lca = LCA(x,y);
		
		ans = dp[x][k] + dp[y][k] - (dp[lca][k] << 1) + Pow(deep[lca],k);
		
		ans = (ans + mod) % mod;
		
		printf("%d\n",ans);
	}
	 
}



