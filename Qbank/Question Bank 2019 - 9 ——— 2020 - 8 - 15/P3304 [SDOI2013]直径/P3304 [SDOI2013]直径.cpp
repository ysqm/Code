# include <cstdio>
# include <cstring>
# define reg register
# define N 200000
# define LL long long

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

int head[N + 42],tot_edge=1,S=1;

inline void add_edge(const int wi,const int u,const int v)
{
	e[++tot_edge] = edge(head[u],v,wi);
	
	head[u] = tot_edge;
	
	e[++tot_edge] = edge(head[v],u,wi);
	
	head[v] = tot_edge;
}

LL dp[N + 42][2],dis[N + 42],n;
int mv[N + 42];

void dfs(const int& u,const int& fa)
{
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa)
		{
			dis[e[i].to] = dis[u] + e[i].wi;
			
			dfs(e[i].to,u);
		}
}

void Dp(const int& u,const int& fa)
{
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa)
		{
			Dp(e[i].to,u);
			
			LL v = dp[e[i].to][0] + e[i].wi;
			
			if(v > dp[u][0]){dp[u][1] = dp[u][0];dp[u][0] = v;mv[u] = e[i].to;}
   			
   			else if(v > dp[u][1]) dp[u][1] = v;
			
		}
}

int main()
{
	n = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read(),Read());
	
	dfs(S,S);
	
	for(reg int i = 1; i <= n ; ++i) dis[S] < dis[i] ? S = i : S;
	
	Dp(S,S);
	
	int cur = mv[S],sum = 0;
	
	while(cur)
	{
		++sum;
		if(dp[cur][0] == dp[cur][1]) break;
		
		if(dp[S][0] == dp[cur][1] + dp[cur][0]) sum = 0;
		
		cur = mv[cur];
	}
	
	printf("%lld\n%d",dp[S][0],sum);
	
	return 0;
}
