# include <cstdio>

long long n,p,inv[3000042];

int main()
{
	scanf("%lld%lld",&n,&p);inv[1] = 1;
	
	for(register int i = 2; i <= n; ++i) inv[i] = (p - p / i) * inv[p % i] % p;
	
	for(register int i = 1; i <= n; ++i)	printf("%lld\n",inv[i]);
	
	return 0;
}
