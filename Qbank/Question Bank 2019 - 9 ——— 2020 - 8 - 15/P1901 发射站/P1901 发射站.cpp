# include <cstdio>
# define N 1000000
# define reg register

inline void in(int& x)
{
	x = 0;reg char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
}

inline void in(long long& x)
{
	x = 0;reg char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
}

inline int Max(const int& a,const int b){return b > a ? b : a;}

long long n,v[N + 42],h[N + 42],sum[N + 42],stack[N + 42],top;

int main()
{
	in(n);
	for(reg int i = 1; i <= n; ++i){
		in(h[i]);in(v[i]);
		while(top && h[stack[top]] < h[i]) sum[i] += v[stack[top--]];
		sum[stack[top]] += v[i];
		stack[++top] = i;
	}top = 0;
	
	for(reg int i = 1; i <= n; ++i) top = Max(top,sum[i]);
	printf("%lld",top);
	return 0;
}
