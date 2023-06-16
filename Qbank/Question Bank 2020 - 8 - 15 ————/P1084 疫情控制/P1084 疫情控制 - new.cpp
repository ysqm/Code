# include <algorithm>
# include <cstring>
# include <cstdio>
# include <queue>
# define LL long long
# define reg register
# define N 50000
# define Max_Step 18

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = x*10 + (ch^48);ch = getchar();}
	
	return x;
} 

struct edge
{
	int Next,to,wi;
	
	edge(const int Next_=0,const int To_=0,const int wi_=0):Next(Next_),to(To_),wi(wi_){}
} e[(N<<1) + 5];

int head[N + 5],edge_tot;

inline void add_edge(const int wi,const int v,const int u)
{
	e[++edge_tot] = edge(head[u],v,wi);
	
	head[u] = edge_tot;
	
	e[++edge_tot] = edge(head[v],u,wi);
	
	head[v] = edge_tot;
}

bool vis[N+5];
LL dis[Max_Step + 1][N + 5],Ar[N+5],need[N+5],deep[N+5];
int f[Max_Step + 1][N + 5],cnt,Am[N+5],n,m,tot,idx[N+5];

inline void dfs(const int u)
{
	for(reg int i = 1; i <= Max_Step ; ++i) f[i][u] = f[i-1][f[i-1][u]];
	for(reg int i = 1; i <= Max_Step ; ++i) dis[i][u] = dis[i-1][u] + dis[i-1][f[i-1][u]];

	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != f[0][u])
		{
			deep[e[i].to] = deep[u] + e[i].wi;
			f[0][e[i].to] = u;
			dis[0][e[i].to] = e[i].wi;
			dfs(e[i].to);
		}
}

inline bool comp(const int a,const int b){return deep[a] > deep[b];}

bool dfs_check(const int u)
{
	if(vis[u]) return 1;
	bool pson = 0;

	for(reg int i = head[u]; i ; i = e[i].Next)
		if(e[i].to != f[0][u])
		{
			pson=1;
			if(dfs_check(e[i].to) == 0) return false;
		}

	return pson;
}

struct node
{
	LL sum;
	int idx;

	node(const int sum_=0,const int idx_=0):sum(sum_),idx(idx_){}

	inline bool operator < (const node& a)const {return sum < a.sum;}
} h[N + 5];

bool check(const int T)
{
	cnt = 0;tot = 0; 

	for(reg int j = 1; j <= m ; ++j)
	{
		LL di = T;
		int cur = Am[j];

		for(reg int i = Max_Step; i >= 0 ; --i)
			if(f[i][cur] != 1 && di > dis[i][cur])
			{
				di -= dis[i][cur];
				x = f[i][cur];
			}
		if(f[0][cur] == 1 && di >= dis[0][cur] ) h[++cnt] = node(di-dis[0][cur],cur);
		else vis[x] = 1;
	}

	for(reg int i = head[1]; i ; i = e[i].Next)
		if(dfs_check(e[i].to) == 0) need[++tot] = dis[0][e[i].to];
	
	if(tot > cnt) return false;

	std::sort(Ar+1,Ar+cnt+1);
	std::sort(need+1,need+tot+1);

	for(reg int i = tot; i ; --i)
		if(Ar[cnt] >= need[i]) --cnt;
		else return false;

	return true;
}

int main()
{
	freopen("P1084_5.in","r",stdin);
	
	n = Read();f[0][1] = 1;
	
	for(reg int i = 2; i <= n ; ++i) add_edge(Read(),Read(),Read());
	
	for(reg int i = head[1]; i ; i = e[i].Next) ++cnt;

	if(cnt > (m = Read())) {printf("-1");return 0;}
	
	for(reg int i = 1; i <= m ; ++i) Am[i] = Read();
	
	dfs(1);
	
	std::sort(Am+1,Am+m+1,comp);

	register int l = 0,r = 1e9,mid;

	while(l<r)
	{
		mid = (l+r)>>1;
		if(check(mid)) r = mid;
		else l = mid+1;
	}

	printf("%d",l);

	return 0;
}


