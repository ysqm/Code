# include <cstdio>
# define reg register
# define N 300000
# define INF 0x7f7f7f7f

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9') {x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

struct edge
{
	int next,to,wi;
} e[(N << 1) + 42];

int T,n,head[N + 42],Size[N + 42],edge_tot = 1;
long long ans = INF,dp[N + 42],L,R;

inline void Max(const long long b){ans = ans > b ? ans : b;}

inline void Min(long long& a,const long long b){a = a < b ? a : b;}

inline void add_edge(const int wi,const int u,const int v)
{
	e[++edge_tot] = (edge){head[u],v,wi};
	
	head[u] = edge_tot;
	
	e[++edge_tot] = (edge){head[v],u,wi};
	
	head[v] = edge_tot;
}

inline void dfs1(const int u,const int father)
{
	Size[u] = 1;
	
	dp[u] = 0;
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father && e[i].to)
		{
			dfs1(e[i].to,u);
			
			Size[u] += Size[e[i].to];
			
			dp[u] += dp[e[i].to] + Size[e[i].to] * e[i].wi;
		}
}

inline long long dfs2(const int u,const int father,const int& root)
{
	long long ans1 = dp[root];
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father && e[i].to)
		{
			Min(ans1,dp[u] + (Size[root] - 2 * Size[e[i].to]) * e[i].wi);
			
			Min(ans1,dfs2(e[i].to,u,root));
		}
		
	return ans1;
}

inline void dfs(const int u,const int father)
{
	int u1,v1;
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father)
		{
			u1 = e[i].to;v1 = e[i^1].to;
			
			e[i].to = e[i^1].to = 0;
			
			dfs1(u,0);
			
			dfs1(e[i].to,0);
			
			L = dfs2(u,0,u);
			
			R = dfs2(u1,0,u1);
		
			Min(ans,Size[u] * Size[e[i].to] + L + R);
			
			e[i].to = u1;e[i^1].to = v1;
			
			dfs1(e[i].to,u);
		}
}

int main()
{
	n = Read();
		
	for(reg int i = 1; i < n ;++i) add_edge(Read(),Read(),Read());
		
	dfs(1,0);
		
	printf("%lld\n",ans);
	
	return 0;
}
