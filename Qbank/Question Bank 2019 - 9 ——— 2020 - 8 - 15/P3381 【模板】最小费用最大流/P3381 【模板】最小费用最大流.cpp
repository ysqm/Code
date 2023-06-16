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
	int next,to,cf,cost;
} e[(E << 1) + 42];

int n,m,s,t,head[V + 42],tot_edge = 1;
int flow[V + 42],dis[V + 42],Pre_V[V + 42],Pre_E[V + 42],max_flow,min_cost;
bool vis[V + 42];

inline void add_edge(const int len,const int wi,const int v,const int u)
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
	in(n);in(m);in(s);in(t);
	
	for (reg int i = 1; i <= m; ++i) add_edge(Read(),Read(),Read(),Read());
	
	while (SPFA())
    {
        max_flow += flow[t];
        
        min_cost += flow[t] * dis[t];
        
        int u = t;
        
		while (u != s)
        {
            e[Pre_E[u]].cf -= flow[t];
            
			e[Pre_E[u] ^ 1].cf += flow[t];
		
            u = Pre_V[u];
        }
    }
    
    printf("%d %d",max_flow,min_cost);
	
	return 0;
}
