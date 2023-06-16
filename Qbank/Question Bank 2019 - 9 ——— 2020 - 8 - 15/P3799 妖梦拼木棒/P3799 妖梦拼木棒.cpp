# include <cstdio>
# include <algorithm>
# define N 5000
# define reg register
# define mod 1000000007

inline void in(int& x)
{
	x = 0; char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
}

inline int Read()
{
	reg int x = 0;reg char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;
}

int x[N + 42],n,Cn[N + 42],L;
long long ans;

signed main()
{
	in(n);
	
	for(reg int i = 1; i <= n ; ++i) ++x[Read()];
	
	for(reg int i = 1; i <= 5000; ++i) if(x[i]) {Cn[i] = (x[i] * (x[i] - 1)) >> 1;L = i;}
	
	for(reg int i = 2; i <= L ; ++i)
		if(x[i] > 1)
			for(reg int j = 1 ; j <= (i >> 1) ; ++j)
				if(j != i - j && x[j] && x[i - j]) ans = (ans + Cn[i] * x[j] * x[i - j]) % mod;
				else if(j == i - j && x[i] >= 2) ans = (ans + Cn[i] * Cn[j]) % mod;
	
	printf("%lld\n",ans);
	
	return 0;
}
