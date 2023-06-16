# include <cstdio>
# define N 100
# define reg register

int dp[N + 42][N + 42],a[N + 42],n,ans;

inline int ABS(const int a){return a < 0 ? -a : a;}
inline int Max(const int a,const int b){return a > b ? a : b;}

int main()
{
	scanf("%d",&n);
	
	for(reg int i = 1; i <= n ; ++i) scanf("%d",&dp[i][1]),a[i] = dp[i][1];
	
	for(reg int i = 2; i <= n ; ++i)
		for(reg int L = 1; L + i - 1 <= n ; ++L)
		{
			int R = L + i - 1;
			
			dp[L][i] = i * ABS(a[L] - a[R]);
			
			for(reg int k = 1; k < i ; ++k)
				dp[L][i] = Max(dp[L][i],dp[L][k] + dp[L+k][i-k]);
		}
	
	//for(reg int i = 1; i <= n ; ++i) ans > dp[i][n] ? ans : ans = dp[i][n];
	
	printf("%d",dp[1][n]);
		
	return 0;
}
