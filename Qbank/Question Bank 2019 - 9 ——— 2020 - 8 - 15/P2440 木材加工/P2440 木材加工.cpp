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

inline int Min(const int a,const int b){return a > b ? b : a;}
inline int ABS(const int a){return a < 0 ? -a : a;}

int n,wood[N + 42],k,sum,ans;

inline bool check(const int len)
{
	reg int res = 0;
	
	for(reg int i = 1; i <= n; ++i) res += wood[i]/len;
	
	return res < k; 
}

int main()
{
	n = Read();k = Read();
	
	for(reg int i = 1; i <= n; ++i) sum += wood[i] = Read();
	
	reg int l = 1,r = sum / k,mid;
	
	while(l < r)
	{
		mid = (r + l)>>1;
		
		if(check(mid)) r = mid;
		else l = mid+1,ans = mid;
	}
	
	printf("%d\n",ans);	
	
	return 0;
}

