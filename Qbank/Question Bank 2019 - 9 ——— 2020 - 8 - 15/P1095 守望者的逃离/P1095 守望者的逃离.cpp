# include <cstdio>
# define T 300000
# define reg register

inline void in(int& x)
{
	x = 0; char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
}

int m,s,t,dp[T + 42],ans;

int main()
{
	in(m);in(s);in(t);
	for(reg int i = 1; i <= t; ++i)
		if(m >= 10 ) {m -= 10;dp[i] = dp[i - 1] + 60;}
		else {dp[i] = dp[i - 1]; m += 4;}
	
	for(reg int i = 1; i <= t ; ++i) dp[i] = dp[i] > (dp[i - 1] + 17) ? dp[i] : dp[i - 1] + 17;
	
	for(reg int i = 1; i <= t ; ++i)
		if(dp[i] >= s) {printf("Yes\n%d",i);return 0;}
		else ans = ans > dp[i] ? ans : dp[i];
	
	printf("No\n%d",ans);
	return 0;
}
