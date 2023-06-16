# include <cstdio>
# include <cstring>
# include <cmath>
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
# define reg register
# define N 5000
# define LL long long
# define INF 0x3f3f3f3f 
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
	int next,to,wi;
	
	edge(const int& ne = 0,const int& tt = 0,const int& w = 0):next(ne),to(tt),wi(w){}
	
} e[(N << 1) + 42];

int head[N + 42],tot_edge = 1,n;

inline void add_edge(const int wi,const int u,const int v)
{
	e[++tot_edge] = edge(head[u],v,wi);
	
	head[u] = tot_edge;
	
	e[++tot_edge] = edge(head[v],u,wi);
	
	head[v] = tot_edge;
}
//切的边必然在直径上，且切的边是该树得任意一条直径都必须经过的边 
int f[N + 42][2],Ans = INF,mv[N + 42],S,T,diameter,radius,dis[N + 42],ded[N + 42],tde;
bool book[N + 42];

void dfs(const int u,const int fa)
{	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa)
		{
			dis[e[i].to] = dis[u] + e[i].wi;
			
			mv[e[i].to] = i;
			
			dfs(e[i].to,u);
		}
}

void Diameter(const int u)
{	
	book[u] = 1;

	for(reg int i = head[u]; i ; i = e[i].next)
		if(!book[e[i].to])
		{
			Diameter(e[i].to);
			
			int v = f[e[i].to][0] + e[i].wi;
			
   			if(v > f[u][0]){f[u][1] = f[u][0];f[u][0] = v;mv[u] = e[i].to;}
   			
   			else if(v > f[u][1]){f[u][1] = v;}
		}
	diameter = Max(diameter,f[u][1] + f[u][0]);
}

void Radius(const int u,const int front)
{	
	book[u] = 0;radius = Min(radius,Max(front,f[u][0]));

	for(reg int i = head[u]; i ; i = e[i].next)
		if(book[e[i].to]) Radius(e[i].to,Max(front,mv[u] == e[i].to ? f[u][1] : f[u][0]) + e[i].wi);
}


int main()
{
	n = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read(),Read());
	
	dfs(1,1);
	
	for(reg int i = 1; i <= n ; ++i) if(dis[S] < dis[i]) S = i;
	
	dis[S] = 0;
	
	for(reg int i = 1; i <= n ; ++i) mv[i] = 0;
	
	dfs(S,S);
	
	for(reg int i = 1; i <= n ; ++i) if(dis[T] < dis[i]) T = i;
	
	for(reg int i = mv[T]; i ; i = mv[e[i^1].to])  
		ded[++tde] = i;
	
	for(reg int i = 1; i <= n ; ++i) mv[i] = 0;
	
	for(reg int i = 1; i <= tde; i++)//可优化，只删直径 
	{
		int d1,d2,r1,r2;
		
		diameter = 0;
		
		book[e[ded[i]].to]=1;
		
		Diameter(e[ded[i]^1].to);
		
		d1 = diameter;
		
   		diameter = 0;
   		
		Diameter(e[ded[i]].to);
		
		d2 = diameter;
		 
   		book[e[ded[i]^1].to]=0;
   		
   		radius = INF;
   		
		Radius(e[ded[i]].to,0);
		
		r1 = radius;
		
   		radius = INF;
   		
		Radius(e[ded[i]^1].to,0);
   		
		r2 = radius;
		
   		Ans = Min(Ans,Max(Max(d1,d2),r1+r2+e[ded[i]].wi));
   		
   		for(reg int i = 1 ; i <= n; ++i) {f[i][0] = mv[i] = f[i][1] = book[i] = 0;}
	}
	
	printf("%d",Ans);
	
	return 0;
}
