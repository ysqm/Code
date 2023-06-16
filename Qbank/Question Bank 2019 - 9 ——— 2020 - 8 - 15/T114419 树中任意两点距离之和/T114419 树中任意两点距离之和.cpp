# include <cstdio>
# include <algorithm>
# include <cmath>
# define N 200000
# define M 200000
# define R register
using namespace std;
int r()
{
	int f = 1,x = 0;;
	
	char c = getchar();
	
	while(c > '9' || c < '0'){
		c = getchar();
	}
	
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		
		c = getchar();
	}
	
	return x * f;
}

struct edge
{
	int to,from,wi;
} e[M * 2 + 42];

int head[N + 42],n,cnt,size[N + 42];

long long ans,dp[N + 42];

inline void add(const int wi,const int u,const int v){e[++cnt].from = head[u];e[cnt].to = v;head[u] = cnt;e[cnt].wi = wi;e[++cnt].from = head[v];e[cnt].wi = wi;e[cnt].to = u;head[v] = cnt;}

void dfs(int u,int father)
{
	size[u] = 1;
	
	for(R int i = head[u]; i ; i = e[i].from)
		if(e[i].to != father){
			
			dfs(e[i].to,u);
			
			size[u] += size[e[i].to];
			
			dp[u] += size[e[i].to] * e[i].wi + dp[e[i].to];
			
		}
}

void dfs2(int u,int father,int wi)
{
	if(father) dp[u] = dp[father] + (size[1] - 2 * size[u]) * wi;
			
	ans += dp[u];
	
	for(R int i = head[u]; i ; i = e[i].from)
		if(e[i].to != father)
			dfs2(e[i].to,u,e[i].wi);
}

int main()
{
	n = r();
	
	for(R int i = 1; i < n; i ++) add(r(),r(),r());
	
	dfs(1,0);
	
	dfs2(1,0,0);
	
	
	
	printf("%lld\n",ans / 2);
	
	return 0;
}
