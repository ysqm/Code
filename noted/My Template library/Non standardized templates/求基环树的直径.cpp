# include <cstdio>
# include <algorithm>
# define reg register
# define N 100000

typedef long long LL;

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

inline LL Max(const LL& a,const LL b){return a < b ? b : a;}
inline LL Min(const LL a,const LL b){return a < b ? a : b;}
inline LL ABS(const LL a){return a < 0 ? -a : a;}

struct edge
{
	int Next,to,wi;
	
	edge(const int Next_=0,const int To_=0,const int wi_=0):Next(Next_),to(To_),wi(wi_){}
} e[(N<<1) + 42];

bool flag=1,vis[N + 42];
int head[N + 42],edge_tot,Circle[N + 42],f[N + 42],Circle_Start,Circle_End,dis[N + 42],n;
LL dp[N + 42][2],Diameter,Pre[N + 42];

inline void add_edge(const int wi,const int v,const int u)
{
	e[++edge_tot] = edge(head[u],v,wi);
	
	head[u] = edge_tot;
	
	e[++edge_tot] = edge(head[v],u,wi);
	
	head[v] = edge_tot;
}

void dfs_Circle(const int u,const int father)
{
	f[u] = father;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != father && ! Circle[e[i].to])
		{
			if(f[e[i].to])
			{
				int v = Circle_Start = u;
				
				Circle[v] = 1;
				
				while(v != e[i].to) Circle[v = f[v]] = 1;
				
				Circle_End = v;
			}
			
			else dfs_Circle(e[i].to,f[e[i].to] = u);
		}
}

void dfs_Diameter(const int u)
{
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != f[u] && !Circle[e[i].to])
		{
			dfs_Diameter(e[i].to);
			
			int d = dp[e[i].to][0] + e[i].wi;
			
			if(d > dp[u][0]){dp[u][1] = dp[u][0];dp[u][0] = d;}
			else if(d > dp[u][1]) dp[u][1] = d;
		}
		
	Diameter = Max(Diameter,dp[u][0]+dp[u][1]);
}

void DFS_Circle_Len(const int u)
{
	vis[u] = 1;
	
	for(reg int i = head[u]; i ; i = e[i].Next)
		if(Circle[e[i].to] && !vis[e[i].to])
		{
			dis[0] += e[i].wi;
			
			dis[e[i].to] = dis[u] + e[i].wi;//DFS完后dis[Circle_Start]中真正存储的是环的长度，但如果按dis数组实际意义这里应该是 0， 
			
			if(e[i].to != Circle_Start) DFS_Circle_Len(e[i].to);
		}
		else if(e[i].to == Circle_End && flag) dis[0] += e[i].wi,flag = false;
}

void DFS_Diameter()
{
	reg int cur = Circle_Start;
	
	while(cur != Circle_End)
	{
		dfs_Diameter(cur);
		
		cur = f[cur];
	}
	
	dfs_Diameter(Circle_End);
}

inline LL W(const int i,const int j)
{
	if(i == 0) return 0;
	
	int disij = ABS(dis[i]-dis[j]);
	
	return Min(dis[0] - disij,disij);
}

inline LL WW(const int i,const int j)
{
	if(i == 0) return 0;
	
	int disij = ABS(dis[i]-dis[j]);
	
	return Max(dis[0] - disij,disij);
}

void Solve()
{
	DFS_Circle_Len(Circle_Start);//dis[0]记录的是环的长度
	
	//dis[Circle_Start] = 0;
	
	f[Circle_End] = Circle_Start;
	
	reg int cur = Circle_Start;
	
	do
	{
		Diameter = Max(Diameter,Max(WW(Pre[cur],cur),dp[Pre[cur]][0] + W(Pre[cur],cur) + dp[cur][0]));
		
		if(dp[Pre[cur]][0] + W(Pre[cur],f[cur]) >= dp[cur][0] + W(f[cur],cur)) Pre[f[cur]] = Pre[cur];
		else Pre[f[cur]] = cur;
		
		cur = f[cur];
	}while(cur != Circle_Start);
	
	do
	{
		Diameter = Max(Diameter,dp[Pre[cur]][0] + W(Pre[cur],cur) + dp[cur][0]);
		
		if(dp[Pre[cur]][0] + W(Pre[cur],f[cur]) >= dp[cur][0] + W(f[cur],cur)) Pre[f[cur]] = Pre[cur];
		else Pre[f[cur]] = cur;
		
		cur = f[cur];
	}while(cur != Circle_Start);
	
	//Diameter = Max(Diameter,dp[Pre[cur]][0] + W(Pre[cur],cur) + dp[cur][0]);
	
	printf((Diameter & 1) ? "%lld.5\n" : "%lld.0\n",(Diameter>>1));
}

int main()
{
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i) add_edge(Read(),Read(),Read());
	
	dfs_Circle(1,1);
	
	DFS_Diameter();
	
	Solve();
	
	return 0;
}
