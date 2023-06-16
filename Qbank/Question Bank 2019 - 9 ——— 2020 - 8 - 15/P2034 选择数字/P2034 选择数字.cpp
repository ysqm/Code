# include <cstdio>
# include <algorithm>
# include <bitset>
# include <cstring>
# define reg register
# define N 2000000
# define LL long long
using namespace std;

inline void in(LL& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

/*inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}*/

LL n,k,t[N + 42],sum,dp[N + 42],ans = 0x7f7f7f7f7f7f;

int main()
{
	in(n);in(k);++k;
	
	//if(n == 50000 && k == 64) {printf("24929172824025");return 0;}
	
	for(reg LL tail = 1,head = 1,i = 1,a;i <= n;++i){
		in(a);
		while(i - t[head] > k) ++head;
		dp[i] = dp[t[head]] + a;
		while(head <= tail && dp[t[tail]] >= dp[i]) --tail;
		t[++tail] = i;
		sum += a;
	}
	
	for(reg LL i = n - k + 1; i <= n; ++i)
		ans = min(ans,dp[i]);
	
	printf("%lld",sum - ans);
	return 0;
}
