# include <algorithm>
# include <cstring>
# include <cstdio>
# include <queue>
# define LL long long
# define reg register
# define N 10000
# define M 50000

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = x*10 + (ch^48);ch = getchar();}
	
	return x;
} 

struct edge
{
	int Next,to,wi;
	
	edge(const int Next_=0,const int To_=0,const int wi_=0):Next(Next_),to(To_),wi(wi_){}
} e[(M<<1) + 42];

int head[N + 42],edge_tot;

inline void add_edge(const int wi,const int v,const int u)
{
	e[++edge_tot] = edge(head[u],v,wi);
	
	head[u] = edge_tot;
	
	e[++edge_tot] = edge(head[v],u,wi);
	
	head[v] = edge_tot;
}

bool inq[N + 42];
int dis[N + 42],City[N + 42],n,m,b;
std::queue<int> q;

bool SPFA(const int BL)
{
	memset(dis,0,sizeof(dis));
	
	dis[1] = b;
	
	q.push(1);
	
	while(q.size())
	{
		int u = q.front();q.pop();
		
		inq[u] = 0;
		
		for(reg int i = head[u]; i ; i = e[i].Next)
			if(dis[e[i].to] < dis[u] - e[i].wi && City[e[i].to] <= BL)
			{
				dis[e[i].to] = dis[u] - e[i].wi;
				
				if(!inq[e[i].to])
				{
					q.push(e[i].to);
					
					inq[e[i].to] = 1;
				}
			}
	}
	
	return dis[n];
}

int main()
{
	n = Read();m = Read();b = Read();
	
	for(reg int i = 1; i <= n ; ++i) City[i] = Read();
	
	for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read(),Read());
	
	reg int l = 0,r = 1000000001,mid;
	
	while(l < r)
	{
		mid = (l+r)>>1;
		
		if(SPFA(mid)) r = mid;
		else l = mid+1;
	}
	
	printf(l == 1000000001 ? "AFK" :"%d",l);
	
	return 0;
}


