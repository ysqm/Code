# include <cstdio>
# include <algorithm>
# define reg register
# define N 2500
# define LL long long

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-')f = -1;ch = getchar();}
	 
	while(ch >= '0' && ch <= '9') {x = x*10 + (ch ^ 48);ch = getchar();}
	
	return x * f;
}

inline int ABS(const int a){return a > 0 ? a : -a;}
inline int Min(const int& a,const int b){return a > b ? b : a;}

int sum[N + 42],n,m,f[N + 42];

int main()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= n ; ++i) sum[i] = sum[i-1] + (Read() == 2 ? -1 : 1),f[i] = i; 
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1 ; j <= i ; ++j)
			if(ABS(sum[i] - sum[j-1]) == i - j + 1 || ABS(sum[i] - sum[j-1]) <= m) f[i] = Min(f[i],f[j-1] + 1);
			
	printf("%d\n",f[n]);
	
	return 0;
}
