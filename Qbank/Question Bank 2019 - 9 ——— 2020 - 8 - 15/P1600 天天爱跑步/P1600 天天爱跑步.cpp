# include <cstdio>
# include <cstring>
# define N 600000
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
inline T min(reg const T& A,reg const T B){return A < B ? A : B;}

template <typename T>
inline T Max(reg const T& A,reg const T B){return A < B ? B : A;} 

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
} e[(N << 1) + 42],e1[(N << 1) + 42],e2[(N << 1) + 42];

int edge_tot,edge_tot1,edge_tot2,head[N + 42],f[N + 42][17],dep[N + 42],n,m,w[N + 42],h1[N + 42],h2[N + 42];

inline void add_edge(const int& v,const int& u)
{
	e[++edge_tot].from = head[u];
	
	e[edge_tot].to = v;
	
	head[u] = edge_tot;
	
	e[++edge_tot].from = head[v];
	
	e[edge_tot].to = u;
	
	head[v] = edge_tot;
}

inline void add_edge1(const int& u,const int& v)
{
	e1[++edge_tot1].from = h1[u];
	
	e1[edge_tot1].to = v;
	
	h1[u] = edge_tot1;
	
}

inline void add_edge2(const int& u,const int& v)
{
	e2[++edge_tot2].from = h2[u];
	
	e2[edge_tot2].to = v;
	
	h2[u] = edge_tot2;
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
int b1[(N << 1) + 42],b2[(N << 1) + 42],js[N + 42],dist[N + 42],s[N + 42],t[N + 42],ans[N + 42];

inline void dfs(reg int x)
{
    int t1 = b1[w[x] + dep[x]],t2 = b2[w[x] - dep[x] + N];
    
    for(reg int i = head[x]; i ; i = e[i].from)
    	if(e[i].to != f[x][0]) dfs(e[i].to);
    	
    b1[dep[x]] += js[x];
    
    for(reg int i = h1[x] ; i ; i = e1[i].from) ++b2[dist[e1[i].to] - dep[t[e1[i].to]] + N];
    
    ans[x] += b1[w[x] + dep[x]] - t1 + b2[w[x] - dep[x] + N] - t2;
    
    for(reg int i = h2[x]; i; i = e2[i].from){
    	
        --b1[dep[s[e2[i].to]]];
        
        --b2[dist[e2[i].to]-dep[t[e2[i].to]]+N];
        
    }
}

int main()
{
    n = Read(); m = Read();
    
    for(reg int i = 1 ; i < n; ++i) add_edge(Read(),Read());
    
    dep[1] = 1;
    
    Pre_Lca(1);
    
    for(reg int i = 1; i <= n; ++i) in(w[i]);
	
	for(int i = 1; i <= m; ++i)
    {
        in(s[i]);in(t[i]);
        
        int lca = Lca(s[i], t[i]);
        
        dist[i] = dep[s[i]] + dep[t[i]] - (dep[lca] << 1);
        
        js[s[i]]++;
        
        add_edge1(t[i], i);
        
        add_edge2(lca, i);
        
        if(dep[lca] + w[lca] == dep[s[i]]) --ans[lca];
    }
    
    dfs(1);
    
    for(int i=1; i<=n; i++) printf("%d ", ans[i]);
	
	return 0;
}
