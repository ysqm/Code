# include <cstdio>
# include <cstring>
# define reg register
# define N 2000
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
	int next,to,wi;
	
	edge(const int next_=0,const int to_=0,const int wi_=0):next(next_),to(to_),wi(wi_){}
} e[(N << 1) + 42];

int head[N + 42],tot_edge=1,S=1,n,m;

inline void add_edge(const int wi,const int u,const int v)
{
	e[++tot_edge] = edge(head[u],v,wi);
	
	head[u] = tot_edge;
	
	e[++tot_edge] = edge(head[v],u,wi);
	
	head[v] = tot_edge;
}

template <class T> inline T Min(const T a,const T b){return a < b ? a : b;}
template <class T> inline T Max(const T a,const T b){return a > b ? a : b;}

int k;
LL dp[N + 42][N + 42],Size[N + 42];

void dfs(const int& u,const int& fa)
{
	Size[u] = 1;dp[u][0] = dp[u][1] = 0;
		
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa)
		{
			dfs(e[i].to,u);
			
			for(reg int j = Min(Size[u],k); ~j ; --j)
				for(reg int l = Size[e[i].to]; ~l ; --l)
					dp[u][j+l] = Max(dp[u][j+l],
					dp[u][j] + dp[e[i].to][l]
					 + (LL)l * e[i].wi * (k - l)
					 + (LL)(Size[e[i].to] - l) * e[i].wi * (n - k + l - Size[e[i].to]));
			
			Size[u] += Size[e[i].to];
		}
}


int main()
{
	n = Read();k = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read(),Read());

	dfs(S,S);
	
	printf("%lld\n",dp[1][k]);
	
	return 0;
}



