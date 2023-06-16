# include <cstdio>
# include <cstring>
# include <queue>
# define N (1 << 9)
# define STATUS 144
# define reg register
using namespace std;

template <typename T>
inline T in(T& x)
{
	x = 0;char c = getchar();int f = 1;
	
	while(c < '0' || c > '9') {if(c == '-') f = -1 ; c = getchar();} 
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}x *= f;
} 

inline int Read()
{
	int x = 0,f = 1;char c = getchar();
	
	while(c < '0' || c > '9') {if(c == '-') f = - 1 ;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
	
	return f * x;
} 

template <typename T>
inline T min(const T A,const T B){return A < B ? A : B;} 

template <typename T>
inline T max(const T A,const T B){return A > B ? A : B;}  

int n,m,temp_tot,knight[STATUS + 42],sum[STATUS + 42];
long long dp[10][STATUS + 42][STATUS + 42];

inline void show(int x)
{
	for(reg int i = n; i ; --i)
		if(x & (1 << i)) printf("1");
		else printf("0");
	printf("\n");
}

signed main()
{
	in(n);in(m);
	
	for(reg int s = 0; s < (1 << n) ; ++s){
		int tot = 0,s1 = s;
		while(s1){
			if(s1 & 1) tot++;
			s1 >>= 1;
		}
		if((((s << 1) | (s >> 1)) & s) == 0) {knight[++temp_tot] = s;sum[temp_tot] = tot;}
	}
	
	dp[0][1][0] = 1;
	
	for(reg int i = 1; i <= n ; ++i)
		for(int j = 1; j <= temp_tot ; ++j)
			for(int k = 0; k <= m ; ++k)
				if(sum[j] <= k) for(int p = 1; p <= temp_tot ; ++p)
									if(((knight[p] | (knight[p] >> 1) | (knight[p] << 1)) & knight[j]) == 0)
										dp[i][j][k] += dp[i - 1][p][k - sum[j]];
	
	long long ans = 0;
	
	for(reg int i = 1; i <= temp_tot ; ++i) ans += dp[n][i][m];
	
	printf("%lld",ans); 
	return 0;
}
