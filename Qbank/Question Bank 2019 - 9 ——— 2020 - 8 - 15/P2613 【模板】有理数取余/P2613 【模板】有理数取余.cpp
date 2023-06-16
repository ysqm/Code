# include <cstdio>
# include <cstring>
# define reg register
# define mod 19260817
# define LL long long

inline void in(LL& x)
{
	x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();

	while(ch <= '9' && ch >= '0'){
		x = ((x << 3) + (x << 1) + (ch ^ 48)) % mod;
		ch = getchar();
	}
} 

inline LL fast_pow(LL x,LL p)
{
	LL ans = 1;
	for(;p;p >>= 1,x = (x * x) % mod)
		if(p & 1) ans = (ans * x) % mod;
	return ans;
}


int main()
{
	LL a,b;in(a);in(b);
	if(b == 0)puts("Angry!");
	else printf("%lld",(a * fast_pow(b,mod - 2)) % mod);
	return 0;
}
