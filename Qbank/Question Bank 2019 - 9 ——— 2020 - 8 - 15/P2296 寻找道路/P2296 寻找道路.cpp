# include <cstdio>
# include <queue>
# define reg register
# define N 10000
# define M 200000
# define mod 10007
# define wi(i) Point[e[i].to]

//template <class T>
inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9'){if(	ch == '-') f = -1;ch = getchar();}

	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x * f;
}

struct edge
{
	int next,to;
} e[M + 42],_e[M + 42];

std::queue <int> q;
bool vis_t[N + 42],vis[N + 42],inq[N + 42];
int head[N + 42],_head[N + 42],s,t,tot_edge,n,dis[N + 42];

inline void add_edge(const int v,const int u)
{
	if(u == v) return ;
	
	_e[++tot_edge] = (edge){_head[v],u};
	
	_head[v] = tot_edge;
	
	e[tot_edge] = (edge){head[u],v};
	
	head[u] = tot_edge;
}

inline void INIT()
{
	n = Read();reg int m = Read();
	
	while(m--) add_edge(Read(),Read());
	
	s = Read();t = Read();
}

inline int Max(const int& a,const int b){return a > b ? a : b;}

inline void BFS_T()
{
	q.push(t);
	
	vis_t[t] = 1;
	
	while(q.size())
	{
		int u = q.front();
		
		q.pop();
		
		for(reg int i = _head[u]; i ; i = _e[i].next)
			if(!vis_t[_e[i].to])
			{
				vis_t[_e[i].to] = 1;
				
				q.push(_e[i].to);
			}
	}
}

inline void check()
{
	for(reg int i = 1,f = 1; i <= n ; ++i)
		if(vis_t[i])
		{
			for(reg int j = head[i]; j ; j = e[j].next) 
				if(!vis_t[e[j].to]){f = 0;break;}
			
			if(f) vis[i] = 1;
			
			else f = 1;
		}
}

inline void ans()
{
	q.push(s);
	
	while(q.size())
	{
		int u = q.front();
		
		q.pop();
		
		if(dis[t]){printf("%d\n",dis[t]);return ;}
		
		for(reg int i = head[u]; i ; i = e[i].next)
			if(vis[e[i].to] && dis[e[i].to] == 0)
			{
				dis[e[i].to] = dis[u] + 1;
				
				q.push(e[i].to);
			}
	}
	
	puts("-1");
}

int main()
{
	INIT();
	
	BFS_T();
	
	if(!vis_t[s]){puts("-1");return 0;}
	
	check();
	
	if(!vis[s]){puts("-1");return 0;}
	
	ans();
	
	return 0;
}
