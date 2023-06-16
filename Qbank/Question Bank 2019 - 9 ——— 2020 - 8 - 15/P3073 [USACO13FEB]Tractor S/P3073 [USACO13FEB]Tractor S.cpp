# include <cstdio>
# include <cstring>
# include <algorithm>
# include <vector> 
# define reg register
# define N 250000
# define LL long long
using namespace std;

inline LL Read()
{
	 LL x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

inline int Min(const int a,const int b){return a < b ? a : b;}
inline int Max(const int a,const int b){return a > b ? a : b;}
inline int ABS(const int a){return a < 0 ? -a : a;} 

struct edge
{
	int from,to,wi;
	
	edge(const int& next_=0,const int& to_=0,const int& wi_=0):from(next_),to(to_),wi(wi_){}
	
	inline friend bool operator < (const edge a,const edge b){return a.wi < b.wi;}
	
} e[(N << 2) + 42];

int tot_edge;

inline void add_edge(const int u,const int v,const int wi)
{
	e[++tot_edge] = edge(v,u,wi);
}

int fa[N + 42],G[542][542],n,d[N + 42];

inline int calc(const int x,const int y){return x + (y-1) * n;}
inline int Find(const int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}

int main()
{
	n = Read();
	
	int Limit = n * n,xk;
	
	xk = (Limit + 1) >> 1;
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1; j <= n ; ++j)
			G[i][j] = Read();
			
	for(reg int i = 1; i <= Limit ; ++i) fa[i] = i;
	
	for(reg int i = 1; i <= Limit ; ++i) d[i] = 1;
		
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1; j <= n ; ++j)
		{
			if(j + 1 <= n) add_edge(calc(i,j),calc(i,j+1),ABS(G[i][j] - G[i][j+1]));
			if(i + 1 <= n) add_edge(calc(i,j),calc(i+1,j),ABS(G[i][j] - G[i+1][j]));
		}
			
			
	sort(e + 1,e + tot_edge + 1);
	
	for(reg int i = 1; i <= tot_edge ; ++i)
	{
		if(Find(e[i].from) == Find(e[i].to)) continue;
		
		d[fa[e[i].from]] += d[fa[e[i].to]];
		
		fa[fa[e[i].to]] = fa[fa[e[i].from]];
		
		if(d[fa[e[i].from]] >= xk) 
		{
			printf("%d\n",e[i].wi);
			break;
		}
	}
	return 0;
}
