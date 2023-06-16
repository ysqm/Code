# include <cstdio>
# define N 50000
# define inf 0x7f7f7f7f7f
# define LL long long
# define reg register

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}
inline int MIn(const int& a,const int& b){return a < b ? a : b;}
inline int Min(const LL& a,const LL b){return a < b ? a : b;}

int n,w[N + 42],m,f[100042];

int main()
{
	in(m);in(n);
	
	f[0] = true;
	
	for(reg int i = 1; i <= n; ++i) in(w[i]);
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = m; j >= 0; --j)
			if(f[j]) f[j + w[i]] = true;
			
	for(reg int i = m ; i >= 0; --i) if(f[i]) {printf("%d",i);return 0;}
}
