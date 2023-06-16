# include <cstdio>
# include <algorithm>
# define N 20000
# define LL long long
# define reg register

inline void in(LL& x)
{
	x = 0; char ch = getchar();//int f = 1;
	
	while(ch < '0' || ch > '9')/*{if(ch == '-') f = -1;*/ch = getchar();//}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	//x *= f;
}

inline LL exgcd(LL a,LL b,LL& x,LL& y)
{
	if(b == 0){x = 1;y = 0;return a;}
	LL ans = exgcd(b,a % b,x,y);
	x ^= y ^= x ^= y;
	y = y - a / b * x;
	return ans;
}


LL n,a[N + 42],b[N + 42],mod = 1,ans;



int main()
{
	in(n);
	
	for(reg int i = 1; i <= n; ++i){in(a[i]);in(b[i]);mod *= a[i];}
	
	LL ea,x,y;
	
	for(reg int i = 1; i <= n; ++i){
		ea = mod / a[i];
		exgcd(ea,a[i],x,y);
		ans = ((ans + ea * x * b[i]) % mod + mod) % mod;
	}
	
	printf("%lld",ans);
	
	return 0;
}
