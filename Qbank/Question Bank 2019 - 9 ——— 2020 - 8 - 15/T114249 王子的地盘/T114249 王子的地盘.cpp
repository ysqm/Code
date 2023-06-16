# include <cstdio>
# include <algorithm>
# include <cmath>
# define N 10000
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

int head[N + 42],n,cnt,size[N + 42],ans;

inline void add(const int v,const int u){e[++cnt].from = head[u];e[cnt].to = v;head[u] = cnt;e[++cnt].from = head[v];e[cnt].to = u;head[v] = cnt;}

void dfs(int u,int father)
{
	size[u] = 1;
	
	int maxson = 0;
	
	for(R int i = head[u]; i ; i = e[i].from)
		if(e[i].to != father){
			
			dfs(e[i].to,u);
			
			size[u] += size[e[i].to];
			
			maxson = max(maxson,size[e[i].to]);
			
		}
		
	maxson = max(maxson,n - size[u]);
	
	ans = min(maxson,ans);
}

int main()
{
	n = r();
	
	for(R int i = 1; i < n; i ++) add(r(),r());
	
	ans = n + 1;
	
	dfs(1,0);
	
	printf("%d",n - ans);
	
	return 0;
}
