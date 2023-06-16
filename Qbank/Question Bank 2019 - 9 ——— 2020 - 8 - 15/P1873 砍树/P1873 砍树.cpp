# include <cstdio>
# include <algorithm>
# define reg register
# define N 1000000
# define LL long long

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9')ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

int n,a[N + 42],res;

int main()
{
	n = Read();res = Read();
	
	for(reg int i = 1; i <= n; ++i) a[i] = Read();
	
	std::sort(a + 1,a + n + 1);
	
	for(reg int i = n; i ; --i)
	{
		if((a[i+1]-a[i])*(n-i) > res)
		{
			if(res%(n-i) == 0) printf("%d\n",a[i+1]-res/(n-i));
			else printf("%d\n",a[i+1]-res/(n-i)-1);
			return 0;
		}
		res -= (a[i+1]-a[i])*(n-i);
	}
}

