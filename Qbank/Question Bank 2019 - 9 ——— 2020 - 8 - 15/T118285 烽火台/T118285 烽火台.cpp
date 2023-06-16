# include <cstdio>
# include <algorithm>
# include <bitset>
# include <cstring>
# define reg register
# define N 2000000
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

int n,m,t[N + 42],dp[N + 42],ans;

int main()
{
	in(n);in(m);
	
	ans = 0x7f7f7f7f;dp[0] = 0;
	
	for(reg int i = 1,head = 1,tail = 0,a;i <= n;++i){
		in(a);
		while(head <= tail && dp[i - 1] <= dp[t[tail]]) --tail;
		t[++tail] = i - 1;
		while(t[head] < i - m) ++head;
		dp[i] = dp[t[head]] + a;
	}
	
	for(reg int i = n + 1 - m; i <= n; ++i)
		ans = min(ans,dp[i]);
	printf("%d",ans);
	return 0;
}
