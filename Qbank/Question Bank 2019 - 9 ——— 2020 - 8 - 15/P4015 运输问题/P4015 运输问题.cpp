# include <cstdio>
# include <algorithm>
# include <queue>
# include <cstring>
# define V 200
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
	int next,to,cf,cost;
} e[(V << 5) + 42];

int n,m,s,t,head[V + 42],tot_edge = 1;
int flow[V + 42],dis[V + 42],Pre_V[V + 42],Pre_E[V + 42],max_flow,min_cost,G[V + 42][V + 42],a[V + 42],b[V + 42];
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

signed main()
{
	in(m);in(n);t = (s = m + n + 1) + 1;
	
	for(reg int i = 1; i <= m ; ++i) add_edge(s,i,a[i] = Read(),0);
	
	for(reg int i = 1; i <= n ; ++i) add_edge(m + i,t,b[i] = Read(),0);
	
	for(reg int i = 1; i <= m ; ++i)
		for(reg int j = 1; j <= n ; ++j)
			add_edge(i,m + j,INF,G[i][j] = Read());
	
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
    
    printf("%d\n",min_cost);
    
    min_cost = 0;
    
    memset(head,0,sizeof(head));
    
    for(reg int i = 1; i <= m ; ++i) add_edge(s,i,a[i],0);
	
	for(reg int i = 1; i <= n ; ++i) add_edge(m + i,t,b[i],0);
	
	for(reg int i = 1; i <= m ; ++i)
		for(reg int j = 1; j <= n ; ++j)
			add_edge(i,m + j,INF,-G[i][j]);
    
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
	
	printf("%d\n",-min_cost);
	
	return 0;
}
