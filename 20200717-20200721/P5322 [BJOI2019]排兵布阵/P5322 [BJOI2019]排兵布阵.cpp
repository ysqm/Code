# include <cstdio>
# include <queue>
# include <cstring>
# include <algorithm>
# define reg register 
# define N 100
# define M 20000
# define LL long long

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return f == -1 ? -x : x;
}

inline int Max(const int a,const int b){return a < b ? b : a;} 

int s,n,m,dp[M+42],a[N+42][N+42],b[N+42][N+42]; 

int main()
{
	s = Read();n = Read();m = Read();
	
	for(reg int i = 1; i <= s ; ++i)
		for(reg int j = 1; j <= n ; ++j)
			a[j][i] = Read()<<1;
			
	/*for(reg int i = 1; i <= m ; ++i)
		for(reg int j = 1; j <= n ; ++j)
			for(reg int k = 1; k <= s ; ++k)
				if(i > a[k][j]) b[j][i] += j;//统计第 j 个城堡出兵为 i 时所能得到的分数. */
	
	for(reg int i = 1; i <= n ; ++i) std::sort(a[i]+1,a[i]+s+1);
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = m; j >= 0; --j)
			for(reg int k = 1; k <= s ; ++k)
				if(j > a[i][k]) dp[j] = Max(dp[j],dp[j-a[i][k]-1]+i*k);
	
	
	//for(reg int j = 1; j <= m; ++j) printf("%d ",dp[j]);
	
	printf("%d\n",dp[m]);
	
	return 0;
}
