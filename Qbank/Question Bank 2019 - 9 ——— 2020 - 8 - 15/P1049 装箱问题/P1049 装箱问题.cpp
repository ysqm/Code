# include <cstdio>
# include <algorithm>
# define REG register
# define N 20000
using namespace std;

typedef long long LL;

template <typename T>
inline void in(T& x)
{
	x = 0;char c = getchar();int f = 1;
	
	while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	x *= f;
	
	return ;
} 

//template <typename T>
inline int Read()
{
	int x = 0;char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) +c - 48;c = getchar();}
	
	return x;
}

int dp[N + 42],a[42],n,V; 

int main()
{
	in(V);in(n);
	
	for(REG int i = 1; i <= n ; ++i) in(a[i]);
	
	for(REG int i = 1; i <= n; ++i)
		for(REG int j = V; j >= a[i]; --j)
			dp[j] = max(dp[j],dp[j - a[i]] + a[i]);
	printf("%d",(V - dp[V]) > 0 ? V - dp[V] : 0);
	return 0;
}
