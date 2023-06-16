# include <cstdio>
# include <algorithm>
# include <queue>
# include <cstring>
# define V 100000
# define E 1000000
# define INF 0x7f7f7f7f7f
# define reg register
# define int unsigned long long

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
	int next,to,cf,cost;
} e[(E << 1) + 42];

int s,t,head[V + 42],tot_edge = 1;
int flow[V + 42],dis[V + 42],Pre_V[V + 42],Pre_E[V + 42];
bool vis[V + 42];

inline void add_edge(const int u,const int v,const int wi,const int len)
{
	e[++tot_edge] = (edge){head[u],v,wi,len};
	
	head[u] = tot_edge;
	
	e[++tot_edge] = (edge){head[v],u,0,-len};
	
	head[v] = tot_edge;
}

inline bool SPFA()
{
	std::queue <int> q;
	
    memset(dis,0x7f,sizeof(dis));
    
    memset(flow,0x7f,sizeof(flow));
    
    memset(vis,0,sizeof(vis));
    
    q.push(s);
	
	vis[s] = 1;
	
	dis[s] = 0;
	
    while(q.size())
	{
		int u = q.front();
		
		q.pop();
		
		vis[u] = 0;
		
	    for(reg int i = head[u]; i ; i = e[i].next)
			if(dis[e[i].to] > dis[u] + e[i].cost && e[i].cf > 0){
				
            	dis[e[i].to] = dis[u] + e[i].cost;
            	
                Pre_V[e[i].to] = u;
				
				Pre_E[e[i].to] = i;
                
				flow[e[i].to] = flow[u] > e[i].cf ? e[i].cf : flow[u];
				
                if (!vis[e[i].to])  {vis[e[i].to] = true;  q.push(e[i].to);}
    		}
	}
	
    return dis[t] < INF;
}

inline int MCMF()
{
	int min_cost = 0;
	
	while (SPFA())
    {      
        min_cost += flow[t] * dis[t];
        
        int u = t;
        
		while (u != s)
        {
            e[Pre_E[u]].cf -= flow[t];
            
			e[Pre_E[u] ^ 1].cf += flow[t];
		
            u = Pre_V[u];
        }
    }
    
    return min_cost;
}

inline void INIT()
{
	int p,m,f,n,si,a[2042],N;
	
	N = Read();t = (s = (N << 1) + 1) + 1;
	
	/*for(reg int i = 1; i <= N ; ++i) a[i] = Read();
	
	add_edge(s,1,INF,0);
	
	add_edge(N << 1,t,INF,0);
	
	p = Read();m = Read();f = Read();n = Read();si = Read();
	
	for(reg int i = 1; i <= N ; ++i)
	{
		add_edge(i,i + N,a[i],0);
		
		if(i != N) add_edge(i + N,i + 1,INF,p);
		
		if(i + m <= N) add_edge(i + N,i + m,a[i],f);
		
		if(i + n <= N) add_edge(i + N,i + n,a[i],si);
	}*/
	
	for(reg int i = 1; i <= N ; ++i){a[i] = Read();add_edge(s,i,a[i],0);add_edge(i + N,t,a[i],0);}
	
	p = Read();m = Read();f = Read();n = Read();si = Read();
	
	for(reg int i = 1; i <= N ; ++i)
	{
		add_edge(s,i + N,INF,p);
		
		if(i + 1 <= N) add_edge(i,i + 1,INF,0);
		
		if(i + m <= N) add_edge(i,i + N + m,INF,f);
		
		if(i + n <= N) add_edge(i,i + N + n,INF,si);
	}
	
}

signed main()
{
	//freopen("P1251_2.in","r",stdin);
	
	INIT();
	
	printf("%llu\n",MCMF());
	
	return 0;
}
