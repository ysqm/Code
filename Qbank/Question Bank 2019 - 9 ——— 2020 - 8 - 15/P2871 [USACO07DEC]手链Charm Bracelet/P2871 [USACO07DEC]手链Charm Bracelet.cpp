# include <cstdio>

inline int in(int& x)
{
	x = 0;char c = getchar();
	
	while(c < '0' && c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
	
	return x;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}

int n,dp[13000],m;

int main()
{
	in(n);in(m);
	for(register int i = 1,w,v; i <= n; ++i){
		in(w);in(v);
		for(register int j = m; j >= w; --j)
			dp[j] = Max(dp[j],dp[j - w] + v);
	}
	printf("%d",dp[m]);
	return 0;
}
