# include <cstdio>
# include <cstring>
# define reg register
# define N 248
# define Ls(i) (i<<1)
# define Rs(i) (i<<1|1)

inline int Read()
{
	 int x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

inline int Min(const int a,const int b){return a < b ? a : b;}
inline int Max(const int a,const int b){return a > b ? a : b;}

int f[N + 42][N + 42],n;

int main()
{
	n = Read(); 
	
	for(reg int i = 1; i <= n ; ++i) f[i][i] = Read();
	
	for(reg int i = 1; i <= n ; ++i)
	{
		for(reg int l = 1 ; l + i <= n ; ++l)
		{
			int r = l + i;
			
			for(reg int j =  l + 1; j <= r ; ++j) 
				f[l][r] = Max(f[l][r],f[l][j-1] == f[j][r] ? f[l][j-1] + 1 : 0);
		}
	}
	
	/*for(reg int i = 1; i <= n; ++i)
	{
		for(reg int j = 1; j <= n ; ++j) printf("%d ",f[i][j]);
		puts("");
	}*/
	
	int ans = 0;
	
	for(reg int i = 1; i <= n; ++i)
		for(reg int j = i; j <= n; ++j)
			ans = Max(ans,f[i][j]);
	
	printf("%d",ans);
	
	return 0;
}
