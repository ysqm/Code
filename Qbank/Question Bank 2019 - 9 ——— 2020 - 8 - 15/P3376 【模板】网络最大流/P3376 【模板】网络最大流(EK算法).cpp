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

int n,m,s,t,head[V + 42],tot_edge = 1,delta,ans,Pre[V + 42],ID[V + 42];

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
	
	bool book[V + 42];
	
    memset(book,0,sizeof(book));
    
    book[s] = true;q.push(s);
	
    while(q.size())
	{
		int u = q.front();
		
		q.pop();
		
		if(u == t)   return true; //BFSËÑµ½ÁË»ãµã
		
	    for(reg int i = head[u]; i ; i = e[i].next)
			if(!book[e[i].to] && e[i].cf > 0)
			{
            	book[e[i].to] = true;
            	
    			q.push(e[i].to);

    			Pre[e[i].to] = u;
    			
    			ID[e[i].to] = i;
    		}
	}
	
    return false;
}

void dfs_update(const int& v)
{
	if(v == s) return;
	
	delta = delta > e[ID[v]].cf ? e[ID[v]].cf : delta;
	
	dfs_update(Pre[v]);
	
	e[ID[v]].cf -= delta;
	
	e[ID[v] ^ 1].cf += delta;
}

signed main()
{
	in(n);in(m);in(s);in(t);
	
	for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read(),Read());
	
	while(BFS()){
		delta = INF;
		
        dfs_update(t);
		      
		ans += delta;
	}
	
	printf("%d",ans);
	
	return 0;
}
