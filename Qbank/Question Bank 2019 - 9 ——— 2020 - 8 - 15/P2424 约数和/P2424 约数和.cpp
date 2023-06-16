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

LL a,b;

inline LL sum(const LL n)
{
	LL ans = 0;
	
	for(register LL l = 1,r; l <= n ; l = r + 1){r = n / (n / l);ans += ((n / l) * (l + r) * (r - l + 1)) >> 1;}
	
	return ans;
}

int main()
{
	a = Read();b = Read();
	
	printf("%lld", sum(b) - sum(a - 1));
	
	return 0;
}
