# include <cstdio>
# include <cstring>
# define reg register
# define N 100000
# define Ls(i) (i<<1)
# define Rs(i) (i<<1|1)

inline int Read()
{
	 int x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

inline int Min(const int a,const int b){return a < b ? a : b;}
inline int Max(const int a,const int b){return a > b ? a : b;}

int nx[N + 42],h[N + 42],a[N + 42],n;

int main()
{
	n = Read();
	
	for(reg int i = 1; i <= n ; ++i)
	{
		a[i] = Read();
		h[a[i]] = a[i-1];
		nx[a[i-1]] = a[i];
	}
	
	for(reg int i = n ; i >= 1; --i)
		if(nx[i]) 
			{
				printf("%d %d ",i,nx[i]);
				nx[h[i]] = nx[nx[i]];
				h[nx[h[i]]] = h[i];
				nx[nx[i]] = 0;
			}
	
	return 0;
}
