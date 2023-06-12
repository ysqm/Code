# include <cstdio>
# include <cstring>
# include <queue> 
# define N 2000
# define mod 19650827 
# define reg register
# define INF 0x3f3f3f3f

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

inline int Min(const int a,const int b){return a < b ? a : b;}

int dp[N + 42][N + 42][2],n,a[N + 42];

int main()
{
	scanf("%d",&n);
	
	for(reg int i = 1; i <= n ; ++i) scanf("%d",&a[i]);
	
	for(reg int i = 1; i <= n ; ++i) dp[i][i][0] = 1;
	
	for(reg int k = 1; k <= n ; ++k)
		for(reg int i = 1; i + k - 1 <= n ; ++i)
		{
			int j = i + k;
			
			dp[i][j][0] = (dp[i][j][0]+(a[i] < a[i+1] ? dp[i+1][j][0] : 0)+(a[i] < a[j] ? dp[i+1][j][1] : 0))%mod;
			dp[i][j][1] = (dp[i][j][1]+(a[j] > a[j-1] ? dp[i][j-1][1] : 0)+(a[i] < a[j] ? dp[i][j-1][0] : 0))%mod;
		}
		
	printf("%d",(dp[1][n][0]+dp[1][n][1])%mod);
	
	return 0;
}
