# include <cstdio>
# define reg register 
# define N 1000

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

struct edge
{
	int Next,to;
	
	edge(const int Next_=0,const int To_=0):Next(Next_),to(To_){}
	
} e[(N << 1) + 42];

int head[N + 42],tot_edge;

inline void add_edge(const int u,const int v)
{
	e[++tot_edge] = edge(head[u],v);
	
	head[u] = tot_edge;
	
	e[++tot_edge] = edge(head[v],u);
	
	head[v] = tot_edge;
}

bool vis[N + 42];
int q[N + 42],top,tail,n,Stack[N + 42],tp,fa[N + 42],ans;

void dfs(const int u,const int dep)
{
	if(dep > 2) return ;
	
	vis[u] = 0;
	
	for(reg int i = head[u]; i ; i = e[i].Next) dfs(e[i].to,dep+1);
}

int main()
{
	n = Read();
	
	for(reg int i = 2; i <= n ; ++i) add_edge(i,Read());
	
	q[++top] = 1;
	
	vis[1] = 1;
	
	fa[1] = 1;
	
	while(tail != n)
	{
		reg int u = q[++tail];
		
		Stack[++tp] = u;
		
		for(reg int i = head[u]; i ; i = e[i].Next)
			if(!vis[e[i].to])
			{
				fa[e[i].to] = u;
				
				q[++top] = e[i].to;
				
				vis[e[i].to] = 1;
			}
	}
	
	for(reg int i = n; i ; --i)	if(vis[Stack[i]] && ++ans) dfs(fa[fa[Stack[i]]],0);
	
	printf("%d",ans); 
	
	return 0;
}
