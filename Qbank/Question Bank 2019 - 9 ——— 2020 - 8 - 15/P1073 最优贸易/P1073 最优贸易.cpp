# include <cstdio>
# include <queue>
# define reg register
# define M 5000000
# define N 300000

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
	int next,to,wi;
} e[M + 42];

std::queue <int> q;
bool inq[N + 42];
int head[N + 42],tot_edge,n,dis[N + 42],ans,T;

inline void add_edge(const int u,const int v,const int wi)
{
	e[++tot_edge] = (edge){head[u],v,wi};
	
	head[u] = tot_edge;
}

inline void INIT()
{
	n = Read();reg int m = Read();
	
	int a[N + 42];
	
	for(reg int i = 1; i <= n ; ++i) a[i] = Read();
	
	int x,y,z;
	
	while(m--)
	{
		x = Read();y = Read();z = Read();
		
		add_edge(x,y,0);
		
		add_edge(x + n,y + n,0);
		
		add_edge(x + (n << 1),y + (n << 1),0);
		
		add_edge(x,y + n,-a[x]);
		
		add_edge(x + n,y + (n << 1),a[x]);
		
		if(z == 2)
		{
			add_edge(y,x,0);
		
			add_edge(y + n,x + n,0);
		
			add_edge(y + (n << 1),x + (n << 1),0);
			
			add_edge(y,x + n,-a[y]);
		
			add_edge(y + n,x + (n << 1),a[y]);
		}
	}
	
	add_edge(n,(T = 3 * n + 1),0);
	
	add_edge(3 * n,T,0);
}

inline void SPFA(const int s)
{
	for(reg int i = 1; i <= n ; ++i) dis[i] = dis[i + n] = dis[i + (n << 1)] = -0x3f3f3f3f;
	
	q.push(s);
	
	dis[1] = 0;
	
	inq[s] = 1;
	
	while(q.size())
	{
		int u = q.front();
		
		/*if(u == 5)
		{
			puts("fucking!!");
		}*/
		
		q.pop();
		
		inq[u] = 0;
		
		for(reg int i = head[u] ; i ; i = e[i].next)
			if( dis[e[i].to] < dis[u] + e[i].wi)
			{				
				dis[e[i].to] = dis[u] + e[i].wi;
					
				if(!inq[e[i].to]) {q.push(e[i].to);inq[e[i].to] = 1;}
			}
	}
	
	printf("%d\n",dis[T]);
}

int main()
{
	INIT();
	
	SPFA(1);
	
	return 0;
}
