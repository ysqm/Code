# include <cstdio>
# include <cstring>
# define N 1000000
# define reg register
# define LL long long

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

template<class T>
inline T Max(const T a,const T b){return a > b ? a : b;}

struct edge
{
	int next,to;
} e[(N << 1) + 42];

int head[N + 42],n,tot_edge = 1,cnt,DE,p[N + 42];
LL ans,f[N + 42][2];
bool vis[N + 42];

inline void add_edge(const int u,const int v)
{
	e[++tot_edge] = (edge){head[u],v};
	
	head[u] = tot_edge;
	
	e[++tot_edge] = (edge){head[v],u};
	
	head[v] = tot_edge;
}

inline void dfs_circle(const int u,const int father)
{
	vis[u] = 1;
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father)
		{
			if(vis[e[i].to]) DE = i;
			
			else dfs_circle(e[i].to,u);
		}
}

void dfs(int u,int father)
{
	f[u][1] = p[u];
	f[u][0] = 0;
	
    for(reg int i = head[u]; i ; i = e[i].next)
    	if(e[i].to != father && i != DE && (i^1) != DE)
		{
			dfs(e[i].to,u);
			
        	f[u][1] += f[e[i].to][0];
        	f[u][0] += Max(f[e[i].to][1],f[e[i].to][0]);
		}
}

/*
5
1 2
2 3
3 4
4 5
5 2
2->3->4->5->2
*/

inline void printd()
{
	for(reg int i = 1; i <= n ; ++i) printf("%-5d",i);
	puts("");
	for(reg int i = 1; i <= n ; ++i) printf("%-5d",f[i][0]);
	puts("");
	for(reg int i = 1; i <= n ; ++i) printf("%-5d",f[i][1]);
	puts("");
}

int main()
{
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i){p[i] = Read();add_edge(i,Read());}
	
	for(reg int i = 1; i <= n ; ++i)
		if(!vis[i])
		{
			dfs_circle(i,0);
			
        	dfs(e[DE].to,0);
        	//printd();
        	LL temp = f[e[DE].to][0];
        	
        	dfs(e[DE^1].to,0);
        	//printd();
        	ans += Max(temp,f[e[DE^1].to][0]);
		}
	
	printf("%lld",ans);
	
	return 0;
}
