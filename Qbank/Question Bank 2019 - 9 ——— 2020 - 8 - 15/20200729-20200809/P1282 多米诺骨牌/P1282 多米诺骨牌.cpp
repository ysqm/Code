# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register
# define N 6000
# define INF 0x3f3f3f3f 
# define Gc getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;

inline int Read()
{
	register int x = 0;register char ch = Gc;
	
	while(ch < '0' || ch > '9') ch = Gc;
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return x;
}

inline int Min(const int a,const int b){return a < b ? a : b;}

bool vis[N + 42];
int dp[N + 41],a[N + 41],m,d[N + 41];

int main()
{
	reg int n = Read();

	for(reg int i = 1; i <= n ; ++i) a[i] = Read() - Read();
	
	for(reg int i = 1; i <= n ; ++i) m += a[i];
	
	if(m < 0)
	{
		m = ~m+1;
		
		for(reg int i = 1; i <= n ; ++i) a[i] = -a[i];

	}
	
	for(reg int i = 1; i <= n ; ++i) a[i] = a[i]<<1;
	
	std::sort(a+1,a+n+1);
	
	vis[0] = 1;
	
	for(reg int i = n; i >= 1; --i)
		for(reg int j = m + 101; j >= 0 ; --j)
			if(j+a[i]>=0 && vis[j])
			{
				vis[j+a[i]] = true;
				if(dp[j+a[i]] == 0) dp[j+a[i]] = dp[j]+1;
			}
	
    /*for(reg int j = 1; j <= n ; ++j)
		for(reg int i = m; i >= 0 ; --i)
			if(i+d[j] >= 0) dp[i] = Min(dp[i+d[j]] + 1,dp[i]);*/

	//for(reg int i = 0; i <= m ; ++i) printf("%-3d ",dp[i] == 0x3f3f3f3f ? -1 : dp[i]);
	
	//for(reg int i = 0; i <= m ; ++i) printf("%d ",dp[i]);printf("\n");
	
	dp[0] = 0;
	
	for(reg int i = m; i >= 0; --i) if(vis[i]) {printf("%d",dp[i]);return 0;}
} 
