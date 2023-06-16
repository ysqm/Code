# include <cstdio>
# include <vector>
# include <queue>
# define reg register
# define N 2500
# define M 2500
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

inline int Min(const int a,const int b){return a < b ? a : b;}

int n,m,ans,S[N + 5][M + 5],H[N + 42][M + 42],a[N + 5][M + 5],f[N + 5][M + 5];

inline int Max(const int a,const int b){return a > b ? a : b;}
inline void Chk(const int b){if(b > ans) ans = b;}

int main()
{
	#ifdef ONLINE_JUDGE
	#else
    freopen("1.txt","r",stdin);
	#endif
	
	n = Read();m = Read();
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1; j <= m ; ++j)
			if((a[i][j] = Read()) == 0)
			{
				H[i][j] = H[i-1][j]+1;
				S[i][j] = S[i][j-1]+1;
			}
			else
			{
				f[i][j] = Min(f[i-1][j-1],Min(H[i-1][j],S[i][j-1])) + 1;
				Chk(f[i][j]);
			}
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1; j <= m ; ++j)
			H[i][j] = S[i][j] = f[i][j] = 0;
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = m; j >= 1 ; --j)
			if(a[i][j] == 0)
			{
				H[i][j] = H[i-1][j]+1;
				S[i][j] = S[i][j+1]+1;
			}
			else
			{
				f[i][j] = Min(f[i-1][j+1],Min(H[i-1][j],S[i][j+1])) + 1;
				Chk(f[i][j]);
			}		
	
	
	printf("%d",ans);
	
	return 0;
}


