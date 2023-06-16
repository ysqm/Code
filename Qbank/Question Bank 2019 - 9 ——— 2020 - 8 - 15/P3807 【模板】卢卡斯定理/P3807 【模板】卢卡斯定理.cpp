# include <cstdio>
# define N 100000

int T;
long long n,m,p,Cn[N + 42];

inline long long fast_pow(long long x,long long y)
{
	register long long ans = 1;
	for(; y ; y >>= 1,x = (x * x) % p) if(y & 1) ans = (ans * x) % p;
	return ans;
}

inline long long C(const long long n,const long long m)
{
	if(m > n) return 0;
	else return ((Cn[n] * fast_pow(Cn[m],p - 2)) % p * fast_pow(Cn[n - m],p - 2) % p) % p;
}

inline long long Lucas(const long long n,const long long m)
{
	if(!m) return 1;
	else return Lucas(n / p,m / p) * C(n % p,m % p) % p;
}

int main()
{
	scanf("%d",&T);
	
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&p);Cn[0] = 1;
		for(register int i = 1; i <= p; ++i) Cn[i] = Cn[i - 1] * i % p;
		printf("%lld\n",Lucas(n + m,n));
	}
}
