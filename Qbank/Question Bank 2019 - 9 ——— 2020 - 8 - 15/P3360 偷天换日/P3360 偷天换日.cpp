# include <cstdio>
# include <cstring>
# define N 600
# define reg register
# define LL long long
# define M 10000

template <typename T>
inline void in(T& x)
{
	x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
} 

inline LL Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
	
	return x;
} 

template <typename T> inline T Min(const T A,const T B){return A < B ? A : B;} 

template <typename T> inline T Max(const T A,const T B){return A > B ? A : B;} 

template <typename T> inline void check(T& A,T B){if(A < B) A = B;}

LL dp[M + 42][N + 42],W[N + 42],V[N + 42],T,tot;

void dfs(const LL K,const int TIME)
{
	LL T1,x;
	
	T1 = Read()<<1;in(x);
	
	if(x)
	{
		for(reg int i = 1; i <= x ; ++i){W[i] = Read();V[i] = Read();}
		
		for(reg int i = 1; i <= x ; ++i)
			for(reg int j = TIME; j >= T1 + V[i]; --j)
				dp[K][j] = Max(dp[K][j-V[i]] + W[i],dp[K][j]);
	}
	else 
	{
		int l = ++tot,r = ++tot; 
		
		dfs(l,TIME-T1);dfs(r,TIME-T1);
		
		for(reg int i = TIME; i >= T1 ; --i)
			for(reg int j = 0; j <= i - T1; ++j)
				dp[K][i] = Max(dp[l][j] + dp[r][i - j - T1],dp[K][i]);
	}
}

int main()
{
	in(T);--T;
	
	dfs(1,T);
	
	/*for(reg int i = 1; i <= 20; ++i)
	{
		for(reg int j = 1; j <= T ; ++j) printf("%d ",dp[i][j]);
		puts("");
	}*/	
	
	printf("%lld\n",dp[1][T]);
	
	return 0;
}

