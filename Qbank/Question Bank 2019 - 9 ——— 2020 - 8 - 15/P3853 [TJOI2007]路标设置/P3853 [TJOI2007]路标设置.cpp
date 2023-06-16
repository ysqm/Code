# include <cstdio>
# include <algorithm>
# define reg register
# define N 100000
# define LL long long

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9')ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

int n,a[N + 42],L,K,ans;

inline bool check(const int& x)
{
	int used_ = 0;
	
	for(reg int i = 1; i <= n; ++i)
		if(a[i+1]-a[i] > 0)
		{
			if((a[i+1]-a[i])%x == 0) used_ += ((a[i+1] - a[i])/x)-1;
			else used_ += (a[i+1] - a[i])/x;
		}
	
	return used_ <= K;
}

int main()
{
	L = Read();n = Read();K = Read();
	
	for(reg int i = 1; i <= n ; ++i) a[i] = Read();
	
	a[n+1] = L;
	
	reg int l = 0,r = L,mid;
	
	while(l < r)
	{
		mid = (l + r) >> 1;
		
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	
	printf("%d\n",l);
	
	return 0;
}

