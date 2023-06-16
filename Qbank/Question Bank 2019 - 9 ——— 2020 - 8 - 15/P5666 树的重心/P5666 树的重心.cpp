# include <cstdio>
# define reg register
# define N 300000
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

int T,n,head[N + 42],Size[N + 42],Son[N + 42][2],s[N + 42][21],edge_tot,dp[N + 42];
long long ans;

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
			
			if(Size[e[i].to] > Size[Son[u][0]]){Son[u][1] = Son[u][0];Son[u][0] = e[i].to;}
			else if(Size[e[i].to] > Size[Son[u][1]]) Son[u][1] = e[i].to;
		}
	
	s[u][0] = Son[u][0];
	
    for(reg int i = 1; i <= 20; ++i) s[u][i] = s[s[u][i-1]][i-1];
}

inline void Multiply(const int& u)
{
	s[u][0] = Son[u][0];
	
    for(reg int i = 1; i <= 20; --i) s[u][i] = s[s[u][i-1]][i-1];
}

inline void find(const int root)
{
	reg int u = root;
	
	for(reg int i = 20; i >= 0 ; --i)  if(Size[s[u][i]] > Size[root]>>1) u = s[u][i];
	
	if(Size[root] - Size[u] <= Size[root]>>1) ans += u;
	
	if(Size[root] - Size[s[u][0]] <= Size[root]>>1) ans += s[u][0];
}

void dfs(const int u,const int father)//遍历边，断开每一条边(u,v) 
{
    int uson = Son[u][0],usize = Size[u];
    
    for(reg int i = head[u]; i ; i = e[i].next)
    	if(e[i].to != father){
    		
    		if(e[i].to == uson) Son[u][0] = Size[Son[u][1]] > n - usize ? Son[u][1] : father;
    		
    		else Son[u][0]= Size[uson] > n - usize ? uson : father;
    		
    		Size[u] = n - Size[e[i].to];
    		
    		s[u][0] = Son[u][0];
		
    		for(reg int i = 1; i <= 20; ++i) s[u][i] = s[s[u][i-1]][i-1];
    	
			find(u);find(e[i].to);
			
    		dfs(e[i].to,u);
		}
	
	Son[u][0] = uson;
	
	Size[u] = usize;
	
  	s[u][0] = Son[u][0];
	
    for(reg int i = 1; i <= 20; ++i) s[u][i] = s[s[u][i-1]][i-1];
}

int main()
{
	T = Read();
	
	while(T--)
	{
		edge_tot = 1;ans = 0;
		
		for(reg int i = 1; i <= n ; ++i) Son[i][0] = Son[i][1] = Size[i] = head[i] = 0;
		
		n = Read();
		
		for(reg int i = 1; i < n ;++i) add_edge(Read(),Read());
		
		INIT(1,0);
		
		dfs(1,0);
		
		printf("%lld\n",ans);
	}
	
	return 0;
}
