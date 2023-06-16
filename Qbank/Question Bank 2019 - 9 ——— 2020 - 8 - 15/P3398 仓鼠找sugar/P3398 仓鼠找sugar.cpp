# include <cstdio>
# include <algorithm>
# define N 100000
# define reg register
# define mod 1000000007

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
	int next,to;
} e[(N << 1) + 42];

int n,head[N + 42],tot_edge,deep[N + 42],father[N + 42],son[N + 42],Size[N + 42],top[N + 42],root = 1;

inline void add_edge(const int u,const int v)
{
	e[++tot_edge] = (edge){head[u],v};
	
	head[u] = tot_edge;
	
	e[++tot_edge] = (edge){head[v],u};
	
	head[v] = tot_edge;
} 

inline void INIT(const int& u)
{
	Size[u] = 1;son[u] = 0;
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father[u]){
			
			father[e[i].to] = u;
			
			deep[e[i].to] = deep[u] + 1;
			
			INIT(e[i].to);
			
			Size[u] += Size[e[i].to];
			
			if(Size[e[i].to] > Size[son[u]]) son[u] = e[i].to;
		}
}

inline void dfs(const int& u,const int& TOP)
{
	top[u] = TOP;
	
	if(son[u]) dfs(son[u],TOP);
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father[u] && e[i].to != son[u]) dfs(e[i].to,e[i].to);
}

inline int LCA(reg int x,reg int y)
{
	while(top[x] != top[y]) deep[top[x]] > deep[top[y]] ? x = father[top[x]] : y = father[top[y]];
	
	return deep[x] > deep[y] ? y : x;
}

signed main()
{
	reg int q;
	
	in(n);in(q);
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read());
	
	INIT(root);
	
	dfs(root,root);
	
	while(q--){
		
		reg int a = Read(),b = Read(),c = Read(),d = Read();
		
		reg int S = LCA(a,b),T = LCA(c,d);
		
		if(deep[S] >= deep[T])
			if(LCA(S,c) == S || LCA(S,d) == S) puts("Y");
			else puts("N");
		else 
			if(LCA(T,a) == T || LCA(T,b) == T) puts("Y");
			else puts("N");
	}
	
	return 0;
}
