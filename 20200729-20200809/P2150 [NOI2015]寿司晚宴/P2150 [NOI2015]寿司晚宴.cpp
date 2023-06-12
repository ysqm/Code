/*
	Code by : 云岁月书
	Date：2020-8-2 
*/
# include <cstdio>
# include <algorithm>
# define reg register
using namespace std;

typedef long long LL;

const int p[10] = {0,2,3,5,7,11,13,17,19};
const int Max_Status = 1<<8;

struct Point
{
	int d,color;
	
	friend bool operator < (const Point& a,const Point& b){if(a.color != b.color) return a.color < b.color;return a.d < b.d;}
	
} g[542];

int n,Status=Max_Status-1;
LL dp[Max_Status+42][Max_Status+42],mod,f1[Max_Status+42][Max_Status+42],f2[Max_Status+42][Max_Status+42];

int main()
{
	scanf("%d%lld",&n,&mod);
	
	for(reg int i = 2,x; i <= n; ++i)
	{
		x = i;
		
		for(reg int j = 1; j <= 8; ++j)
			if(x % p[j] == 0)
			{
				while(x % p[j] == 0) x /= p[j];
				
				g[i].d |= (1<<(j-1));
			}
			
		g[i].color = x;
	}
	
	sort(g+2,g+n+1);
	
	dp[0][0] = 1;
	
	for(int i = 2; i <= n; ++i)
	{
		if(g[i].color == 1 || g[i].color != g[i-1].color)//分组，某个人可以连续吃含同一超过19的质数的寿司，所以不能更新。 
		{
			for(reg int i = 0; i <= Status; ++i)
				for(reg int j = 0; j <= Status; ++j)
					f1[i][j] = f2[i][j] = dp[i][j];
		}
		
		for(reg int j = Status; j >= 0 ; --j)
			for(reg int k = Status; k >= 0 ; --k)
			{
				/*if(j == 0 && k == 0)
				{
					puts("****_***");//手动屏蔽***
				}*/
				
				if(!(j&g[i].d)) f1[j][k|g[i].d] = (f1[j][k] + f1[j][k|g[i].d])%mod;
				if(!(k&g[i].d)) f2[j|g[i].d][k] = (f2[j][k] + f2[j|g[i].d][k])%mod;
			}
			
		if(g[i].color != g[i+1].color || g[i].color == 1)
			for(reg int j = 0; j <= Status ; ++j)
				for(reg int k = 0; k <= Status ; ++k)
					dp[j][k] = (f1[j][k] + f2[j][k] - dp[j][k] + mod)%mod;
	}
	
	LL ans = 0;
	
	for(reg int j = 0; j <= Status ; ++j)
		for(reg int k = 0; k <= Status ; ++k)
			if(!(j&k)) ans = (ans + dp[j][k]) % mod;
	
	printf("%lld",ans);
	
	return 0;
}
