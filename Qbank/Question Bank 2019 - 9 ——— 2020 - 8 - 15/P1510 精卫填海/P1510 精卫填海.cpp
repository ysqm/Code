# include <cstdio>
# define N 10000

inline void in(int& x)
{
	x = 0; char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
}

inline int Max(const int& a,const int b){return a > b ? a : b;}

int n,v[N + 42],g,c,w[N + 42],ans,f[N + 42];

int main()
{
	in(g);in(n);in(c);

	for(register int i = 1; i <= n; ++i){in(v[i]);in(w[i]);}
	
	for(register int i = 1; i <= n; ++i)
		for(register int j = c; j >= w[i]; --j)
			f[j] = Max(f[j],f[j - w[i]] + v[i]);
	
	for(register int i = 0; i <= c; ++i)if(f[i] >= g){printf("%d",c - i);return 0;}
	
	printf("Impossible");
	
	return 0;
}
