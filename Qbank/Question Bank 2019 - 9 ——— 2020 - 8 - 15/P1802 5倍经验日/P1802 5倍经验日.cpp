# include <cstdio>
# include <cstring>
# define reg register
# define N 248
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

int f[N + 42],n,x,W[N + 42],sum,V[N + 42];

int main()
{
	n = Read(); x = Read();
	
	for(reg int i = 1,a,b; i <= n ; ++i) 
	{a = Read();b = Read();W[i] = b - a;sum += a;V[i] = Read();} 
	
	for(reg int i = 1; i <= n; ++i)
		for(reg int j = x; j >= V[i] ; --j)
			f[j] = Max(f[j],f[j-V[i]] + W[i]); 
			
	
	
	printf("%lld",(f[x] + sum) * 5LL);
	
	return 0;
}

/*

# include <cstdio>
# include <cstring>
# define reg register
# define N 1000
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

int f[N + 42],n,x,A[N + 42],B[N + 42],sum,V[N + 42];

int main()
{
	n = Read(); x = Read();
	
	for(reg int i = 1; i <= n ; ++i) 
	{A[i] = Read();B[i] = Read();V[i] = Read();} 
	
	for(reg int i = 1; i <= n; ++i)
		for(reg int j = x; ~j ; --j)
			if(j >= V[i])f[j] = Max(f[j] + A[i],f[j-V[i]] + B[i]);
			else f[j] += A[i];
	
	printf("%lld",f[x] * 5LL);
	
	return 0;
}

*/
