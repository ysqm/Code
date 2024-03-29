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
	reg int x = 0,f = 1;reg char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x*f;
}

struct edge
{
	int next,to,cf;
} e[(E << 1) + 42];

int n,m,s,t,head[V + 42],tot_edge = 1,deep[V + 42],cur[V + 42],Sum_All;

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
	if(u == t) return flow;
	
	int sum = 0,delta;
	
	for(reg int &i = cur[u]; i ; i = e[i].next)
		if(deep[e[i].to] == deep[u] + 1 && e[i].cf > 0 && (delta = DFS(e[i].to,flow > e[i].cf ? e[i].cf : flow)) > 0)
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
	while(BFS()){
		
		memcpy(cur,head,sizeof(cur));
		
		Sum_All -= DFS(s,INF);
	}
	
	return Sum_All;
} 

inline int f(const int i,const int j){return (i - 1) * m + j;}

inline void INIT()
{
	n = Read();m = Read();t = (s = 10001) + 1;
			
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1,c; j <= m ; ++j)
			{
				Sum_All += (c = Read());
				
				/*if((i + j) & 1)
				{
					add_edge(f(i,j),f(i,j) + nm,-c);
				
					if(i != 1) add_edge(f(i,j) + nm,f(i-1,j),INF);
					if(i != n) add_edge(f(i,j) + nm,f(i+1,j),INF);
					if(j != 1) add_edge(f(i,j) + nm,f(i,j-1),INF);
					if(j != m) add_edge(f(i,j) + nm,f(i,j+1),INF);	
				}*/
				
				if((i + j) & 1)
				{
					add_edge(s,f(i,j),c);
				
					if(i != 1) add_edge(f(i,j),f(i-1,j),INF);
					if(i != n) add_edge(f(i,j),f(i+1,j),INF);
					if(j != 1) add_edge(f(i,j),f(i,j-1),INF);
					if(j != m) add_edge(f(i,j),f(i,j+1),INF);	
				}
				
				else add_edge(f(i,j),t,c);
			}
}



signed main()
{
	INIT();
	
	printf("%d\n",Dinic());
	
	return 0;
}
