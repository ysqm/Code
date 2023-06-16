# include <cstdio>
# include <algorithm>
# define N 500000
# define reg register

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

struct Node
{
	int u,v;
} node[(N << 1) + 42],DEL[N + 42];

inline bool comp(const Node& a,const Node& b){return a.v > b.v;}

struct edge
{
	int next,to;
} e[(N << 1) + 42];

bool vis[N + 42],ck,fk;
int head[N + 42],f[N + 42],edge_tot,n,xu,xy,m,ans[N + 42],cnt,root = 1,tmp,K[N + 42];

inline void add_edge(const int& u,const int& v)
{
	e[++edge_tot] = (edge){head[u],v};
	
	head[u] = edge_tot;
}

void dfs(const int& u,const int& father)
{
	ans[++cnt] = u;
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father) dfs(e[i].to,u);
}

void DFS(const int& u,const int& father)
{
	//if(ans[cnt] > K[cnt]) fk = 1;
	//if(K[cnt] > ans[cnt] && ans[cnt] != 0 && fk) ck = 1;
	//if(ck) return;
	
	vis[u] = 1;
	
	K[++cnt] = u;
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(!vis[e[i].to] && e[i].to != father)
		{
			if((xu == u && xy == e[i].to) || (xu == e[i].to && xy == u)) continue;
			
			DFS(e[i].to,u);
		} 	
}

inline bool check()
{
	for(reg int i = 1; i <= n; ++i)
		if(ans[i] == K[i]) continue;
		else if(K[i] > ans[i]) return false;
		else return true;
}

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= m ; ++i) DEL[i].u = node[i].u = node[i+m].v = Read(),DEL[i].v = node[i].v = node[i+m].u = Read();
	
	std::sort(node+1,node+(m=m<<1)+1,comp);
	
	for(reg int i = 1; i <= m ; ++i) add_edge(node[i].u,node[i].v);
	
	if((m>>1) == n-1)
	{
		dfs(root,root);
		
		for(reg int i = 1; i <= cnt; ++i) printf("%d ",ans[i]);
	}
	
	else 
	{	
		for(reg int i = 1; i <= m ; ++i)
		{
			xu = DEL[i].u;xy = DEL[i].v;
			
			//z这里还可以加一个两点都必须在环上 
			
			cnt = 0;//ck = 0;fk = 1;
			
			for(reg int i = 1; i <= n ; ++i) vis[i] = K[i] = 0;
			
			DFS(root,root);
			
			if(cnt < n) continue;
			
			if(ans[1] == 0) for(reg int i = 1; i <= n ; ++i) ans[i] = K[i];
			
			else if(check()) for(reg int i = 1; i <= n ; ++i) ans[i] = K[i];
		}
		
		for(reg int i = 1; i <= cnt; ++i) printf("%d ",ans[i]);
	}
	
	return 0;
}
