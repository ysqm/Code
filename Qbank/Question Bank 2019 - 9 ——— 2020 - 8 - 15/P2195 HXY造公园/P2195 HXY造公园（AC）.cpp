# include <cstdio>
# include <cstring>
# define reg register
# define N 300000
# define LL long long

inline int Read()
{
	 int x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

int fa[N + 42];

template <class T> inline T Min(const T a,const T b){return a < b ? a : b;}
template <class T> inline T Max(const T a,const T b){return a > b ? a : b;}
template <class T> inline T f(const T& x){return x == fa[x] ? x : fa[x] = f(fa[x]);}
template <class T> inline void M(const T& x,const T& y){fa[f(y)] = f(x);}

struct edge
{
	int next,to;
	
	edge(const int next_=0,const int to_=0):next(next_),to(to_){}
} e[(N << 1) + 42];

int head[N + 42],tot_edge=1,S=1,n,m,Q;

inline void add_edge(const int u,const int v)
{
	e[++tot_edge] = edge(head[u],v);
	
	head[u] = tot_edge;
	
	e[++tot_edge] = edge(head[v],u);
	
	head[v] = tot_edge;
	
	M(u,v);
}

int wi[N + 42],ans,dp[N + 42][2],d[N + 42],len;

void dfs(const int& u,const int& fa)
{
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa)
		{
			dfs(e[i].to,u);
			
			int v = dp[e[i].to][0] + 1;
			
			if(v > dp[u][0]){dp[u][1] = dp[u][0];dp[u][0] = v;}
			else if(v > dp[u][1])dp[u][1] = v;
		}
		
	d[u] = Max(d[u],dp[u][0] + dp[u][1]);
	len = Max(len,d[u]);
}

int main()
{
	n = Read();m = Read();Q = Read();
	
	for(reg int i = 1; i <= n ; ++i) fa[i] = i;
	
	for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read());

	for(reg int i = 1; i <= n ; ++i) if(f(i) == i) {len=0;dfs(i,i);d[i] = len;}

	reg int x,y,op;
	
	while(Q--)
	{
		op = Read();
		
		if(op == 1)
		{
			x = Read();
			
			printf("%d\n",d[f(x)]);
		}
		
		else
		{
			x = Read();y = Read();
			
			x = f(x);y = f(y);
			
			M(x,y);
			
			if(x != y) d[x] = Max(d[x],Max(d[y],((d[x]+1)>>1) + ((d[y]+1)>>1) + 1));
		}
	}
	
	return 0;
}
