# include <cstdio>
# define reg register
# define N 500000
# define INF 0x7f7f7f7f

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9') {x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

struct edge
{
	int next,to;
} e[(N << 1) + 42];

int T,n,head[N + 42],Size[N + 42],Son[N + 42],s[N + 42][21],edge_tot,Q;

inline void add_edge(const int u,const int v)
{
	e[++edge_tot] = (edge){head[u],v};
	
	head[u] = edge_tot;
	
	e[++edge_tot] = (edge){head[v],u};
	
	head[v] = edge_tot;
}

void INIT(const int u,const int father)
{
	Size[u] = 1;
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father)
		{
			INIT(e[i].to,u);
			
			Size[u] += Size[e[i].to];
			
			if(Size[e[i].to] > Size[Son[u]]) Son[u] = e[i].to;

		}
	
	s[u][0] = Son[u];
	
    for(reg int i = 1; i <= 20; ++i) s[u][i] = s[s[u][i-1]][i-1];
}

inline int find(const int root)
{
	reg int u = root,ans = 0;
	
	for(reg int i = 20; i >= 0 ; --i)  if(Size[s[u][i]] > Size[root]>>1) u = s[u][i];
	
	if(Size[root] - Size[u] <= Size[root]>>1) ans += u;
	
	if(Size[root] - Size[s[u][0]] <= Size[root]>>1) ans += s[u][0];
	
	return ans;
}

int main()
{
	n = Read();Q = Read();
		
	for(reg int i = 1; i < n ;++i) add_edge(Read(),Read());
		
	INIT(1,0);
		
	for(reg int i = 1; i <= Q ; ++i) printf("%lld\n",find(Read()));
	
	return 0;
}
