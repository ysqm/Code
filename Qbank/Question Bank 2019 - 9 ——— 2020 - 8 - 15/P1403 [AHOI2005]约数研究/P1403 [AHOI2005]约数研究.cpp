# include <cstdio>
# include <cmath>

typedef long long LL;

inline LL Read()
{
	register LL x = 0;register char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9') {x = x * 10 + (c ^ 48);c = getchar();}
	
	return x;
}

LL n,ans;

int main()
{
	n = Read();
	
	for(register int i = 1; i <= n ; ++i) ans += n / i;
	 
	printf("%d",ans);
	
	return 0;
}
