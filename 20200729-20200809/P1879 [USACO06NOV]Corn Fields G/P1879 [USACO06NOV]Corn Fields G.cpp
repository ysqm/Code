# include <algorithm>
# include <cstring>
# include <cstdio>
# include <cmath>
# define reg register
using namespace std;

const int Max_Status = 600,N = 12,M = 12;

char s[42];
int n,m,d,g[Max_Status + 42],Status,top,dp[N + 42][Max_Status + 42];

inline void Get_Line()
{
	d = 0;
	
	for(reg int i = 0,ch; i < m ; ++i)
	{
		scanf("%d",&ch);
		
		if(ch == 0) d |= (1<<i);
	}
}

inline int Mod(const int x){return x < 100000000 ? x : x - 100000000;}

inline void Show_Me(const int x)
{
	printf("csae %d:\n",x);
	
	for(reg int i = 1; i <= top ; ++i) printf("%-6d",g[i]);
	
	printf("\n");
	
	for(reg int i = 1; i <= top ; ++i) printf("%-6d",dp[x][i]);
	
	printf("\n");
}

int main()
{
	//freopen("1.txt","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	Status = (1 << m) - 1;
	
	for(reg int i = 0; i <= Status ; ++i)
	{
		bool flag = 0;
		int sum = 0;
		
		for(reg int k = 0; k < m ; ++k)
			if((i>>k) & 1)
			{
				flag |= i>>(k-1)&1;
				++sum; 
			}
			
		if(!flag) g[++top] = i;
	}
	
	Get_Line();
	
	for(reg int i = 1; i <= top ; ++i)
		if(!(g[i]&d)) ++dp[1][i];
	
	//Show_Me(1);
	
	for(reg int i = 2; i <= n ; ++i)
	{
		Get_Line();
		
		for(reg int j = 1; j <= top ; ++j)
			if(!(g[j]&d))
				for(reg int k = 1; k <= top ; ++k)
					if(!(g[j]&g[k]))
						dp[i][j] = Mod(dp[i][j]+dp[i-1][k]);
		//Show_Me(i);
	}
	
	int ans = 0;
	
	for(reg int i = 1; i <= top ; ++i) ans = Mod(ans + dp[n][i]); 
	
	printf("%d",ans);
	
	return 0;
} 

