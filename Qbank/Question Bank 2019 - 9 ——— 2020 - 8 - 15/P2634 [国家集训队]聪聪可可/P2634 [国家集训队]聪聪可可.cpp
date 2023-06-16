# include <cstdio>
# include <algorithm>
# define N 20000
# define reg register

inline void in(int& x)
{
	x = 0; char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
}

inline int Read()
{
	reg int x = 0;reg char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;
}

struct edge
{
	int next,to,wi;
} e[(N << 1) + 42];

int n,head[N + 42],tot_edge,f[N + 42][3],root = 1,ans;

inline void add_edge(const int wi,const int u,const int v)
{
	e[++tot_edge] = (edge){head[u],v,wi};
	
	head[u] = tot_edge;
	
	e[++tot_edge] = (edge){head[v],u,wi};
	
	head[v] = tot_edge;
} 

inline int mod(const int x){return (x % 3 + 3) % 3;}

inline void dfs(const int& u,const int& father)
{
	f[u][0] = 1;
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father){
			
			dfs(e[i].to,u);
			
			for(reg int j = 0; j < 3 ; ++j) ans += (f[e[i].to][j] * f[u][mod(- j - e[i].wi)]) << 1;
			
        	for(reg int j = 0; j < 3 ; ++j) f[u][mod(j + e[i].wi)] += f[e[i].to][j];
        	
		}
}

inline int gcd(reg int x,reg int y)
{
	if(x == 0 || y == 0) return x | y;
	
	reg int t;
	
	while(t = x % y) {x = y;y = t;}
	
	return y;
}

signed main()
{
	in(n);
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read(),Read());
	
	dfs(root,root);
	
	ans += n;
	
	reg int full = n * n,GCD = gcd(ans,full);
	
	ans /= GCD;full /= GCD;
	
	printf("%d/%d\n",ans,full);
	
	return 0;
}
