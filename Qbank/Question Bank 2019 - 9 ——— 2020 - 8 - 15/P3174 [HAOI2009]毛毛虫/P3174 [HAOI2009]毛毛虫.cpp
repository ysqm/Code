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

inline int Min(const int a,const int b){return a < b ? a : b;}
inline int Max(const int a,const int b){return a > b ? a : b;}

struct edge
{
	int next,to;
	
	edge(const int next_=0,const int to_=0):next(next_),to(to_){}
} e[(N << 1) + 42];

int head[N + 42],tot_edge=1,S=1,n,m;

inline void add_edge(const int u,const int v)
{
	e[++tot_edge] = edge(head[u],v);
	
	head[u] = tot_edge;
	
	e[++tot_edge] = edge(head[v],u);
	
	head[v] = tot_edge;
}

template <class T> inline T Min(const T a,const T b){return a < b ? a : b;}
template <class T> inline T Max(const T a,const T b){return a > b ? a : b;}

int wi[N + 42],ans,f[N + 42][2];

void dfs(const int& u,const int& fa)
{
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa)
		{
			++wi[u];
			
			wi[e[i].to] = 2;
			
			dfs(e[i].to,u);
			
			/*int v = f[u][0] + f[e[i].to][0] + 1;
			
			if(v > f[u][0]){f[u][1] = f[u][0];f[u][0] = v;}
			else if(v > f[u][1]) f[u][1] = v;*/
		}
}

void DFS(const int u,const int fa)
{
	f[u][0] = wi[u];
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa)
		{
			DFS(e[i].to,u);
			
			int v = wi[u] + f[e[i].to][0] - 2;
			
			if(v > f[u][0]){f[u][1] = f[u][0];f[u][0] = v;}
			else if(v > f[u][1]) f[u][1] = v;
			
			ans = Max(ans,f[u][1] + f[u][0] - wi[u]);
		}
}


int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read());

	if(n == 1)
	{
		puts("1");
		
		return 0;
	}

	wi[S] = 1;

	dfs(S,S);
	
	DFS(S,S);
	
	printf("%d\n",ans);
	
	return 0;
}
