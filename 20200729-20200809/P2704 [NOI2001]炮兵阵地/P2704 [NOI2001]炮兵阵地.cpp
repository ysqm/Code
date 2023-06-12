# include <algorithm>
# include <cstring>
# include <cstdio>
# include <cmath>
# define reg register
using namespace std;

const int Max_Status = 200,N = 100,M = 10;

char s[42];
int n,m,Status,dp[Max_Status][Max_Status+42][Max_Status+42],g[Max_Status + 42],cnt[Max_Status+42],top,h[N+42];

inline void Show_Me(const int k)
{
	printf("csae %d:\n",k);
	
	for(reg int i = 1; i <= top ; ++i)
	{
		for(reg int j = 1; j <= top ; ++j) printf("%-3d ",dp[k][i][j]);
		
		printf("\n");
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	
	Status = (1<<m)-1;
	
	for(reg int i = 0; i <= Status; ++i)
	{
		bool flag = 0;
		int sum = 0;
		
		for(reg int k = 1; k <= m ; ++k)
			if(i>>(k-1) & 1)
			{
				++sum;
				flag |= (i>>k & 1) || (i>>(k+1) & 1);
			}
			
		if(!flag) {cnt[++top] = sum;g[top] = i;}
	}
	
	for(reg int i = 1; i <= n ; ++i)
	{
		scanf("%s",s+1);
		
		for(reg int j = 1; j <= m ; ++j) if(s[j] == 'H') h[i] |= (1<<(j-1));
	}
	
	for(reg int i = 1; i <= top ; ++i)
		for(reg int j = 1; j <= top ; ++j)
			if(!((g[i]&h[1]) || (g[j]&h[2]) || (g[i]&g[j]))) 
				dp[2][i][j] = cnt[i] + cnt[j];
		
	for(reg int i = 3; i <= n ; ++i)
		for(reg int j = 1; j <= top ; ++j)
			if(!(g[j]&h[i]))
				for(reg int k = 1; k <= top ; ++k)
					for(reg int l = 1; l <= top ; ++l)
						if(!((g[l]&g[j]) || (g[k]&g[j])))
							dp[i][l][j] = max(dp[i][l][j],dp[i-1][k][l] + cnt[j]);
		
	//Show_Me(n-1);
							
	int ans = 0;
	
	for(reg int i = 1; i <= top ; ++i)
		for(reg int j = 1; j <= top ; ++j)
			ans = max(ans,dp[n][i][j]);
	
	printf("%d\n",ans);	
	
	return 0;
} 

