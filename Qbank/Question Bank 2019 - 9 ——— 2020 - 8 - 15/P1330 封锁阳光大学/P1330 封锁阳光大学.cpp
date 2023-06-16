# include <cstdio>
# include <cstring>
# define N 100000
# define reg register
# define int long long
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
} e[N + 42];

int edge_tot,G[10042],head[10042],n,m,c[3],ans;

inline void add_edge(const int& v,const int& u)
{
	e[++edge_tot].from = head[u];
	
	e[edge_tot].to = v;
	
	head[u] = edge_tot;
	
	e[++edge_tot].from = head[v];
	
	e[edge_tot].to = u;
	
	head[v] = edge_tot;
}

inline bool dfs(const int u,const int colour)
{
	if(G[u]){
		
		if(G[u] == colour) return true;
		
		return false;
	}
	
	++c[G[u] = colour];
	
	bool flag = true;
	
	for(reg int i = head[u]; i && flag ; i = e[i].from) flag = flag & dfs(e[i].to,colour == 1 ? 2 : 1);
	
	return flag;
}

signed main()
{
	
	in(n);in(m);
	
	for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read());
	
	for(reg int i = i; i <= n ; ++i){
		
		if(G[i]) continue;
		
		c[1] = c[2] = 0;
		
		if(!dfs(i,1)){printf("Impossible");return 0;}
		
		ans += c[1] > c[2] ? c[2] : c[1];
	}
	
	printf("%lld",ans);
	
	return 0;
}
