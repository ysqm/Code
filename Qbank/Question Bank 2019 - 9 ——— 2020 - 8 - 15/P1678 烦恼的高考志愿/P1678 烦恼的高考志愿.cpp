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

inline int Min(const int a,const int b){return a > b ? b : a;}
inline int ABS(const int a){return a < 0 ? -a : a;}

int n,a[N + 42],b[N + 42],ans,m;

int main()
{
	m = Read();n = Read();
	
	for(reg int i = 1; i <= m; ++i) a[i] = Read();
	
	for(reg int i = 1; i <= n; ++i) b[i] = Read();
	
	std::sort(a + 1,a + m + 1);
	
	a[0] -= a[m+1] = 0x7f7f7f7f;
	
	std::sort(b + 1,b + n + 1);
	
	for(reg int i = 1,cur = 1; i <= n; ++i)
	{
		while(a[cur] < b[i]) ++cur;
		
		ans += Min(a[cur]-b[i],b[i]-a[cur-1]);
	}
	
	printf("%d",ans);
}

