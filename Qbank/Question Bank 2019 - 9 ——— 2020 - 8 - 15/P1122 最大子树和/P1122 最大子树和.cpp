# include <cstdio>
# include <algorithm>
# define REG register
# define N 500000
using namespace std;

typedef long long LL;

template <typename T>
inline void in(T& x)
{
	x = 0;char c = getchar();int f = 1;
	
	while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	x *= f;
	
	return ;
} 

//template <typename T>
inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	return x;
}

struct edge
{
	int from,to;
} e[(N << 1) + 42];

int head[N + 42],cnt_e;

//bool ins[N + 42];

void add(int u,int v)
{
	e[++cnt_e].from = head[v];
	
	e[cnt_e].to = u;
	
	head[v] = cnt_e;
	
	e[++cnt_e].from = head[u];
	
	e[cnt_e].to = v;
	
	head[u] = cnt_e;
	
}

int n;

int dp[N + 42],ans;

void dfs(int u,int father)
{
	
	for(REG int i = head[u]; i ; i = e[i].from)
		if(e[i].to != father){
			dfs(e[i].to,u);
			dp[u] += dp[e[i].to] > 0 ? dp[e[i].to] : 0;
		}
	if(ans < dp[u]) ans = dp[u];
}

int main()
{
	in(n);
	
	for(REG int i = 1; i <= n; ++i) in(dp[i]);
	
	for(REG int i = 1; i < n; ++i)add(Read(),Read());
	
	dfs(1,-1);
	
	printf("%d",ans);
	
	return 0;
}
