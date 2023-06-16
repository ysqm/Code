# include <cstdio>

int main()
{
	register long long p,x = 2,ans = 1;scanf("%lld",&p);--p;
	
	for(; p ; p >>= 1,x = (x * x) % 6662333) if(p & 1) ans = (ans * x) % 6662333;
	
	printf("%lld",ans);

}
