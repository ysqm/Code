# include <cstdio>
# include <algorithm>
# define LL long long
# define N 100
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

int G[N + 42][N + 42],g[N + 42][N +42],m,n;

int main()
{
	in(n);in(m);
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j  = 1; j <= n ; ++j)
			g[i][j] = 0x7f7f7f;
	
	for(reg int i = 1,a,b,c; i <= m ; ++i){
		in(a);in(b);in(c);
		G[a][b] = G[b][a] = c;
		g[a][b] = g[b][a] = 0;
	}
	
	in(m);
	
	for(reg int i = 1,a,b; i <= m; ++i){
		in(a);in(b);
		g[a][b] = g[b][a] = G[a][b];
	}
	
	for(reg int k = 1; k <= n; ++k)
		for(reg int i = 1; i <= n; ++i)
			for(reg int j = 1; j <= n; ++j)
				g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
	
	printf("%d",g[Read()][Read()]);
	
	return 0;
}
