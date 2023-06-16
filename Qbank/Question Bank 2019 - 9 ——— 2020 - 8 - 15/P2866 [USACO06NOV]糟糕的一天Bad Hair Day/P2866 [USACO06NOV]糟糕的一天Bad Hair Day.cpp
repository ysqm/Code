# include <cstdio>
# include <algorithm>
# include <bitset>
# define reg register
using namespace std;

inline void in(long long& x)
{
	x = 0;char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

inline void in(int& x)
{
	x = 0;char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

long long n,ans,stack[80042],top;

int main()
{
	in(n);
	in(stack[++top]);
	for(reg int i = 2,a; i <= n ; ++i){
		in(a);
		while(a >= stack[top] && top > 0) --top;
		ans += top;
		stack[++top] = a;	 
	}
	printf("%lld",ans);
	return 0;
}
