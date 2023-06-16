# include <cstdio>
# include <queue>
# define reg register
# define M 5000
# define N 1000

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
} e[(M << 1) + 42];

std::queue <int> q;
bool inq[N + 42];
int head[N + 42],tot_edge,n,m,Entry[N + 42],dis[N + 42],ans;

inline void add_edge(const int wi,const int u,const int v)
{
	e[++tot_edge] = (edge){head[u],v,wi};
	
	head[u] = tot_edge;
}

inline void INIT()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read(),Read());
	
	for(reg int i = 1; i <= n ; ++i) add_edge(0,n + 1,i);
	
	for(reg int i = 1; i <= n ; ++i) dis[i] = 0x3f3f3f3f;
}

inline void SPFA(const int s)
{
	q.push(s);
	
	inq[s] = 1;
	
	while(q.size())
	{
		int u = q.front();
		
		q.pop();
		
		if((++Entry[u]) > n - 1){puts("NO SOLUTION");return;}
		
		inq[u] = 0;
		
		for(reg int i = head[u] ; i ; i = e[i].next)
			if( dis[e[i].to] > dis[u] + e[i].wi)
			{				
				dis[e[i].to] = dis[u] + e[i].wi;
					
				if(!inq[e[i].to]) {q.push(e[i].to);inq[e[i].to] = 1;}
			}
	}
	
	for(reg int i = 1; i <= n ; ++i) ans = ans < dis[i] ? ans : dis[i];
	
	for(reg int i = 1; i <= n ; ++i) printf("%d\n",dis[i] - ans);
}

int main()
{
	INIT();
	
	SPFA(n + 1);
	
	return 0;
}
