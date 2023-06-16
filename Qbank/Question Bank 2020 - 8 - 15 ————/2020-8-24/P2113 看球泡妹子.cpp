# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 100
# define M 4000
# define reg //register

inline bool comp(const int a,const int b){return a > b;}

int n,m,K,c,dp[M+5][N+5],a[N+5],b[N+5],d[N+5],e[N+5],v[N+5],w[N+5],s,ans;

inline void chkmax(int& x,const int y){x = (x < y ? y : x);}
inline int Min(const int x,const int y){return x < y ? x : y;}
inline int Max(const int x,const int y){return x > y ? x : y;}

signed main()
{
    scanf("%d%d%d%d",&n,&m,&K,&c);

    for(reg int i = 1; i <= n ; ++i) scanf("%d",a+i);

    for(reg int i = 1; i <= n ; ++i) scanf("%d",b+i);

    for(reg int i = 1; i <= m ; ++i) scanf("%d%d",d+i,e+i);
    
    for(reg int i = 1; i <= m ; ++i) w[i] = a[d[i]]*a[e[i]];
    
    for(reg int i = 1; i <= m ; ++i) v[i] = b[d[i]]+b[e[i]];

    memset(dp,-0x3f,sizeof(dp));
    memset(dp[0],0,sizeof(dp[0]));

	for(reg int i = 1; i <= m ; ++i) s += v[i];

    for(reg int i = 1; i <= m ; ++i)
    	for(reg int j = s; j >= v[i] ; --j)
    		for(reg int k = 1; k <= K ; ++k)
    			dp[j][k] = Max(dp[j][k],dp[j-v[i]][k-1]+w[i]);

	for(reg int i = c; i <= s ; ++i) 
		ans = Max(ans,dp[i][K]);

    printf("%d",ans);

    return 0;
}
