# include <cstdio>
# include <cstring>
# define N 300
# define reg register
using namespace std;

template <typename T>
inline T in(T& x)
{
	x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
} 

template <typename T>
inline T min(const T A,const T B){return A < B ? A : B;} 

template <typename T>
inline T max(const T A,const T B){return A > B ? A : B;}

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
	
	return x;
}

struct Edge
{
	int from,to,wi;
} e[N + 42];

int dp[N + 42][N + 42],edge_tot,m,Supper_Start_Point = 1,head[N + 42],n;

inline void add_edge(const int v,const int wi,const int u)
{
	e[++edge_tot].from = head[u];
	
	e[edge_tot].to = v;
	
	head[u] = edge_tot;
	
	dp[v][1] = wi;
}

inline void dfs(const int& u)
{
	for(reg int p = head[u]; p ; p = e[p].from){
		dfs(e[p].to);
		for(reg int i = m; i >= 0 ; --i)
			for(reg int j = 0; j < i; ++j)
				dp[u][i] = max(dp[u][i],dp[u][i - j] + dp[e[p].to][j]); 
	}
}

signed main()
{
	in(n);in(m);
	
	for(reg int i = 1; i <= n; ++i) add_edge(i + 1,Read(),Read() + 1);m++;
	
	dfs(Supper_Start_Point);
	
	printf("%d",dp[1][m]);
	
	return 0;
}
