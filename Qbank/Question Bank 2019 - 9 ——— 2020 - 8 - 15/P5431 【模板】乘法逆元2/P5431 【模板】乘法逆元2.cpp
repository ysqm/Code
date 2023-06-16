# include <cstdio>
# include <algorithm>
# define N 5000000
# define LL long long
# define reg register

inline void in(LL& x)
{
	x = 0; char ch = getchar();//int f = 1;
	
	while(ch < '0' || ch > '9')/*{if(ch == '-') f = -1;*/ch = getchar();//}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	//x *= f;
}

inline int Read()
{
	int x = 0; char ch = getchar();//int f = 1;
	
	while(ch < '0' || ch > '9')/*{if(ch == '-') f = -1;*/ch = getchar();//}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x /*= f*/;
}


inline LL exgcd(LL a,LL b,LL& x,LL& y)
{
	if(b == 0){x = 1;y = 0;return a;}
	LL ans = exgcd(b,a % b,x,y);
	x ^= y ^= x ^= y;
	y = y - a / b * x;
	return ans;
}

LL n,mod,k,a[N + 42],s[N + 42],p[N + 42],ans;

inline LL inv(const LL& p)
{
	if(p == 1) return 1;
	else return ((mod - mod / p) * inv(mod % p) % mod);
} 

int main()
{
	in(n);in(mod);in(k);p[n + 1] = s[0] = 1;
	
	for(reg int i = 1; i <= n; ++i)s[i] = (s[i - 1] * (a[i] = Read())) % mod;
	
	for(reg int i = n; i ; --i) p[i] = p[i + 1] * a[i] % mod;
	
	for(reg int i = 1,j = k; i <= n; ++i,j = j * k % mod) ans = (ans + (j * s[i - 1] % mod * p[i + 1]))% mod;

	printf("%lld",ans * inv(s[n]) % mod);
	
	return 0;
}
