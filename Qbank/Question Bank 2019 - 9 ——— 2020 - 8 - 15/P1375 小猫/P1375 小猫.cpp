# include <cstdio>
# define mod 1000000007
# define reg register
# define LL long long

inline LL fast_pow(LL x,LL p)
{
	LL ans = 1;
	
	for(; p ; p >>= 1,x = (x * x) % mod) if(p & 1) ans = (ans * x) % mod;
	
	return ans;
}

LL Cn[200042] = {1},n;

inline LL mul(LL a,LL b)
{
	LL ans = 0;
	
	for(; b ; a = (a + a) % mod,b >>= 1) 
		if(b & 1) ans = (ans + a) % mod;
	
	return ans;
}

int main()
{
	scanf("%d",&n);n <<= 1;
	
	for(reg int i = 1; i <= n; ++i) 
		Cn[i] = Cn[i - 1] * i % mod;n >>= 1;
	
	printf("%lld",Cn[n<<1] * fast_pow(mul(Cn[n],Cn[n + 1]),mod - 2) % mod);
	
	return 0;
}
