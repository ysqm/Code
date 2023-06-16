# include <cstdio>
# define reg register
# define ll long long

ll a,m,b,phi = 1;bool flag;

int main()
{
	scanf("%lld%lld",&a,&m);a %= m;reg int tmp = m;
	
	for(reg int i = 2; i * i <= tmp; ++i)
		if(tmp % i == 0) {
			phi *= i - 1;tmp /= i;
			while(tmp % i == 0){phi *= i;tmp /= i;}
		}
	if(tmp > 1) phi *= tmp - 1;
	
	char ch = getchar();
	
	while(ch < '0' || ch > '9')ch = getchar();
	
	while(ch >= '0' && ch <= '9'){b = (b << 3) + (b << 1) + (ch ^ 48);ch = getchar();if(b >= phi){flag = 1;b %= phi;}}

	if(flag) b += phi;
	
	reg int ans = 1;
	
	for(;b;b >>= 1,a = a * a % m) if(b & 1) ans = ans * a % m;
	
	printf("%lld",ans);
	
	return 0;
}
