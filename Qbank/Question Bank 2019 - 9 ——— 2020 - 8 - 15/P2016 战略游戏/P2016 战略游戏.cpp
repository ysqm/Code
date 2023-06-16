# include <cstdio>
# include <algorithm>
# define REG register
# define N 500000
using namespace std;

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

int n,dp[N + 42][2];

void dfs(int u,int father)
{
	dp[u][0] = 0;
	dp[u][1] = 1;
	
	for(REG int i = head[u]; i ; i = e[i].from)
		if(e[i].to != father){
			dfs(e[i].to,u);
			dp[u][1] += min(dp[e[i].to][0],dp[e[i].to][1]);
			dp[u][0] += dp[e[i].to][1];
		}
}

int main()
{
	in(n);
	
	for(REG int i = 1; i <= n; ++i){
		int u = Read() + 1,num;in(num);
		while(num--) add(u,Read() + 1);
	}
	
	dfs(1,0);
	
	printf("%d",min(dp[1][0],dp[1][1]));
	
	return 0;
}
