# include <algorithm>
# include <cstring>
# include <cstdio>
# include <queue>
# define LL long long
# define reg register
# define N 1000
# define M 900000

const int dx[] = {0,2,2,-2,-2,1,-1,1,-1};
const int dy[] = {0,1,-1,1,-1,2,2,-2,-2};

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = x*10 + (ch^48);ch = getchar();}
	
	return x;
} 

struct edge
{
	int Next,to;
	
	edge(const int Next_=0,const int To_=0):Next(Next_),to(To_){}
} e[M + 42];

bool vis[42][42];
int head[N + 42],edge_tot,id[42][42],G[42][42],S,T,n,m;


inline void add_edge(const int u,const int v)
{
	e[++edge_tot] = edge(head[u],v);
	
	head[u] = edge_tot;
}

void Build(const int u,const int x,const int y)
{
	if(vis[x][y]) return;
	
	vis[x][y] = 1; 
	
	for(reg int i = 1; i <= 8 ; ++i)
	{
		int xx = dx[i]+x,yy = dy[i]+y;
		
		if(xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy]) continue;
		
		if(G[xx][yy] == 1) Build(u,xx,yy);
		
		else if(G[xx][yy] != 2) 
		{
			vis[xx][yy] = 1;
			add_edge(u,id[xx][yy]);
		}
	}
}

std::queue<int> q;
bool inq[N + 42];
int dis[N + 42];
LL ans[N + 42]; 

int SPFA()
{
	memset(dis,0x3f,sizeof(dis));
	
	ans[S] = 1;
	
	dis[S] = 0;
	
	q.push(S);
	
	while(q.size())
	{
		int u = q.front();
		
		q.pop();
		
		inq[u] = 0;
		
		++dis[u];
		
		for(reg int i = head[u]; i ; i = e[i].Next)
			if(dis[e[i].to] > dis[u])
			{
				dis[e[i].to] = dis[u];
				
				ans[e[i].to] = ans[u];
				
				if(!inq[e[i].to])
				{
					q.push(e[i].to);
					
					inq[e[i].to] = 1;
				}
			}
			else if(dis[e[i].to] == dis[u]) ans[e[i].to] += ans[u];
			
		--dis[u];
	}
	
	return dis[T] < dis[0];
}

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1; j <= m ; ++j)
		{
			G[i][j] = Read();
			
			id[i][j] = (i-1)*m+j;
		}
		
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1; j <= m ; ++j)
			if(G[i][j] == 0)
			{
				memset(vis,0,sizeof(vis));
				Build(id[i][j],i,j);
			}
			else if(G[i][j] == 3) 
			{
				S = id[i][j];
				memset(vis,0,sizeof(vis));
				Build(id[i][j],i,j);
			}
			else if(G[i][j] == 4) T = id[i][j];
	
	if(SPFA()) printf("%d\n%lld",dis[T]-1,ans[T]);
	else puts("-1");
	
	return 0;
}


