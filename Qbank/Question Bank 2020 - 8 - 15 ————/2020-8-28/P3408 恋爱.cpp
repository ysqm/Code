# include <ctime>
# include <queue>
# include <cmath>
# include <queue>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define N 500000
# define LL long long
# define int long long
inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

struct edge
{
    int Next,to;

    edge(const int Next_=0,const int To_=0):Next(Next_),to(To_){}
} e[N+5];

int head[N+5],edge_tot = 1,n,T,c,S,A[N+5];
std::vector<int> heap[N+5];

inline void add_edge(const int u,const int v)
{
    e[++edge_tot] = edge(head[u],v);

    head[u] = edge_tot;

    /*e[++edge_tot] = edge(head[v],u);

    head[v] = edge_tot;*/
}

LL dp[N+5];

inline void dfs(const int u)
{
    for(reg int i = head[u]; i ; i = e[i].Next) 
	{
		dfs(e[i].to);
		heap[u].push_back(dp[e[i].to]);
	}
	
	reg int i = 0,siz = heap[u].size();
    if(siz == 0) {dp[u] = A[u];return;}
    std::sort(heap[u].begin(),heap[u].end());
    while(i*T < A[u]*siz) 
		dp[u] += heap[u][i++];
}

signed main()
{
    n = Read();T = Read();c = Read();

    for(reg int i = 1; i <= n ; ++i) {add_edge(Read(),i);A[i] = Read();}

    for(reg int i = head[0]; i ; i = e[i].Next)
	{
		dfs(e[i].to);
		heap[0].push_back(dp[e[i].to]);
	}
    
    if(heap[0].size() == 0) dp[0] = A[0];
	else
	{
		std::sort(heap[0].begin(),heap[0].end());
    	reg int i = 0,siz = heap[0].size();

    	while(i*T < c*siz) 
			dp[0] += heap[0][i++];
	}

	printf("%lld",dp[S]);

    return 0;
}
