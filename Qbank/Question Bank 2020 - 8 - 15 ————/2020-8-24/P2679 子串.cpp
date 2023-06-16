# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 1000
# define M 200
# define reg register
# define LL long long

const LL modp = 1000000007;
char s1[N+5],s2[M+5];
LL dp[M+5][M+5],sum[M+5][M+5],n,m,K;

inline LL Mode(const LL x){return x < modp ? x : x-modp;}

inline int Min(const int x,const int y){return x < y ? x : y;}

int main()
{
    scanf("%d%d%d%s%s",&n,&m,&K,s1+1,s2+1);

    dp[0][0] = 1;

    for(reg int i = 1; i <= n ; ++i)
        for(reg int j = m; j >= 1 ; --j)
            for(reg int k = K; k >= 1 ; --k)
                dp[j][k] = Mode(dp[j][k] + (sum[j][k] = (s1[i] == s2[j] ? Mode(sum[j-1][k]+dp[j-1][k-1]) : 0)));

    printf("%lld",dp[m][K]);

    return 0;
}