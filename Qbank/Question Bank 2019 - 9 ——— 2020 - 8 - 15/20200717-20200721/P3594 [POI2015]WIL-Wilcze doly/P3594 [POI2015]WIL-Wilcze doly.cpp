# include <cstdio>
# define reg register 
# define N 2000000
# define LL long long

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

inline LL ReadL()
{
	LL x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

inline LL Max(const LL& a,const LL b){return a < b ? b : a;} 

int q[N + 42],n,d;
LL a[N + 42],s[N + 42],p;

int main()
{
	n = Read();p = ReadL();d = Read();
	
	for(reg int i = 1; i <= n ; ++i) s[i] = s[i-1] + (a[i] = ReadL());

	int t = 0,h = 0,ans = d,l = 1;
	
	q[t] = d;
	
	for(int i = d+1; i <= n ; ++i)
	{
		while(h <= t && s[i] - s[i - d] >  s[q[t]] - s[q[t]-d]) --t;
		
		q[++t] = i;
		
		while(h <= t && s[i] - s[l-1] - s[q[h]] + s[q[h]-d] > p)
		{
			++l;
			
			while(h <= t && q[h] - d + 1 < l) ++h;
		}
		
		ans = Max(ans,i - l + 1);
	}
	
	printf("%lld\n",ans);
	
	return 0;
}
