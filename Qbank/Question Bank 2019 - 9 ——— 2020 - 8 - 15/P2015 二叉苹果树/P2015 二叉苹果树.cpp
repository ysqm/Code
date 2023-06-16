# include <cstdio>
# include <algorithm>
# define REG register
# define N 100
using namespace std;

typedef long long LL;

template <typename T>
inline void in(T& x)
{
	x = 0;char c = getchar();int f = 1;
	
	while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	x *= f;
	
	return ;
} 

//template <typename T>
inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	return x;
}

struct edge
{
	int from,to,wi;
} e[(N << 1) + 42];

int head[N + 42],cnt_e;

//bool ins[N + 42];

void add(int wi,int u,int v)
{
	e[++cnt_e].from = head[v];
	
	e[cnt_e].to = u;
	
	head[v] = cnt_e;
	
	e[cnt_e].wi = wi;
	
	e[++cnt_e].from = head[u];
	
	e[cnt_e].to = v;
	
	head[u] = cnt_e;
	
	e[cnt_e].wi = wi;
}

int n,Q;

int f[N + 42][N + 42],ans,size[N + 42];

void dfs(int u,int father)
{
	size[u] = 1;
	for(REG int i = head[u]; i ; i = e[i].from)
		if(e[i].to != father){
			dfs(e[i].to,u);size[u] += size[e[i].to];
			for(REG int j = min(Q,size[u]); j ; --j)
				for(REG int k = min(size[e[i].to],j - 1); k >= 0 ; --k)
					f[u][j]=max(f[u][j],f[u][j - k - 1] + f[e[i].to][k] + e[i].wi);
		}
}

int main()
{
	in(n);in(Q);
	
	//for(REG int i = 1; i <= n; ++i) in(dp[i]);
	
	for(REG int i = 1; i < n; ++i)add(Read(),Read(),Read());
	
	dfs(1,-1);
	
	printf("%d",f[1][Q]);
	
	return 0;
}
