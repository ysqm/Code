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
	int to,from,wi;
} e[M * 2 + 42];

int head[N + 42],n,cnt,size[N + 42],ans,son[N + 42],dp[N + 42];

inline void add(const int wi,const int u,const int v){e[++cnt].from = head[u];e[cnt].to = v;head[u] = cnt;e[cnt].wi = wi;e[++cnt].from = head[v];e[cnt].wi = wi;e[cnt].to = u;head[v] = cnt;}

void dfs(const int u,const int father)
{
	size[u] = 1;
	
	for(R int i = head[u]; i ; i = e[i].from)
		if(e[i].to != father){
			
			dfs(e[i].to,u);
			
			size[u] += size[e[i].to];
			
			dp[u] += size[e[i].to] * e[i].wi + dp[e[i].to];
			
			if(size[e[son[u]].to] < size[e[i].to]) son[u] = i;
			
		}

}

int main()
{
	n = r();
	
	for(R int i = 1; i < n; i ++) add(r(),r(),r());
	
	ans = n + 1;
	
	dfs(1,0);
	
	int i = son[1],fa = 1,ans2; ans = 100000000;
	
	do{
		dp[e[i].to] = dp[fa] + (size[1] - 2 * size[e[i].to]) * e[i].wi;
		
		if (ans > dp[e[i].to]){
			ans = dp[e[i].to];
			
			ans2 = e[i].to;
		}
		fa = e[i].to;
		
		i = son[i];
	}while(i);
	
	
	
	printf("%d %d",ans2,ans);
	
	return 0;
}
