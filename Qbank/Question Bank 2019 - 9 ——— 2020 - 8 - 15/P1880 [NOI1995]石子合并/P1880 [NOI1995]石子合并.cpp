# include <cstdio>
# include <algorithm>
# include <cmath>
# define N 100
# define M 500000
# define R register
# define inf 0x6f6f6f6f6f6f
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

long long dp[N * 2 + 42][N * 2 + 42],Dp[N * 2 + 42][N * 2 + 42],n,sum[N * 2 + 42],ans1,ans2 = inf,nn;

void show()
{
	for(int i = 1; i <= nn; ++i){
		for(int j = 1; j <= nn; ++j)
			if(Dp[i][j] < inf) printf("%5lld",Dp[i][j]);
			else printf("  inf");
		printf("\n");
	}
	printf("\n");
}

int main()
{
	freopen("P1880_3.in","r",stdin);
	
	n = r();nn = n * 2;
	
	for(R int i = 1; i <= n; ++i)  
		sum[i] = sum[i + n] = r();
	
	for(R int i = 2; i <= nn; ++i) sum[i] += sum[i - 1];
	
	for(R int i = 1;i <= nn; ++i) 
		for(R int j = 1; j <= nn; ++j)
			Dp[i][j] = inf;
	
	for(R int i = 1; i <= nn ; ++i) Dp[i][i] = 0;
	
	int i,k,j,t; 
	
	for(t = 2; t <= n; ++t){
		for(i = 1; i + t < nn; ++i){//×ó¶Ëµã 
			j = i + t - 1;//ÓÒ¶Ëµã 
			for(k = i; k < j; ++k){
				dp[i][j] = max(dp[i][j],dp[i][k] + dp[k + 1][j]);
				Dp[i][j] = min(Dp[i][j],Dp[i][k] + Dp[k + 1][j]);
			}
			
			dp[i][j] += sum[j] - sum[i - 1];
			Dp[i][j] += sum[j] - sum[i - 1];
		}	
			
		//show();
	}
		
	
	for(i = 1; i <= n; ++i) ans1 = max(ans1,dp[i][i + n - 1]),ans2 = min(ans2,Dp[i][i + n - 1]);
	
	printf("%lld\n%lld",ans2,ans1);
	return 0;
}
