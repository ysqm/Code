/*
	血一样的教训
	coby以前的code
	结果改了2 hours 
*/
# include <cstdio>
# include <algorithm>
# include <cmath>
# define N 100
# define M 500000
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
	int to,from;
} e[M * 2 + 42];

int head[N + 42],n,cnt,size[N + 42],ans,son[N + 42],dp[N + 42],p[N + 42],su1;

inline void add(const int u,const int v){e[++cnt].from = head[u];e[cnt].to = v;head[u] = cnt;e[++cnt].from = head[v];e[cnt].to = u;head[v] = cnt;}

void dfs(const int u,const int father)
{
	size[u] = p[u];
	
	for(R int i = head[u]; i ; i = e[i].from)
		if(e[i].to != father && e[i].to){
			
			dfs(e[i].to,u);
			
			size[u] += size[e[i].to];
			
			son[u] = max(size[e[i].to],son[u]);
			
		}
		
	son[u] = max(son[u],su1 - size[u]);
	
	if(son[u] < son[ans]) ans = u;
	
	
}

void sum_dfs(const int u,const int father)
{
	dp[u] = 0;
	
	for(R int i = head[u]; i ; i = e[i].from)
		if(e[i].to != father && e[i].to){
			
			sum_dfs(e[i].to,u);
			
			dp[u] += dp[e[i].to] + p[e[i].to];
			
			p[u] += p[e[i].to];
		}

}

int main()
{
	n = r();
	
	for(R int i = 1; i <= n; i ++){
		p[i] = r();
		su1 += p[i];
		add(i,r());
		add(i,r());
	}
	
	ans = n + 1;son[ans] = su1;
	
	dfs(1,0);
	
	sum_dfs(ans,0);
	
	printf("%d",dp[ans]);
	
	return 0;
}
