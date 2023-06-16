# include <algorithm>
# include <cstring>
# include <cstdio>
# include <cmath>
# define reg register
using namespace std;

int n,m,dp[42][42];

void Pretreatment()
{
	for(reg int i = 0; i <= 9 ; ++i) dp[1][i] = 1;
	
	for(reg int i = 2; i <= 10 ; ++i)
	{
		for(reg int j = 0; j <= 9 ; ++j)
			for(reg int k = 0; k <= 9 ; ++k)
			{
				if(abs(j-k) >= 2) dp[i][j] += dp[i-1][k];
			}
	}
}

int Query(int x)
{
	int len=0,ans=0,s[42];
	
	while(x)
	{
		s[++len] = x % 10;
		x /= 10;
	}
	
	for(reg int i = len-1; i ; --i) 
		for(reg int j = 1; j <= 9 ; ++j)
			ans += dp[i][j];
			
	for(reg int i = 1; i < s[len] ; ++i) ans += dp[len][i];
		
	for(reg int i = len-1; i >= 1 ; --i)
	{
		for(reg int j = 0; j < s[i] ; ++j) if(abs(j-s[i+1]) >= 2) ans += dp[i][j];
		
		if(abs(s[i]-s[i+1]) < 2) break;
	}
		
		
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);

	Pretreatment();

	printf("%d",Query(m+1)-Query(n));
	
	return 0;
} 

