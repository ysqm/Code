# include <cstdio>
# include <stack>
# define N 500000
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

long long n,h[N + 42],stack[N + 42],ans,num[N + 42];

int main()
{
	in(n);reg int top;
	for(reg int i = 1; i <= n; ++i){
		in(h[i]);num[i] = 1;
		for(;top && h[stack[top]] <= h[i];top--) {
			ans += num[stack[top]];
			if(h[stack[top]] == h[i]) num[i] += num[stack[top]];	
		}
		if(top) ++ans;
		stack[++top] = i;
	}
	
	printf("%lld",ans);
	return 0;
}
