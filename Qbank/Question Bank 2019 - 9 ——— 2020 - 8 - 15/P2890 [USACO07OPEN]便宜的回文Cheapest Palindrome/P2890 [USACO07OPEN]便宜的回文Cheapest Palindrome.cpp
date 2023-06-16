# include <cstdio>
# include <algorithm>
# include <cmath>
# include <cstring>
# include <iostream>
# define REG register
# define LL long long
# define N 3010 
# define inf 0x6f6f6f6f6f6f66f
using namespace std;

inline void in(LL& x)
{
	x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();

	while(ch <= '9' && ch >= '0'){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
} 

inline LL r()
{
	LL x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();

	while(ch <= '9' && ch >= '0'){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}

LL cost['z' + 42],dp[N + 42][N + 42],n,m;
char ch[N + 42],pos;

int main()
{
	in(n);in(m);
	scanf("%s ",ch);
	
	LL a,b;
	
	
	/*for(REG int i = 0;i <= N; ++i)
		for(REG int j = 0; j <= N; ++j)
			dp[i][j] = inf;
	*/
	while(n--){
		std::cin >> pos >> a >> b; 
		cost[pos - 96] = min(a,b);
	}
	
	//cost[0] = inf;
	
	for(int i = 0 ; i < m; ++i) dp[i][i] = 0;
	
	for(REG int len = 2; len <= m ; ++len){
		for(int L = 0; L + len <= m; ++L){
			int R = L + len - 1;
			dp[L][R] = inf;
			if(ch[L] == ch[R] ) dp[L][R] = dp[L + 1][R - 1];
			else dp[L][R] = min(dp[L + 1][R] + cost[ch[L] - 96],dp[L][R - 1] + cost[ch[R] - 96]);
		}
	}
	
	printf("%lld\n",dp[0][m - 1]);
	return 0;
}
