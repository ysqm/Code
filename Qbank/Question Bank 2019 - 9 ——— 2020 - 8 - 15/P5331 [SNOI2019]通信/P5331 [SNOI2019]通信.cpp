/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
=======`-.____`-.___\_____/___.-`____.-'=======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  	 Buddha said:
         	 	 The program have no BUG.
         	 	 The program can pass the text.
*/
# include <cstdio>
# include <algorithm>
# include <queue>
# include <cstring>
# define V 2000
# define E 2000000
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
} e[E + 42];

int n,W,s,t,head[V + 42],tot_edge = 1;
int flow[V + 42],dis[V + 42],Pre_V[V + 42],Pre_E[V + 42],a[V + 42];
bool vis[V + 42];

inline int Abs(const int x){return x < 0 ? -x : x;}

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
	in(n);in(W);t = (s = V + 1) + 1;
	
	for(reg int i = 1; i <= n ; ++i) a[i] = Read();
	
	for(reg int i = 1; i <= n ; ++i)
	{
		add_edge(s,i,1,0);
		
		add_edge(i,t,1,W);
		
		add_edge(n + i,t,1,0);
		
		for(reg int j = 1,w ; j < i ; ++j)
			if((w = Abs(a[i] - a[j])) < W) add_edge(i,n + j,1,w);
	}	
	
	long long Min_Cost = 0;
	
	while (SPFA())
    {  
        Min_Cost += flow[t] * dis[t];
        
        int u = t;
        
		while (u != s)
        {
            e[Pre_E[u]].cf -= flow[t];
            
			e[Pre_E[u] ^ 1].cf += flow[t];
		
            u = Pre_V[u];
        }
    }
    
    printf("%lld",Min_Cost);
	
	return 0;
}
