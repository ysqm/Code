# include <cstdio>
# include <algorithm>
# include <queue>
# include <cstring>
# define V 10000
# define E 100000
# define INF 0x7f7f7f7f
# define reg register

inline void in(int& x)
{
	x = 0; char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
}

inline int Read()
{
	reg int x = 0;reg char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;
}

struct edge
{
	int next,to,cf;
} e[(E << 1) + 42];

int n,m,s,t,head[V + 42],tot_edge = 1,delta,ans,deep[V + 42],cur[V + 42];

inline void add_edge(const int wi,const int v,const int u)
{
	e[++tot_edge] = (edge){head[u],v,wi};
	
	head[u] = tot_edge;
	
	e[++tot_edge] = (edge){head[v],u,0};
	
	head[v] = tot_edge;
}

inline bool BFS()
{
	std::queue <int> q;
	
    memset(deep,0,sizeof(deep));
    
    q.push(s);
	
	deep[s] = 1;
	
    while(q.size())
	{
		int u = q.front();
		
		q.pop();
		
	    for(reg int i = head[u]; i ; i = e[i].next)
			if(deep[e[i].to] == 0 && e[i].cf > 0){
				
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
		if(deep[e[i].to] == deep[u] + 1 && e[i].cf && (delta = DFS(e[i].to,flow > e[i].cf ? e[i].cf : flow)))
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
	
	while(BFS()){
		
		for(reg int k = 1; k <= n ; ++k) cur[k] = head[k];
		
		Max_Flow += DFS(s,INF);
	}
	
	return Max_Flow;
} 

signed main()
{
	in(n);in(m);in(s);in(t);
	
	for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read(),Read());
	
	printf("%d",Dinic());
	
	return 0;
}
