# include <cstdio>
# define LL long long
# define mod 1000000007

LL Cn[1000042];//,inv[1000042];
LL a,b,c,sum,tmp,ans;
int n;
bool flag;

inline LL fast_pow(LL a)
{
	long long x = 1;
	for(register int p = 1000000005; p ; p >>= 1,a = (a * a) % mod) if(p & 1) x = (x * a) % mod;
	return x;
}

int main()
{
	Cn[0] = 1;
	
	scanf("%lld%lld%d",&a,&b,&n);
	
	for(register int i = 1; i <= n; ++i) Cn[i] = Cn[i - 1] * i % mod;
	
	//for(register int i = 2; i <= n; ++i) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	
	c = a - b;
	
	sum = b * n;
	
	for(register int i = 0; i <= n; ++i){
		flag = false;tmp = sum + c * i;
		
		while(tmp){
			if(tmp % 10 != a && tmp % 10 !=  b){flag = false;break;}
			flag = true;tmp /= 10;
		}
		
		if(flag) ans = (ans + Cn[n] * fast_pow(Cn[i] * Cn[n - i] % mod))% mod;
	}
	
	printf("%lld",ans);
	
	return 0;
}
