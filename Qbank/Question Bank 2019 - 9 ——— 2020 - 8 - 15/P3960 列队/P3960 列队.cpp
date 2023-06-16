# include <cstdio>
# include <algorithm>
# define N 100000
# define LL long long
# define reg register
# define int long long

inline void in(LL& x)
{
	x = 0; char ch = getchar();//int f = 1;
	
	while(ch < '0' || ch > '9')/*{if(ch == '-') f = -1;*/ch = getchar();//}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	//x *= f;
}

/*inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}*/

inline LL Read()
{
	LL x = 0; char ch = getchar();//int f = 1;
	
	while(ch < '0' || ch > '9')/*{if(ch == '-') f = -1;*/ch = getchar();//}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;//x *= f;
}

struct edge
{
	LL next,to,wi;
} e[(N << 1) + 42];

inline LL Max(const LL& a,const LL b){return a > b ? a : b;}
inline LL Min(const LL& a,const LL b){return a < b ? a : b;}

LL head[N + 42],n,tote,Size[N + 42],Max_Son[N + 42],Point[N + 42],ans,dis[N + 42],dp[N + 42],cow;

inline void add_edge(const LL wi,const LL v,const LL u)
{
	e[++tote] = (edge){head[u],v,wi};
	
	head[u] = tote;
	
	e[++tote] = (edge){head[v],u,wi};
	
	head[v] = tote;
}

inline void dfs(const LL u,const LL father)
{
	Size[u] = Point[u];
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father){
			
			dfs(e[i].to,u);
			
			Size[u] += Size[e[i].to];
			
			dis[u] += dis[e[i].to] + Size[e[i].to] * e[i].wi;
		}
}

inline void DP(const LL u,const LL father)
{
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != father){
			
			dp[e[i].to] = dp[u] - Size[e[i].to] * e[i].wi + (cow - Size[e[i].to]) * e[i].wi;
			
			ans = Min(ans,dp[e[i].to]);
			
			DP(e[i].to,u);
			
		}
}

signed main()
{
	in(n);
	
	for(reg int i = 1; i <= n ; ++i) in(Point[i]);
	
	for(reg int i = 1; i <= n ; ++i) cow += Point[i];
	
	for(reg int i = 1; i < n ; ++i) add_edge(Read(),Read(),Read());
	
	dfs(1,1);
	
	ans = dp[1] = dis[1];
	
	DP(1,1);
	
	printf("%lld\n",ans);
	
	return 0;
}
