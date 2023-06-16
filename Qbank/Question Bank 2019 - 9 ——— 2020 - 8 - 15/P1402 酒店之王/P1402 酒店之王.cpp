# include <queue>
# include <cstdio>
# include <cstring>
# define reg register
# define INF 0x7f7f7f7f
# define V 1000
# define E 1000000

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

inline int Min(int& a,int& b){return a > b ? b : a;} 

struct edge
{
	int next,to,cf;
} e[(E << 1) + 42];

std::queue <int> q;
int n,s,t,head[V + 42],tot_edge = 1,deep[V + 42],cur[V + 42];

inline void add_edge(const int u,const int v,const int wi)
{
	e[++tot_edge] = (edge){head[u],v,wi};
	
	head[u] = tot_edge;
	
	e[++tot_edge] = (edge){head[v],u,0};
	
	head[v] = tot_edge;
}

bool BFS()
{
	memset(deep,0,sizeof(deep));
	
	q.push(s);
	
	deep[s] = 1;
	
	while(q.size())
	{
		int u = q.front();
		
		q.pop();
		
		for(reg int i = head[u]; i ; i = e[i].next)
			if(deep[e[i].to] == 0 && e[i].cf > 0)
			{
				deep[e[i].to] = deep[u] + 1;
				
				q.push(e[i].to);
			}
	}
	
	return deep[t];
}

int DFS(const int& u,int flow)
{
	if(u == t) return flow;
	
	int sum = 0,delta;
	
	for(reg int &i = cur[u]; i ; i = e[i].next)
		if(deep[e[i].to] == deep[u] + 1 && e[i].cf && (delta = DFS(e[i].to,Min(e[i].cf,flow))))
		{
			e[i].cf -= delta;
			
			e[i ^ 1].cf += delta;
			
			sum += delta;
			
			flow -= delta;
			
			if(flow <= 0) return sum;
		}

	return sum;
}

inline int Dinic()
{
	int Max_Flow = 0;
	
	while(BFS())
	{
		for(reg int i = 0 ; i <= V ; ++i) cur[i] = head[i];
		
		Max_Flow += DFS(s,INF);
	}
	
	return Max_Flow;
}

inline void INIT()
{
	int p1,q1;
	
	n = Read();p1 = Read();q1 = Read();t = (s = ((n << 1) + p1 + q1 + 1)) + 1;
	
	for(reg int i = 1; i <= p1 ; ++i) add_edge(s,i,1);
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1; j <= p1 ; ++j)
			if(Read()) add_edge(j,p1 + i,1);
			
	for(reg int i = 1; i <= n ; ++i) add_edge(p1 + i,p1 + n + q1 + i,1);//保证每个人只吃一道菜 
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1; j <= q1 ; ++j)
			if(Read()) add_edge(p1 + q1 + n + i, p1 + n + j,1);
	
	for(reg int i = 1; i <= q1 ; ++i) add_edge(p1 + n + i,t,1);
}

int main()
{
	INIT();
	
	printf("%d",Dinic());
	
	return 0;
}
