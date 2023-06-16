# include <cstdio>
# include <algorithm>
# include <cmath>
# define N 100
# define M 500000
# define R register
using namespace std;

inline long long r()
{
	long long x = 0;
	
	char c = getchar();
	
	while(c > '9' || c < '0'){
		c = getchar();
	}
	
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		
		c = getchar();
	}
	
	return x;
}

long long dp[N * 2 + 42][N * 2 + 42],n,head[N * 2 + 42],tail[N * 2 + 42],ans;
int main()
{
	n = r();
	
	for(R int i = 1; i <= n; i++) head[i] = head[i + n] = r();
	
	for(R int i = 1; i <= n * 2 - 1; i++) tail[i] = head[i + 1];
	
	tail[2*n]=head[1];
	
	int i,k,j,t; 
	
	for(t = 1; t < n; t++)
		for(i = 1; i <= n * 2 - t; i++){
			j = i + t;
			for(k = i; k < j; k++)
				dp[i][j] = max(dp[i][j],dp[i][k] + dp[k + 1][j] + head[i] * tail[k] * tail[j]);
		}
	
	for(i = 1; i <= n; i++) ans = max(ans,dp[i][i + n - 1]);
	
	printf("%lld",ans);
	return 0;
}
