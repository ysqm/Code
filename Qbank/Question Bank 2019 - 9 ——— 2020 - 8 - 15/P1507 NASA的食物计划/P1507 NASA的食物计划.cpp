# include <cstdio>
# define reg register

inline void in(int& x)
{
	x = 0;reg char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
}

inline int Read()
{
	int x = 0;reg char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + (c ^ 48);c = getchar();}
	
	return x;
}

inline int Max(const int& a,const int b){return b > a ? b : a;}

int n,dp[420][420],v[420],m[420],w[420],W,T;

int main()
{
	in(W);in(T);in(n);
	for(reg int i = 1; i <= n; ++i){in(w[i]);in(m[i]);in(v[i]);}
	for(reg int i = 1; i <= n; ++i)
		for(reg int j = W; j >= w[i]; --j)
			for(reg int k = T; k >= m[i]; --k)
				dp[j][k] = Max(dp[j][k],dp[j - w[i]][k - m[i]] + v[i]);
	printf("%d",dp[W][T]);
	return 0;
}
