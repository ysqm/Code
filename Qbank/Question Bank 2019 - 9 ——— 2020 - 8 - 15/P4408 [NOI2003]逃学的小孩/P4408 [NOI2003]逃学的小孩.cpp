# include <cstdio>
# include <cstring>
# define reg register
# define N 300000
# define LL long long

inline LL ReadL()
{
	 LL x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

inline int Read()
{
	 int x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

template <class T> inline T Min(const T a,const T b){return a < b ? a : b;}
template <class T> inline T Max(const T a,const T b){return a > b ? a : b;}

struct edge
{
	int next,to;
	LL wi;
	
	edge(const int next_=0,const int to_=0,const LL wi_=0):next(next_),to(to_),wi(wi_){}
} e[(N << 1) + 42];

int head[N + 42],tot_edge,S=1,n,m;

inline void add_edge(const LL wi,const int u,const int v)
{
	e[++tot_edge] = edge(head[u],v,wi);
	
	head[u] = tot_edge;
	
	e[++tot_edge] = edge(head[v],u,wi);
	
	head[v] = tot_edge;
}

int len,mv[N + 42];
LL dp[N + 42][2],dis[N + 42],ans,minnum;

void DFS(const int& u,const int& fa)
{
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa)
		{
			dis[e[i].to] = dis[u] + e[i].wi;
			
			DFS(e[i].to,u);
		}
}

void dfs(const int& u,const int& fa)
{
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa)
		{
			dfs(e[i].to,u);
			
			reg LL v = dp[e[i].to][0] + e[i].wi;
			
			if(v > dp[u][0]){dp[u][1] = dp[u][0];dp[u][0] = v;mv[u] = e[i].to;}
			else if(v > dp[u][1])dp[u][1] = v;
		}
}

int Backtracking(const int& u,const int& fa)
{
	reg LL tmp = 0;
	reg int cur = mv[u];
	
	while(cur)
	{
		if(dp[cur][1] + Min(ans-dp[cur][0],dp[cur][0]) > tmp + minnum)
		{
			tmp = dp[cur][1];
			minnum = Min(ans-dp[cur][0],dp[cur][0]);//第二短的路走两遍 
		}
		if(dp[cur][1] == tmp) minnum = Max(minnum,Min(ans-dp[cur][0],dp[cur][0]));
		
		cur = mv[cur];
	}
		
	return tmp;
} 

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= m ; ++i) add_edge(ReadL(),Read(),Read());
	
	DFS(S,S);
	
	for(reg int i = 1; i <= n ; dis[S] < dis[i] ? S = i++ : ++i) ;
	
	dfs(S,S);
	
	ans += dp[S][0];

	ans += Backtracking(S,S);
	
	printf("%lld",ans + minnum);
	
	return 0;
}
