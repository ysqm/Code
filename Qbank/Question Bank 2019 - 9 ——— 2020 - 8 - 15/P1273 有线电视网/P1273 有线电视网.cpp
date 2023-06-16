# include <cstdio>
# include <cstring>
# define N 3000
# define reg register
using namespace std;

template <typename T>
inline T in(T& x)
{
	x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
} 

template <typename T>
inline T min(const T A,const T B){return A < B ? A : B;} 

template <typename T>
inline T max(const T A,const T B){return A > B ? A : B;}

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
	
	return x;
}

struct Edge
{
	int from,to,wi;
} e[N + 42];

int dp[N + 42][N + 42],edge_tot,M,head[N + 42],n,ans = 1e5,root,val[N + 42],t[N + 42];

inline void add_edge(const int wi,const int v,const int u)
{
	e[++edge_tot].from = head[u];
	
	e[edge_tot].to = v;
	
	e[edge_tot].wi = wi;
	
	head[u] = edge_tot;
};

inline int dfs(const int u)
{
	if (u > n - M){
        dp[u][1] = val[u];
        return 1;
    }
    
    int sum = 0,v;
    
    for(reg int p = head[u] ;  p ; p = e[p].from){
    	int tp = dfs(v = e[p].to);
    	for(reg int i = 0 ; i <= sum ;  ++i) t[i] = dp[u][i];
    	for (int j = 0 ; j <= sum ; ++j)
            for (int k = 0 ; k <= tp ; ++k)
                dp[u][j + k] = max(dp[u][j + k],t[j] + dp[v][k] - e[p].wi);
        sum += tp;
	}
	return sum;
}

signed main()
{
	in(n);in(M);
	
	memset(dp,~0x3f,sizeof(dp));
	
	for(reg int i = 1,k; i <= n - M; ++i){in(k);for(reg int j = 1; j <= k ; ++j) add_edge(Read(),Read(),i);}
		
		
	for(reg int i = n - M + 1; i <= n; ++i) val[i] = Read(); 
	
	for(reg int i = 1; i <= n; ++i) dp[i][0] = 0;
	
	dfs(1);
	
	for(reg int i = M; i ; i--)
		if(dp[1][i] >= 0){
			printf("%d",i);
			return 0;
		}
}
