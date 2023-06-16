# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 36
# define max std::max

int n,m;
long long dp[N+5][N+5];

int main()
{
    freopen("ysqm.in","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i = 0; i <= n ; ++i) dp[0][i] = 1;
    for(int i = 1; i <= n ; ++i)
        for(int j = 1; j <= n ; ++j)
            for(int k = 0; k <= j; ++k)
                dp[j][i] += dp[k][i-1]*dp[j-k-1][i-1];
    printf("%lld",dp[n][n]-dp[n][m-1]);
    return 0;
}