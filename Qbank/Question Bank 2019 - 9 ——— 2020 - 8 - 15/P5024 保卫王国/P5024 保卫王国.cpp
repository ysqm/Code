# include <cstdio>
# include <cmath>
# define N 100000
# define NN 18
# define LL long long
# define INF 0x7f7f7f7f7f
# define reg register

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

template<class T>
inline T Min(const T a,const T b){return a > b ? b : a;}

int head[N + 42],edge_tot;

struct edge
{
	int next,u,v;
} e[(N << 1) + 42];

void add_edge(const int u,const int v)
{
	e[++edge_tot] = (edge){head[u],u,v};
	
	head[u] = edge_tot;
	
	e[++edge_tot] = (edge){head[v],v,u};
	
	head[v] = edge_tot;
}

LL f[N + 42][NN][2][2],dp[N][2],cost[N + 42];
int father[N + 42][NN],depth[N + 42],n,m;

void Father_INIT(const int& u)
{
	for(reg int i = 1; i <= NN ; ++i) father[u][i] = father[father[u][i-1]][i-1];
}

void DFS(const int& u)
{
	dp[u][1] = cost[u];
	
	Father_INIT(u);
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].v != father[u][0])
		{
			father[e[i].v][0] = u;
			
			depth[e[i].v] = depth[u] + 1;
			
			DFS(e[i].v);
			
			dp[u][0] += dp[e[i].v][1];
			
			dp[u][1] += Min(dp[e[i].v][1],dp[e[i].v][0]);
		}
}

inline void INIT()
{
	char s[5];
	
	scanf("%d%d%s",&n,&m,s);
	
	for(reg int i = 1; i <= n ; ++i) cost[i] = Read();
	
	for(reg int i = 1; i <  n ; ++i) add_edge(Read(),Read());
	
	int root = 1;
	
	depth[root] = 1;
	
	DFS(root);
}

inline void Initialization()
{
	for(reg int u = 1; u <= n; ++u)
	{
		f[u][0][0][0] = INF;
		f[u][0][1][0] = dp[father[u][0]][0] - dp[u][1];
		f[u][0][0][1] = f[u][0][1][1] = dp[father[u][0]][1] - Min(dp[u][1],dp[u][0]);
	}
	
	for(reg int u = 1; u <= n ; ++u)
		for(reg int i = 1; i <= NN; ++i)
		{
			f[u][i][0][0] = Min(f[u][i-1][0][0]+f[father[u][i-1]][i-1][0][0],f[u][i-1][0][1]+f[father[u][i-1]][i-1][1][0]);
			f[u][i][1][0] = Min(f[u][i-1][1][0]+f[father[u][i-1]][i-1][0][0],f[u][i-1][1][1]+f[father[u][i-1]][i-1][1][0]);
			f[u][i][0][1] = Min(f[u][i-1][0][0]+f[father[u][i-1]][i-1][0][1],f[u][i-1][0][1]+f[father[u][i-1]][i-1][1][1]);
			f[u][i][1][1] = Min(f[u][i-1][1][0]+f[father[u][i-1]][i-1][0][1],f[u][i-1][1][1]+f[father[u][i-1]][i-1][1][1]);
		}
}

inline LL Ans()
{
	for(reg int i = 1; i <= m ; ++i)
	{
		reg int a,x,b,y;
		
		a = Read();x =  Read();b = Read();y = Read();
		
		LL a0,a1,b0,b1,l0,l1,t0,t1,l;
		
		if(depth[a] < depth[b]) a ^= b ^= a ^= b,x ^= y ^= x ^= y;
	
		if(x) {a0 = INF;a1 = dp[a][1];}
		else {a1 = INF;a0 = dp[a][0];}
		
		if(y) {b0 = INF;b1 = dp[b][1];}
		else {b1 = INF;b0 = dp[b][0];}
	
		for(reg int i = NN ; i ; --i)
			if(depth[father[a][i]] >= depth[b])
			{
				t0 = a0;t1 = a1;
				
				a0 = Min(t0+f[a][i][0][0],t1+f[a][i][1][0]);
				a1 = Min(t0+f[a][i][0][1],t1+f[a][i][1][1]);
				
				a = father[a][i];
			}
		if(a == b)
		{
			l = b;
			if(y) {l0 = INF;l1 = a1;}
			else {l1 = INF;l0 = a0;}
		}
		else
		{
			for(reg int i = NN ; i ; --i)
				if(father[a][i] != father[b][i])
				{
					t0 = a0;t1 = a1;
					
					a0 = Min(t0+f[a][i][0][0],t1+f[a][i][1][0]);
					a1 = Min(t0+f[a][i][0][1],t1+f[a][i][1][1]);
					
					a = father[a][i];
				
					t0 = b0;t1 = b1;
					
					b0 = Min(t0+f[b][i][0][0],t1+f[b][i][1][0]);
					b1 = Min(t0+f[b][i][0][1],t1+f[b][i][1][1]);
					
					b = father[b][i];
				}	
				
			l = father[a][0];
			
			l1 = dp[l][1] - Min(dp[a][0],dp[a][1]) - Min(dp[b][0],dp[b][1]) + Min(a1,a0) + Min(b1,b0);
			
			l0 = dp[l][0] - dp[a][1] - dp[b][1] + a1 + b1;
		}
			
		for(reg int i = NN ; i ; --i)
			if(depth[father[l][i]])
			{
				t0 = l0;t1 = l1;
				
				l0 = Min(t0+f[l][i][0][0],t1+f[l][i][1][0]);
				l1 = Min(t0+f[l][i][0][1],t1+f[l][i][1][1]);
				
				l = father[l][i];
			}
	
		LL ans = Min(l1,l0);
	
		if(ans < INF) printf("%lld\n",ans);
		else puts("-1");
	}
}

int main()
{	
	INIT();
	
	Initialization();
	
	Ans();
	
	return 0;
}

