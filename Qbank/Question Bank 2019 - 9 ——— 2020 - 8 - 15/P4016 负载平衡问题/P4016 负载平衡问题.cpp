# include <cstdio>
# include <algorithm>
# include <queue>
# include <cstring>
# define N 100
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

inline int Change_Signed(const int x){return x < 0 ? -x : x;}

int n,a[N + 42],AVE,K[N + 42],ans;

signed main()
{
	in(n);
	
	for(reg int i = 1; i <= n ; ++i) AVE += (a[i] = Read());
	
	AVE /= n;
	
	for(reg int i = 1; i <= n ; ++i) a[i] -= AVE;
	
	for(reg int i = 1; i <= n ; ++i) K[i] = K[i - 1] + a[i];
    
    std::sort(K + 1,K + n + 1);
    
    AVE = K[(n + 1) >> 1];
    
    for(reg int i = 1; i <= n ; ++i) ans += Change_Signed(AVE - K[i]);
        
   	printf("%d\n",ans);
	
	return 0;
}
/*
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

int n,m,s = 541,t = 542,head[V + 42],tot_edge = 1,delta,ans,deep[V + 42],cur[V + 42];

inline void add_edge(const int u,const int v,const int wi)
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
	if(u ==  t) return flow;
	
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
		
		for(reg int k = 1; k <= 600 ; ++k) cur[k] = head[k];
		
		Max_Flow += DFS(s,INF);
	}
	
	return Max_Flow;
} 

signed main()
{
	in(n);in(m);
	
	for(reg int i = 1; i <= n ; ++i)
		if(Read() == 1) add_edge(s,i,1);
		else add_edge(i,t,1);
    
    for(reg int i = 1,x,y; i <= m ; ++i) add_edge(x = Read(),y = Read(),1),add_edge(y,x,1);
        
   	printf("%d\n",Dinic());
	
	return 0;
}*/
