# include <cstdio>
# include <cstring>
# define reg register
# define N 300000
# define LL long long

inline LL ReadL()
{
	 LL x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

inline int Read()
{
	 int x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

template <class T> inline T Min(const T a,const T b){return a < b ? a : b;}
template <class T> inline T Max(const T a,const T b){return a > b ? a : b;}

struct edge
{
	int next,to,wi;
	
	edge(const int next_=0,const int to_=0,const int wi_=0):next(next_),to(to_),wi(wi_){}
} e[(N << 1) + 42];

struct STACK
{
	int Stack[N + 42],top;
} low,s;

int head[N + 42],tot_edge,S=1,n,m;

inline void add_edge(const int wi,const int u,const int v)
{
	e[++tot_edge] = edge(head[u],v,wi);
	
	head[u] = tot_edge;
	
	e[++tot_edge] = edge(head[v],u,wi);
	
	head[v] = tot_edge;
}

bool ins[N + 42];
int dfn[N + 42],t;

void Gabow(const int u)
{
	dfn[u] = ++t;
	
	low.Stack[++low.top] = s.Stack[++s.top] = u;
	
	ins[u] = 1;
	
	for(reg int i = head[u] ; i ; i = e[i].next)
		if(dfn[e[i].to] == 0) Gabow(e[i].to);
		else if(ins[e[i].to]) while(dfn[low.Stack[low.top]] > dfn[e[i].to]) --low.top;
}

int main()
{
	
	
	return 0;
}
