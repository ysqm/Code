# include <cstdio>
# include <algorithm>
# include <cmath>
# define N 10000
# define M 50000
# define R register
using namespace std;

inline int r()
{
	int f = 1,x = 0;;
	
	char c = getchar();
	
	while(c > '9' || c < '0'){
		if(c == '-') f = -1;
		
		else f = 1;
		
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
	int from,to,wi;
} e[(M << 1) + 42];

struct Edge
{
	int start,to,wi;
} E[M + 42];

inline bool comp(const Edge a,const Edge b)
{
	return a.wi > b.wi;
}

int head[N + 42],e_cnt,n,m,f[N + 42][20],s,deep[N + 42],maxstep,a[N + 42],dp[N + 42][20],q;

inline void add(int u,int v,int wi)
{
	e[++e_cnt].from = head[u];
	
	e[e_cnt].to = v;
	
	e[e_cnt].wi = wi;
	
	head[u] = e_cnt;
	
	e[++e_cnt].from = head[v];
	
	e[e_cnt].to = u;
	
	e[e_cnt].wi = wi;
	
	head[v] = e_cnt;
	
}

inline int fi(const int i)
{
	return a[i] == i ? i : a[i] = fi(a[i]);
}

inline void INIT()
{
	sort(E + 1,E + 1 + m,comp);
	
	for(R int i = 1; i <= n ; i++)
		a[i] = i;
		
	for(R int i = 0; i <= n ; i++)
		for(R int j = 0; j <= n ; j++)
			dp[i][j] = 21000000;
	
	for(R int i = 1; i <= m ; i++)
		if(fi(E[i].start) != fi(E[i].to)){
			a[fi(E[i].to)] = a[fi(E[i].start)];
			
			add(E[i].to,E[i].start,E[i].wi);
		}
}

inline void dfs(int u)
{
	
	for(R int j = 1; (1 << j) <= deep[u]; j++){
		f[u][j] = f[f[u][j - 1]][j - 1];
		
		dp[u][j] = min(dp[f[u][j - 1]][j - 1],dp[u][j - 1]);
	}
	
	for(int i = head[u]; i ; i = e[i].from)
		if(deep[e[i].to] == 0) {
			
			f[e[i].to][0] = u;
			
			dp[e[i].to][0] = e[i].wi;
			
			deep[e[i].to] = deep[u] + 1;
			
			dfs(e[i].to);
		}
	maxstep = log2(n) + 1;
		
}

inline void work(int x,int y)
{
	if(deep[x] < deep[y]){
		int temp;
		
		temp = x;
		
		x = y;
		
		y = temp;
	}
	
	int deth = deep[x] - deep[y],ans = 200000;
	
	if(deth)
		for(R int j = maxstep; j >= 0 ; j--)
			if((1 << j) & deth) {
				ans = min(dp[x][j],ans);
				x = f[x][j];
			}
				
	if(x == y && x != 0 && y != 0) {
		printf("%d\n",ans);
		return ;
	}
	
	for(R int i = maxstep; i >= 0; i--)
		if(f[x][i] != f[y][i]){
			ans = min(dp[x][i],min(dp[y][i],ans));
			x = f[x][i];
			y = f[y][i];
		}
		
	if(f[x][0] == f[y][0] && f[x][0]) printf("%d\n",min(dp[x][0],min(dp[y][0],ans)));
	else printf("-1\n");
}

int main()
{
	freopen("2.in","r",stdin);
	
	n = r();m = r();
	
	for(R int i = 1; i <= m; i++){
		E[i].start = r();
		E[i].to = r();
		E[i].wi = r();
	}
	
	INIT();
	
	for(R int i = 1; i <= n ; i++)
		if(deep[i] == 0){
			deep[i] = 1;
	
			dfs(i);
		}
		
	q = r();
	
	while(q--) work(r(),r());
	
	return 0;
} 
