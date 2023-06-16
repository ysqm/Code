# include <cstdio>
# define reg register

inline void in(int& x)
{
	x = 0;reg char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
}

inline int Read()
{
	int x = 0;reg char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
	
	return x;
}

inline int Max(const int& a,const int b){return b > a ? b : a;}

int n,v[42],V;
long long dp[10042];
int main()
{
	in(V);in(n);dp[0] = 1;
	
	for(reg int i = 1; i <= V; ++i) in(v[i]);
	
	for(reg int i = 1; i <= V; ++i)
		for(reg int j = v[i]; j <= n; ++j)
			dp[j] += dp[j - v[i]];
	
	
	printf("%lld",dp[n]);		
	
	return 0;
}
