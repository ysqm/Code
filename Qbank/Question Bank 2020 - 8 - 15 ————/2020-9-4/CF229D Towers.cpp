# include <cstdio>
# define reg register
# define N 5000

inline int Min(const int x,const int y){return x < y ? x : y;}
int n,dp[N+5],f[N+5],sum[N+5];

int main()
{
    scanf("%d",&n);

    for(reg int i = 1; i <= n ; ++i) scanf("%d",sum+i);

    for(reg int i = 2; i <= n ; ++i) sum[i] += sum[i-1];

    for(reg int i = 1; i <= n ; ++i) dp[i] = f[i] = 0x7f7f7f7f;

    for(reg int i = 1; i <= n ; ++i)
        for(reg int j = 0; j <= i ; ++j)
            if(sum[i]-sum[j] >= dp[j] && f[j]+i-j-1 <= f[i])
            {
                dp[i] = Min(sum[i]-sum[j],dp[i]);
                f[i] = f[j]+i-j-1;
            }

    printf("%d",f[n]);

    return 0;
}
