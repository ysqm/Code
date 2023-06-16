# include <cstdio>
# include <algorithm>
# include <queue>
# include <cstring>
# define V 100000
# define E 1000000
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

long long dis[V + 5];
int s,t,head[V + 42],tot_edge = 1;
int flow[V + 42],Pre_V[V + 42],Pre_E[V + 42];
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
	
    return dis[t] < dis[0];
}

inline long long MCMF()
{
	long long min_cost = 0;
	
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
	int a,f,b,fa,fb,an,n;
	
	n = Read();a = Read();b = Read();f = Read();fa = Read();fb = Read();t = (s = (n << 1) + 1) + 1;
	
	for(reg int i = 1; i <= n ; ++i)
	{
		an = Read();
		
		add_edge(s,i,an,0);
		
		add_edge(i + n,t,an,0);
		
		add_edge(s,i + n,INF,f);
		
		if(i + 1 <= n) add_edge(i,i + 1,INF,0);
		
		if(i + a + 1 <= n) add_edge(i,i + n + a + 1,INF,fa);
		
		if(i + b + 1 <= n) add_edge(i,i + n + b + 1,INF,fb);
	}
}

signed main()
{
	//freopen("P1251_2.in","r",stdin);
	
	INIT();
	
	printf("%lld\n",MCMF());
	
	return 0;
}
