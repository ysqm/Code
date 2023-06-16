# include <algorithm>
# include <cstring>
# include <cstdio>
# include <cmath>
# define reg register
using namespace std;

const int Max_Status = 1<<18,N = 18;

int n,W,a[N + 42],Status,dp[Max_Status+42],g[Max_Status + 42];

int main()
{
	scanf("%d%d",&n,&W);
	
	for(reg int i = 1; i <= n ; ++i) scanf("%d",&a[i]);
	
	Status = 1<<n;
	
	
	memset(dp,0x3f,sizeof(dp));
	
	dp[0] = 0;
	
	/*for(reg int i = 0; i < Status ; ++i)
		if(w[i] < 0x3f3f3f3f)
			for(reg int j = 1; j <= n ; ++j)
				w[i|(1<<(j-1))] = min(w[i|(1<<(j-1))],w[i] + a[j]);*/
	
	for(reg int i = 0; i < Status ; ++i)
		for(reg int j = 1; j <= n ; ++j)
			if(~(i & (1 << (j-1))))
			{
				if(g[i] >= a[j] && dp[i|(1<<(j-1))] >= dp[i])
				{
					dp[i|(1<<(j-1))] = dp[i];
					g[i|(1<<(j-1))] = max(g[i|(1<<(j-1))],g[i]-a[j]);
				}
				else if(dp[i|(1<<(j-1))] >= (dp[i]+1))
				{
					dp[i|(1<<(j-1))] = dp[i]+1;
					g[i|(1<<(j-1))] = max(g[i|(1<<(j-1))],W-a[j]);
				}
			}
	
	//for(reg int i = 0; i < Status ; ++i)
	
	printf("%d",dp[Status-1]);
	
	return 0;
} 
