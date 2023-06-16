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

struct Point{
	int L,R,value;
} a[N + 42];

int n,stack[N + 42];

int main()
{
	in(n);
	reg int top = 0;
	for(reg int i = 1; i <= n; ++i){
		in(a[i].value);
		a[i].L = a[i].R = i;
		while(top && a[i].value >= a[stack[top]].value){
			a[stack[top]].R = i - 1;
			a[i].L = a[stack[top]].L;
			--top;
		}
		stack[++top] = i;
	}
	for(;top; --top) a[stack[top]].R = n;
	reg long long ans = 0;
	for(reg int i = 1; i <= n; ++i) ans += a[i].value * (i - a[i].L + 1) * (a[i].R - i + 1);
	printf("%lld",ans);
	return 0;
}
