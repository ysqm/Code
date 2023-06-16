# include <cstdio>
# include <cstring>
# define N 50000
# define reg register
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
} e[(N << 1) + 42];

int edge_tot,head[N + 42],f[N + 42][17],dep[N + 42],n,m;

inline void add_edge(const int& v,const int& u)
{
	e[++edge_tot].from = head[u];
	
	e[edge_tot].to = v;
	
	head[u] = edge_tot;
	
	e[++edge_tot].from = head[v];
	
	e[edge_tot].to = u;
	
	head[v] = edge_tot;
}

inline void Pre_Lca(const int u)
{
	for(reg int i = 1 ; (1 << i) <= dep[u] ; ++i) f[u][i] = f[f[u][i - 1]][i - 1];
	
	for(reg int i = head[u] ; i ; i = e[i].from)
		if(e[i].to != f[u][0]){
		
			f[e[i].to][0] = u;
		
			dep[e[i].to] = dep[u] + 1;
		
			Pre_Lca(e[i].to);
		}
}

inline int Lca(reg int x,reg int y)
{
	if(dep[x] < dep[y]) x ^= y ^= x ^= y;
	
	for(reg int i = 16 ; i >= 0 ; --i) 
		if((1 << i) <=  dep[x] - dep[y]) x = f[x][i];
	
	if (x == y) return y;
	
	for(reg int i = 16 ; i >= 0 ; --i) 
		if (f[x][i] != f[y][i]){
			
			x = f[x][i];
			
			y = f[y][i];
		}
		
	return f[x][0];
}

int mark[N + 42],ans;

inline void dfs(const int u)
{
	for(reg int i = head[u] ; i ; i = e[i].from)
		if(e[i].to != f[u][0]){
			
			dfs(e[i].to);
			
			mark[u] += mark[e[i].to];
		}
	
	ans = ans > mark[u] ? ans : mark[u];
}

int main()
{
	n = Read(); m = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read());
	
	dep[1] = 1;
	
	Pre_Lca(1);
	
	for(reg int i = 1,a,b ; i <= m ; ++i ){
		
		a = Read();b = Read();
		
		reg int lca=Lca(a,b);
		
		++mark[a];++mark[b];--mark[lca];--mark[f[lca][0]];
	}
	
	//printf("case 1:\n");
	
	//for(int i = 1; i <= n ; ++i) printf("%d\n",mark[i]);
	
	dfs(1);
	
	//printf("case 2:\n");
	
	//for(int i = 1; i <= n ; ++i) printf("%d\n",mark[i]);

	printf("%d",ans);
	
	return 0;
}
