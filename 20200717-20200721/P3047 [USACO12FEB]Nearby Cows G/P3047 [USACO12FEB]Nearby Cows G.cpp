# include <cstdio>
# define reg register 
# define N 100000

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

inline void Write(int x)
{
	if(x >= 10) Write(x/10);
	putchar(x%10 + '0');
}

struct edge
{
	int Next,to;
	
	edge(const int Next_=0,const int To_=0):Next(Next_),to(To_){}
	
} e[(N << 1) + 42];

int head[N + 42],tot_edge,S = 1;

inline void add_edge(const int u,const int v)
{
	e[++tot_edge] = edge(head[u],v);
	
	head[u] = tot_edge;
	
	e[++tot_edge] = edge(head[v],u);
	
	head[v] = tot_edge;
}

int n,k,dp[N + 42][21],deep[N + 42];

void dfs_1(const int u)
{
	++deep[u];
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(deep[e[i].to] == 0)
		{
			deep[e[i].to] = deep[u];
			
			dfs_1(e[i].to);
			
			for(reg int j = 1; j <= k ; ++j)
				dp[u][j] += dp[e[i].to][j-1];
		}
	
	--deep[u];
}

void dfs_2(const int u)
{
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(deep[e[i].to] > deep[u])
		{
			for(reg int j = k; j >= 2 ; --j)
				dp[e[i].to][j] -= dp[e[i].to][j-2];
			
			for(reg int j = 1; j <= k ; ++j)
				dp[e[i].to][j] += dp[u][j-1];
				
			dfs_2(e[i].to);
		}
}

inline int Sum(int x)
{
	int res = 0;
	
	for(reg int i = 0 ; i <= k ; ++i) res += dp[x][i];
	
	return res;
}

int main()
{
	n = Read();k = Read();
	
	for(reg int i = 1; i <  n ; ++i) add_edge(Read(),Read());
	
	for(reg int i = 1; i <= n ; ++i) dp[i][0] = Read();
	
	deep[S] = 1;
	
	dfs_1(1);
	
	dfs_2(1);
	
	for(reg int i = 1; i <= n ; ++i) {Write(Sum(i));putchar(10);}
	
	return 0;
}
