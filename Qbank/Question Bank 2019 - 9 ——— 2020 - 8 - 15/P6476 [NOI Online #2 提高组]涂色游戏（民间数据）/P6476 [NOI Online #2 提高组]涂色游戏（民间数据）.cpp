# include <cstdio>
# include <algorithm>
# include <queue>
# include <cstring>
# define INF 0x7f7f7f7f
# define reg register
# define LL long long

inline void in(LL& x)
{
	x = 0; char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
}

inline int Read()
{
	reg int x = 0;reg char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;
}

inline int Gcd(const LL& a,const LL b){return !b ? a : Gcd(b,a%b);}

LL T,p1,p2,GCD,k;

signed main()
{
	in(T);
	
	while(T--){
		
		in(p1);in(p2);in(k);
		
		if (k == 1){puts("NO");continue;}
		
		if(p1 > p2) p1 ^= p2 ^= p1 ^= p2;
		
		GCD = Gcd(p1,p2);
		
		p1 /= GCD;p2 /= GCD;
		
		puts((p2 > 2 && (p2 - 2) / p1 + 1 >= k) ? "NO" : "YES");
	}
	
	return 0;
}
