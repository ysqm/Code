# include <cmath>
# include <cstdio>
# include <algorithm>
# define reg register
# define N 100
# define NN 10000

inline int Max(const int x,const int y){return x > y ? x : y;} 

int a[N + 5],b[N + 5],n,m,f[NN + 42],g[NN + 42],ans;

int main()
{
	scanf("%d",&n);
	
	for(reg int i = 1; i <= n; ++i) scanf("%d",&a[i]);
	
	for(reg int i = 1; i <= n; ++i) scanf("%d",&b[i]);
	
	for(reg int i = 1; i <= n; ++i) m += a[i];
	
	for(reg int i = m+100; i >= 1; --i) f[i] = n;
	
	for(reg int i = 1; i <= n; ++i)
		for(reg int j = m+100; j >= b[i] ; --j)
			if(f[j - b[i]]+1 < f[j])
				{
					f[j] = f[j-b[i]]+1;
					g[j] = g[j-b[i]]+a[i];
				}
			else if(f[j-b[i]]+1 == f[j]) g[j] = Max(g[j],g[j-b[i]]+a[i]);
			
	f[0] = n;
			
	for(reg int i = m+100; i >= m; --i)
		if(f[ans] > f[i]) ans = i;
		else if(f[ans] == f[i] && g[ans] < g[i]) ans = i;
	
	printf("%d %d",f[ans],m - g[ans]);
	
	return 0; 
}
