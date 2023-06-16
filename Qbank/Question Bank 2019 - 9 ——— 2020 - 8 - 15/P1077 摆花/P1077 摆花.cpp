# include <cstdio>
# define N 100
# define reg register
# define mod 1000007;

int f[N + 42],n,m,a[N + 42];

inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = x * 10 + (c ^ 48);c = getchar();}
	
	return x;
}

inline int Min(const int& a,const int& b){return a > b ? b : a;}

int main()
{
    n = Read();m = Read();f[0] = 1;
	
	for(reg int i = 1; i <= n ; ++i) a[i] = Read();
	
	for(reg int i = 1; i <= n; ++i)
		for(reg int j = m; j >= 0; --j)
			for(reg int k = 1; k <= Min(j,a[i]); ++k)
				f[j] = (f[j] + f[j - k]) % mod;
	
	printf("%d",f[m]);
 	
    return 0;
}
