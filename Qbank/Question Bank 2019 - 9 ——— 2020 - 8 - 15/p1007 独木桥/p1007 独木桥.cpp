# include <cstdio>
# define reg register
# define N 300000
# define int long long
# define INF 0x7f7f7f7f

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9') {x = x * 10 + (ch ^ 48);ch = getchar();}
	
	return x;
}

int n,ans1,ans2,l;

inline int Max(const int& a,const int b){return a > b ? a : b;}
inline int Min(const int& a,const int b){return a < b ? a : b;}


signed main()
{
	l = Read();
	
	n = Read();
	
	for(reg int i = 1,p; i <= n ; ++i)
	{
		ans1 = Max(ans1,Max(p = Read(),l-p+1));
		ans2 = Max(ans2,Min(p,l-p+1));
	}
	
	printf("%lld %lld",ans2,ans1);
	
	return 0;
}
