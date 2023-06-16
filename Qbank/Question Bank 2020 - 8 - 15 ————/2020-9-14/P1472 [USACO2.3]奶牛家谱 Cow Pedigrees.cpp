# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>

int n,k;
int dp[205][205];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n ; ++i) dp[1][i] = 1;

    for(int i = 1; i <= n ; ++i)
        for(int j = 3; j <= n ; j += 2)
            for(int k = 1; k <= j-2 ; k += 2)
                dp[j][i] = (dp[j][i]+dp[j-k-1][i-1]*dp[k][i-1])%9901;
    printf("%d",(dp[n][k]-dp[n][k-1]+9901)%9901);
    return 0;
}
