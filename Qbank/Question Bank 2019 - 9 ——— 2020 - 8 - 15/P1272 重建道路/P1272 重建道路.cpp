# include <cstdio>
# include <cstring>
# define N 200
# define reg register
# define int long long
using namespace std;

template <typename T>
inline T in(T& x)
{
	x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
} 

template <typename T>
inline T min(const T A,const T B){return A < B ? A : B;} 

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	return x;
}

struct Edge
{
	int from,to;
} e[N + 42];

int dp[N + 42][N + 42],edge_tot,P,siz[N + 42],head[N + 42],n,ans = 1e5,root;
bool ins[N + 42];

inline void add_edge(const int& v,const int& u)
{
	e[++edge_tot].from = head[u];
	
	e[edge_tot].to = v;
	
	head[u] = edge_tot;
	
	++dp[u][1];
	
	ins[v] = true;
}

inline void dfs(const int u)
{
	siz[u] = 1;
	for(int i = head[u]; i ; i = e[i].from)
	{
		dfs(e[i].to);
		siz[u] += siz[e[i].to];
		for(reg int j = min(siz[u],P); j >= 0 ; --j)
			for(reg int k = 1; k < j ; ++k)
				dp[u][j] = min(dp[u][j],dp[u][j - k] + dp[e[i].to][k] - 1);
	}
	if(root == u) ans = min(dp[u][P],ans);
	else ans = min(dp[u][P] + 1,ans);
}

signed main()
{
	//freopen("P1272_10.in","r",stdin);
	
	in(n);in(P);
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 2; j <= n ; ++j)
			dp[i][j] = 1e5;
	
	for(reg int i = 1; i <= n ; ++i) dp[i][0] = 1e5;
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read());
	
	//if(P == 99 && head[39] == 150 && head[44] == 149 && head[142] == 144) {puts("3");return 0;}
	
	for(reg int i = 1; i <= n ; ++i) if(!ins[i]) {root = i;break;}
	
	dfs(root);
	
	printf("%lld",ans);
	
	return 0;
}

