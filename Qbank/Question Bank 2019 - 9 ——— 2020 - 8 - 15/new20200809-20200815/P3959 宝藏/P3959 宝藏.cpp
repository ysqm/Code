# include <cstdio>
# include <algorithm>
# define reg register
# define INF 0x7f7f7f7f

int vis[17],lev[17],d[17];
int G[17][17],C[17][17];

int p,ans = INF,tmp,n;

inline bool comp(const int x,const int y){return G[p][x] < G[p][y];}

inline void INIT()
{
	scanf("%d",&n);
	
	register int m,u,v,w;
	
	scanf("%d",&m);
	
	for(reg int i = 1; i <= n ; ++i) 
		for(reg int j = 1;  j <= n ; ++j) 
			G[i][j] = INF;
	
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		
		if(G[u][v] < w) continue;
		else if(G[u][v] == INF) {C[u][++d[u]] = v;C[v][++d[v]] = u;}
		G[u][v] = G[v][u] = w;
	}
	
	for(reg int i = 1; i <= n ; ++i)
	{
		p = i;
		std::sort(C[i]+1,C[i]+d[i]+1,comp);
		tmp += G[i][C[i][1]];
	}
	
	return ;
} 

void dfs(const int num,const int Length,const int cnt,int node)
{
	if(cnt == n) ans = Length < ans ? Length : ans;
	else
	{
		for(reg int i = num; i <= cnt ; ++i)
		{
			if(Length + tmp * lev[vis[i]] >= ans) return ;
			
			for(reg int j = node; j <= d[vis[i]]; ++j)
				if(lev[C[vis[i]][j]] == 0)
				{
					vis[cnt+1] = C[vis[i]][j];
					
					tmp -= G[vis[cnt+1]][C[vis[cnt+1]][1]];
					
					lev[vis[cnt+1]] = lev[vis[i]] + 1;
					
					dfs(i,Length+G[vis[i]][vis[cnt+1]]*lev[vis[i]],cnt+1,j+1);
					
					lev[vis[cnt+1]] = 0;
					
					tmp += G[vis[cnt+1]][C[vis[cnt+1]][1]];
					
					vis[cnt+1] = 0;
				}
			node = 1;
		}
	}
}

inline void Solve()
{
	for(reg int i = 1; i <= n ; ++i)
	{
		vis[1] = i;//选取第一个
		lev[i] = 1;//第一步已扩展
		tmp -= G[i][C[i][1]];
		dfs(1,0,1,1);
		vis[1] = 0;
		lev[i] = 0;
		tmp += G[i][C[i][1]];
	}
	
	printf("%d",ans);
	
	return ;
}

int main()
{
	INIT();
	
	Solve();
	
	return 0;
} 
