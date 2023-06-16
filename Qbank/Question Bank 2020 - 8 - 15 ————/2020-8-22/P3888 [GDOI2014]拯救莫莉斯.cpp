# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg //register

inline int Min(const int x,const int y){return x < y ? x : y;}

const int N = 55;
const int Max_Status = (1<<7)-1;
int G[N][15],dp[N][Max_Status+5][Max_Status+5],g[N][Max_Status+5][Max_Status+5],sum[N][Max_Status+5],s[Max_Status+5];
int n,m,S;

int main()
{
    //freopen("1.in","r",stdin);

    scanf("%d%d",&n,&m);S = (1<<m)-1;

    for(reg int i = 1; i <= n ; ++i)
        for(reg int j = 1; j <= m ; ++j)
            scanf("%d",&G[i][j]);

	++n;

    for(reg int i = 1; i <= n ; ++i)
        for(reg int j = 0; j <= S ; ++j)
            for(reg int k = 0; k <= S ; ++k)
                dp[i][j][k] = 0x3f;

	--n;
	
    for(reg int i = 1; i <= n ; ++i)
        for(reg int j = 0; j <= S ; ++j)
            for(reg int k = 1; k <= m ; ++k) 
                (j&(1<<(k-1))) && (sum[i][j] += G[i][k]);

    for(reg int j = 0; j <= S ; ++j)
        for(reg int i = 1; i <= m ; ++i)
            (j&(1<<(i-1))) && (++s[j]);

    for(reg int i = 0; i <= S ; ++i) dp[1][i][0] = sum[1][i];

    for(reg int i = 0; i <= S ; ++i) g[1][i][0] = s[i];

	++n;

    for(reg int i = 2; i <= n ; ++i)
        for(reg int j = 0; j <= S ; ++j)//前一行建油库的方式
            for(reg int k = 0; k <= S ; ++k)//上上行建油库的方式
                for(reg int p = 0; p <= S ; ++p)//本行选择建油库的方式
                    if(((((j<<1)|(j>>1)|j|k|p)&S) == S) && dp[i-1][j][k]+sum[i][p] <= dp[i][p][j])
                    {
                        if(dp[i-1][j][k]+sum[i][p] < dp[i][p][j])
                        {
                            dp[i][p][j] = dp[i-1][j][k]+sum[i][p];
                            g[i][p][j] = g[i-1][j][k]+s[p];
                        }
                        else g[i][p][j] = Min(g[i][p][j],g[i-1][j][k]+s[p]);
                    }
                        
    int ans = 0x3f3f3f3f,anst;

    for(reg int i = 0; i <= S ; ++i) 
    (dp[n][0][i] <= ans) && (((dp[n][0][i] == ans && (anst = Min(g[n][0][i],anst))) || (((ans = dp[n][0][i]) && (anst = g[n][0][i])))));

    printf("%d %d",anst,ans);

    return 0;
}
