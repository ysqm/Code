# include <cstdio>
# include <queue>
# include <cstring>
# define reg //register 
# define N 100
typedef long long LL;
typedef unsigned long long ULL;

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return f == -1 ? -x : x;
}

char s[102];
int n,dp[N+5][N+5],m[N+5];

inline bool check(const char* ch,const int n,const int len)
{
	for(reg int i = len; i < n ; ++i)
		if(ch[i] != ch[i%len]) return 0;
		
	return 1;
}

inline int Min(const int a,const int b){return a < b ? a : b;}

int main()
{
	scanf("%s",s+1);
	
	n = strlen(s+1);
	
	for(reg int i = 1; i <= 9; ++i) m[i] = 1;
	for(reg int i = 10; i <= 99; ++i) m[i] = 2;
	m[100] = 3;
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = i; j <= n ; ++j)
			dp[i][j] = j-i+1;
			
	for(reg int i = 5; i <= n ; ++i)
		for(reg int l=1,r=i; r <= n ; ++l,++r)
		{
			for(reg int k = l; k < r ; ++k)
				dp[l][r] = Min(dp[l][r],dp[l][k] + dp[k+1][r]);
				
			for(reg int k = 1; k < i ; ++k)
				if(i%k == 0 && check(s+l,i,k))
					dp[l][r] = Min(dp[l][r],dp[l][l+k-1] + m[i/k] + 2);
			
		}
		
	/*for(reg int i = 1; i <= n ; ++i)
	{
		for(reg int j = 1; j <= n ; ++j) printf("%d ",dp[i][j]);
		puts(" ");
	}*/
		
	printf("%d",dp[1][n]);
	
	return 0;
}
//aaaaaa
//aaaaaaaaaa
//acdcdcdacdcdcd
