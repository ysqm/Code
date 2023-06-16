# include <cstdio>
# include <vector>
# include <queue>
# define reg register
# define N 1000
# define V 20000
# define mod 998244353 
# define INF 0x7f7f7f7f7f7f7f7f
# define Gc getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;

inline int Read()
{
	register int x = 0;register char ch = Gc;
	
	while(ch < '0' || ch > '9') ch = Gc;
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return x;
}

inline int Max(const int a,const int& b){return a > b ? a : b;}

inline int Mod(int& x,const int y)
{
	x += y;
	if(x >= mod) x-=mod;
} 

int dp[N + 5][(V<<1) + 5],ans,base;
int n,a[V + 42];

int main()
{
	#ifdef ONLINE_JUDGE
	#else
    freopen("2.txt","r",stdin);
	#endif
	
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i) base = Max(a[i] = Read(),base);
	
	for(reg int i = 2; i <= n ; ++i)
		for(reg int j = 1; j < i ; ++j)
		{
			Mod(dp[i][a[i]-a[j]+base],dp[j][a[i]-a[j]+base]+1);
			
			Mod(ans,dp[j][a[i]-a[j]+base] + 1); 
		}
		
	Mod(ans,n);
	
	printf("%d",ans);
	
	return 0;
}


