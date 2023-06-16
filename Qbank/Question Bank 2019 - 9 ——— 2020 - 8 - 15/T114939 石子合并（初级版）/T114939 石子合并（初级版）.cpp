# include <cstdio>
# include <algorithm>
# include <cmath>
# define N 100
# define REG register
# define inf 0x6f6f6f6f6f6f6f
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
long long dp[N + 42][N + 42],n,sum[N + 42];

void show()
{
	for(REG int i = 1; i <= n; ++i){
		for(REG int j = 1; j <= n; ++j)
			if(dp[i][j] != inf) printf("%5lld",dp[i][j]);
			else printf("  inf");
		printf("\n");
	}
	printf("\n");
}

int main()
{
	n = r();
	
	for(REG int i = 1; i <= n; ++i) {sum[i] = r();sum[i] += sum[i - 1];}
	
	for(REG int i = 1; i <= n; ++i)
		for(REG int j = 1; j <= n; ++j)
			dp[i][j] = inf;
	
	for(REG int i = 1; i <= n;++i) dp[i][i] = 0; 
	
	for(int len = 2; len <= n; ++len){
		for(int L = 1,R; L + len - 1 <= n; ++L){
			R = L + len - 1;
			
			for(int k = L; k < R; ++k)
				dp[L][R] = min(dp[L][k] + dp[k + 1][R],dp[L][R]);
			
			dp[L][R] += sum[R] - sum[L - 1];
		}
			
		//show();
	}
		
	
	printf("%lld\n",dp[1][n]);
	return 0;
}
