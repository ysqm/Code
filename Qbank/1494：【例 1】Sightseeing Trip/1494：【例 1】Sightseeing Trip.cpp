# include <cstdio>
# include <algorithm>
# include <vector>
# define inf 0x7f7f7f7f
# define N 100
# define R register
# define I inline
# define _ dis[i][j]+g[j][k]+g[k][i]

I void r(int &x)
{
	x = 0;int f = 1;
	char c = getchar();
	
	while(c >'9' || c < '0'){
		if(c == '-') f = -f;
		c = getchar();
	}
	
	while(c <= '9' && c >= '0'){
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	
	x *= f;
}

int n,m;
int pre[N + 42][N + 42],g[N + 42][N + 42],dis[N + 42][N + 42];
int path[N + 42],cnt;

void INIT()
{
	r(n);r(m);
	
	for(R int i = 1; i <= n ; i++)
		for(R int j = 1;j <= n; j++)
			g[i][j] = dis[i][j] = inf;
	
	for(R int i = 1; i <= n ; i++)
		g[i][i] = dis[i][i] = 0;
	
	int u,v,w;
	
	for(R int i = 1; i <= m ; i++)
	{
		r(u);r(v);r(w);
		g[u][v] = dis[u][v] = g[v][u] =dis[v][u] = w;
		pre[u][v] = u;
		pre[v][u] = v;
	}
}

void WORK()
{
	int mincircle = inf;
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= k-1; i++)
			for(int j = i + 1; j <= k-1; j++)
				if(dis[i][j] < inf && g[j][k] < inf && g[k][i] < inf && _< mincircle){
					mincircle = _;
					int p = j;
					cnt = 0;
					
					while(p != i){
						path[++cnt] = p;
						p = pre[i][p];
					}
					
					path[++cnt] = i;
					path[++cnt] = k;
				}
	
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(dis[i][k] < inf && dis[k][j] < inf && dis[i][j] > dis[i][k] + dis[k][j]){ 
					dis[i][j] = dis[i][k] + dis[k][j];
					pre[i][j] = pre[k][j];
				}	
	}
	
	int minto = inf,p;
	
	if(mincircle == inf){
		printf("No solution.");
		return;
	}
	
	for(int i = 1;i <= cnt; i++)
		if(minto > path[i]){
			minto = path[i];
			p = i;
		}
	
	for(int i = p; i ; i--)
		printf("%d ",path[i]);
	for(int i = cnt; i > p ; i--)
		printf("%d ",path[i]);
	
	return;
}

int main()
{
	INIT();
	WORK();
	return 0;
} 
