# include <cstdio>
# include <cstring>
# include <queue> 
# define N 50
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

char s[N + 42];
int dp[N + 42][N + 42],n;

int main()
{
	scanf("%s",s+1);
	
	n = strlen(s+1);
	
	for(reg int len = 1; len <= n ; ++len)
		for(reg int l = 1; l + len - 1 <= n ; ++l)
			{
				int r = l + len - 1;
				
				dp[l][r] = 0x7f7f7f7f;
				
				if(l == r) dp[l][r] = 1;
				else if(s[l] == s[r]) dp[l][r] = Min(dp[l+1][r],dp[l][r-1]);
				else
				{
					for(reg int k = l + 1; k <= r; ++k)
						dp[l][r] = Min(dp[l][r],dp[l][k-1]+dp[k][r]);
				}
			} 
	
	printf("%d\n",dp[1][n]);
	
	return 0;
}
