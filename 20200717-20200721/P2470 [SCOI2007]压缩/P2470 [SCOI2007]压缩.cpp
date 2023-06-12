# include <cstdio>
# include <queue>
# include <cstring>
# define reg register 
# define N 50
typedef long long LL;
typedef unsigned long long ULL;

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return f == -1 ? -x : x;
}

char s[52];
int n,dp[N+5][N+5][2];

inline bool check(const int l,const int r)
{
	if((r-l+1)&1) return 0;
	else 
		for(reg int i = l,mid = (r+l)>>1; i <= mid ; ++i)
			if(s[i] != s[mid+i-l+1]) return 0;
	return 1;
}

inline int Min(const int a,const int b){return a < b ? a : b;}

int main()
{
	scanf("%s",s+1);
	
	n = strlen(s+1);
	
	memset(dp,0x3f,sizeof(dp));
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = i; j <= n ; ++j)
		 	dp[i][j][0] = dp[i][j][1] = j-i+1;
		 	
	for(reg int i = 2; i <= n ; ++i)
		for(reg int l = 1,r = i; r <= n; ++r,++l)
		{
			if(check(l,r)) dp[l][r][0] = Min(dp[l][r][0],dp[l][(l+r)>>1][0]+1);
			//直接折叠,最开始的M不需要写，所以不用加一 
			for(reg int j = l; j < r ; ++j)
				dp[l][r][0] = Min(dp[l][r][0],dp[l][j][0] + r - j);
			//l->r从l->j内折叠加上后面直接补上字母的情况。
			//注意的是在此处其实已经加上了补 M 所需要的字数. 
			for(reg int k = l; k < r ; ++k)
				dp[l][r][1] = Min(dp[l][r][1],Min(dp[l][k][0],dp[l][k][1]) + Min(dp[k+1][r][0],dp[k+1][r][1]) + 1);	 
			//补上折叠的M 
		}
		
	
		
	printf("%d",Min(dp[1][n][0],dp[1][n][1]));
	
	return 0;
}
