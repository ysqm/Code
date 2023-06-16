# include <cstdio>
# include <queue>
# define reg register
# define N 200000
# define mod 10007
# define wi(i) Point[e[i].to]

//template <class T>
inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9'){if(	ch == '-') f = -1;ch = getchar();}

	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x * f;
}

struct edge
{
	int next,to;
} e[(N << 1) + 42];

std::queue <int> q;
int head[N + 42],tot_edge,n,Point[N + 42],dp[N + 42],Max_W,ans;

inline void add_edge(const int v,const int u)
{
	e[++tot_edge] = (edge){head[u],v};
	
	head[u] = tot_edge;
	
	e[++tot_edge] = (edge){head[v],u};
	
	head[v] = tot_edge;
}

inline void INIT()
{
	n = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read());
	
	for(reg int i = 1; i <= n ; ++i) Point[i] = Read();
}

inline int Max(const int& a,const int b){return a > b ? a : b;}

inline void Solve(const int u,const int father,const int grandpa)
{
	int sum_gf = 0,sum = 0,max_first = 0,max_second = 0;
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father)
		{
			sum_gf = (sum_gf + wi(i)) % mod;
			
			sum = (sum + wi(i) * wi(i)) % mod;
			
			if(wi(i) > max_first)
			{	
				max_second = max_first;
				
				max_first = wi(i);
			}
			
			else if(wi(i) > max_second) max_second = wi(i);
			
			Solve(e[i].to,u,father);
		}
	
	Max_W = Max(Max_W,Max(Point[grandpa] * Point[u],max_second * max_first));
	
	ans = (ans + (sum_gf * sum_gf % mod - sum + mod) % mod + (Point[grandpa] * Point[u] << 1)) % mod;
}

int main()
{
	INIT();
	
	Solve(1,0,0);
	
	printf("%d %d",Max_W,ans);
	
	return 0;
}
