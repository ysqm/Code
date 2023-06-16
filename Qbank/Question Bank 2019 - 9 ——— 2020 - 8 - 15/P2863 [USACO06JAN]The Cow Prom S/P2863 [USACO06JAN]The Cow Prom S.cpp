# include <cstdio>
# include <algorithm>
# define N 10000
# define M 50000
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
	int next,to,wi;
} e[(M << 1) + 42];

struct STACK
{
	int Stack[N + 42],top;
} s,low;

bool instack[N + 42];
int n,m,head[N + 42],tot_edge,id[N + 42],root = 1,dfn[N + 42],colour_tot,t,cnt[N + 42],ans;

inline void add_edge(const int v,const int u)
{
	e[++tot_edge] = (edge){head[u],v};
	
	head[u] = tot_edge;
	
	//e[++tot_edge] = (edge){head[v],u,wi};
	
	//head[v] = tot_edge;
} 

inline void Gabow(const int& u)
{
	dfn[u] = ++t;
	
	s.Stack[++s.top] = low.Stack[++low.top] = u;
	
	instack[u] = true;
	
	for(reg int i = head[u] ; i ; i = e[i].next)
		if(dfn[e[i].to] == 0) Gabow(e[i].to);
		
		else if(instack[e[i].to]) while(dfn[low.Stack[low.top]] > dfn[e[i].to]) low.top--;
		
	if(u == low.Stack[low.top]){
		int p;
		
		low.top--;
		
		colour_tot++;
		
		do{
			++cnt[id[p = s.Stack[s.top--]] = colour_tot];
			
			instack[p] = false;
			
		} while(p != u);
		
	}
}


signed main()
{
	in(n);in(m);
	
	for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read());
	
	for(reg int i = 1; i <= n ; ++i) if(dfn[i] == 0) Gabow(i);
	
	for(reg int i = 1; i <= colour_tot ; ++i) if(cnt[i] > 1) ++ans;
	
	printf("%d\n",ans);
	
	return 0;
}
