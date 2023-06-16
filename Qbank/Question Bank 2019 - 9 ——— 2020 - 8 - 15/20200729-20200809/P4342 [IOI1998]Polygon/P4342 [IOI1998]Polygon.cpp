# include <cstdio>
# include <cstring> 
# include <algorithm>
# define reg register
using namespace std;

const int N = 100;

char s[42];
int opt[N + 42],dp[N + 42][N + 42],f[N + 42][N + 42],a[N + 42],n,ans,debug,m;

inline void Show_Me()
{
	for(reg int i = 1 ; i <= m ; ++i)
	{
		for(reg int j = 1; j <= (n<<1) ; ++j) printf(dp[i][j] <= -0x3f3f ? "INF   " : "%-5d ",dp[i][j]);
		
		printf("\n");
	}
		
}

inline void DP(const int L,const int R)
{
	for(reg int k = L ; k < R ; ++k)
	{
		if(opt[k+1] == 2)
		{
			dp[L][R] = max(dp[L][R],max(max(dp[L][k]*dp[k+1][R],f[L][k]*f[k+1][R]),max(dp[L][k]*f[k+1][R],f[L][k]*dp[k+1][R])));
			f[L][R] = min(f[L][R],min(min(dp[L][k]*dp[k+1][R],f[L][k]*f[k+1][R]),min(dp[L][k]*f[k+1][R],f[L][k]*dp[k+1][R])));
		}
		else
		{
			dp[L][R] = max(dp[L][R],dp[L][k]+dp[k+1][R]);
			f[L][R] = min(f[L][R],f[L][k]+f[k+1][R]); 
		}
	}
	
	//printf("case %d\n",++debug);
	
	//Show_Me();
}

int main()
{
	scanf("%d",&n);
	
	for(reg int i = 1; i <= n ; ++i)
	{
		scanf("%s %d",s+1,a + i);
		
		a[n+i] = a[i];
		
		if(s[1] == 't') opt[n+i] = opt[i] = 1;
		else opt[n+i] = opt[i] = 2;
	}//1¼Ó2³Ë
	
	m = (n<<1)-1;
	
	memset(dp,-0x3f,sizeof(dp));
	memset(f,0x3f,sizeof(f));
	
	for(reg int i = 1; i <= m ; ++i) dp[i][i] = f[i][i] = a[i]; 
	
	for(reg int i = 2 ; i <= n ; ++i)
		for(reg int l = 1,r = i; r <= m ; ++r,++l)
			DP(l,r);
	
	for(reg int i = 1; i <= n ; ++i) ans = max(ans,dp[i][i+n-1]);
	
	printf("%d\n",ans);
	
	for(reg int i = 1; i <= n ; ++i) if(dp[i][i+n-1] == ans) printf("%d ",i);
	
	return 0;
} 
