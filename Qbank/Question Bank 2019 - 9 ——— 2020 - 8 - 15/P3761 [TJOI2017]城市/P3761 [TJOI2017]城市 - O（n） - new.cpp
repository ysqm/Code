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
int A[N + 42],B[N + 42];
int W[N + 42],WW[N + 42];
int mv[N + 42],mvv[N + 42];
int f[N + 42][2],dp[N + 42][2];
int dnt[N + 42],cnt;
int Ans,S,T,diameter,d1,temp;
bool book[N + 42];

void dfs1(const int u,const int fa)
{	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa)
		{
			dfs1(e[i].to,u);
			
			int v = f[e[i].to][0] + e[i].wi;
			
   			if(v > f[u][0]){f[u][1] = f[u][0];f[u][0] = v;mv[u] = e[i].to;W[u] = e[i].wi;}
   			
   			else if(v > f[u][1]){f[u][1] = v;}
   			
   			A[u] = Max(A[u],A[e[i].to]);
		}
		A[u] = Max(A[u],f[u][1] + f[u][0]);
}

void dfs(const int u,const int fa)
{	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa)
		{
			dfs(e[i].to,u);
			
			int v = dp[e[i].to][0] + e[i].wi;
			
   			if(v > dp[u][0]){dp[u][1] = dp[u][0];dp[u][0] = v;mvv[u] = e[i].to;WW[u] = e[i].wi;}
   			
   			else if(v > dp[u][1]){dp[u][1] = v;}
   			
   			B[u] = Max(B[u],B[e[i].to]);
		}
		B[u] = Max(B[u],dp[u][1] + dp[u][0]);
}


int main()
{
	n = Read();
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read(),Read());

	dfs1(1,1);
	
	for(reg int i = 1; i <= n; ++i) if(f[i][0] + f[i][1] == A[1]) S = i;
	
	while(mv[S]) S = mv[S];
	
	memset(A,0,sizeof(A));
	memset(mv,0,sizeof(mv));
	memset(f,0,sizeof(f));
	
	dfs1(S,T = S);
	
	dnt[++cnt] = T;
	
	while(mv[T]) dnt[++cnt] = (T = mv[T]);
	
	dfs(T,T);
	
	for(reg int i = S; i ; i = mv[i])
	{
		int ans = diameter;
		int rt=0,lt=0,Half = ans>>1,cur;
		
		if(diameter > temp)
		{
			cur = i;
		
			while(dp[cur][0] - WW[cur] > Half && cur) cur = mvv[cur];
		
			rt = dp[cur][0];

			temp = diameter;
		}
		
		cur = mv[i];
		
		Half = (f[mv[i]][0] + f[mv[i]][1])>>1;
		
		while(f[cur][0] - W[cur]> Half && cur) cur = mv[cur];
		
		lt = f[cur][0];
		
		ans = Max(ans,f[mv[i]][0] + f[mv[i]][1]);
		
		ans = Max(ans,W[i] + lt + rt);
		
		Ans = Min(ans,Ans);
	}
	
	printf("%d",Ans);
	
	return 0;
}
