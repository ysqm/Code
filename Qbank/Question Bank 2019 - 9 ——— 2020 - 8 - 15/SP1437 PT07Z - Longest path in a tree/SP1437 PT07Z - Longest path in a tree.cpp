# include <cstdio>
# include <cstring>
# include <cmath>
# define reg register
# define N 5000
# define LL long long
using namespace std;

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	return x;
}

inline int Max(const int a,const int b){return a > b ? a : b;}
inline int Min(const int a,const int b){return a < b ? a : b;}

struct edge
{
	int next,to;
	
	edge(const int& ne = 0,const int& tt = 0):next(ne),to(tt){}
	
} e[(N << 1) + 42];

int head[N + 42],tot_edge = 1,n;

inline void add_edge(const int u,const int v)
{
	e[++tot_edge] = edge(head[u],v);
	
	head[u] = tot_edge;
	
	e[++tot_edge] = edge(head[v],u);
	
	head[v] = tot_edge;
}
//切的边必然在直径上，且切的边是该树得任意一条直径都必须经过的边 
int f[N + 42][2],Ans;

void dfs1(const int u,const int fa)
{	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa)
		{
			dfs1(e[i].to,u);
			
			int v = f[e[i].to][0] + 1;
			
   			if(v > f[u][0]){f[u][1] = f[u][0];f[u][0] = v;}
   			
   			else if(v > f[u][1]){f[u][1] = v;}
		}
		Ans = Max(Ans,f[u][1] + f[u][0]);
}

int main()
{
	n = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read());

	dfs1(1,1);
	
	printf("%d",Ans);
	
	return 0;
}
