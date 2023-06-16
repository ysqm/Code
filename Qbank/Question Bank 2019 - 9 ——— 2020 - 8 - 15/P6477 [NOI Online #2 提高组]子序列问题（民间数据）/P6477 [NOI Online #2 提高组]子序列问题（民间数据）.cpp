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

template <class T>
inline T Read()
{
	reg T x = 0;reg char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;
}

inline int Gcd(const LL& a,const LL b){return !b ? a : Gcd(b,a%b);}

LL C[N + 42],S[N + 42];
int a[N + 42],b[N + 42],d[N + 42],last[N + 42];

signed main()
{
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i) b[i - 1] = a[i] = Read();
	
	
	
	
	return 0;
}
