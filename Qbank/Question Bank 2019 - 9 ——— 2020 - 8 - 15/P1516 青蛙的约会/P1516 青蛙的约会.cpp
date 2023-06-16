# include <cstdio>
# define reg register
# define LL long long

LL ans;

inline LL exgcd(LL a,LL b,LL& x,LL& y)
{
	if(b == 0){x = 1;y = 0;return a;}
	ans = exgcd(b,a % b,x,y);
	x ^= y ^= x ^= y;
	y = y - a / b * x;
	return ans;
}

LL x,y,m,n,l;

int main()
{
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	
	LL a = n - m,b = x - y;
	
	if(a < 0){b = -b;a = -a;}
	
	exgcd(a,l,x,y);l /= ans;
	
	if(b % ans != 0) puts("Impossible");
	else printf("%lld",((x * (b / ans) % l) + l) % l);
}
