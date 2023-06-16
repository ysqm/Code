# include <cstdio>
# include <algorithm>
# define LL long long
# define N 10000
# define reg register
using namespace std;

inline void in(int& x)
{
	x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
}

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
	
	return x;
}

int f[N + 42],V,n,cos[N + 42],sin[N + 42];

int main()
{
	in(V);in(n);
	
	for(reg int i = 1; i <= n; ++i){in(sin[i]);in(cos[i]);}
	
	for(reg int i = 1; i <= n; ++i)
		for(reg int j = cos[i]; j <= V; ++j)
			f[j] = max(f[j],f[j - cos[i]] + sin[i]);
	printf("%d",f[V]);
	return 0;
}
