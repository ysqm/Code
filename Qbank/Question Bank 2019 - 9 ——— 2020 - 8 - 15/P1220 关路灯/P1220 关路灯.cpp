# include <cstdio>
# include <algorithm>
# define N 10 
# define REG register
using namespace std;
typedef long long LL;

inline void in(LL& x)
{
	char ch = getchar();
	
	while(ch > '9' || ch < '0') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
	
}

inline LL Read()
{
	LL x = 0;char ch = getchar();
	
	while(ch > '9' || ch < '0') ch = getchar();
	
	while(ch <= '9' && ch >= '0') {x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
	
	return x;
}

inline LL _min(LL a,LL b) {return a > b ? a : b;}

LL dp[N + 42][N + 42][2],n,start,sum[N + 42],a[N + 42];

int main()
{
	in(n);in(start);
	
	for(REG int i = 1; i <= n ; ++i) {a[i] = Read();sum[i] = sum[i - 1] + Read();}
	
	for(REG int i = 1; i <= n ; ++i)
		for(REG int j = 1; j <= n ; ++j)
			dp[i][j][0] = dp[i][j][1] = 0x7f7f7f7f7f;
	
	dp[start][start][0] = dp[start][start][1] = 0;
	
	for(int l = 2;l <= n; ++l){
    	for(int i=1 ; i+l-1 <= n ; ++i){
    		int j=i+l-1;
			dp[i][j][0] = min(dp[i + 1][j][0] + (a[i + 1] - a[i]) * (sum[i] + sum[n] - sum[j]),
               				  dp[i + 1][j][1] + (a[j] - a[i]) * (sum[i] + sum[n] - sum[j]));
    		dp[i][j][1] = min(dp[i][j - 1][0] + (a[j] - a[i]) * (sum[i - 1] + sum[n] - sum[j - 1]),
               				  dp[i][j - 1][1] + (a[j] - a[j - 1]) * (sum[i - 1] + sum[n] - sum[j - 1]));
		}/*debug
		printf("区间长度%d：\n",len);
		printf("left:\n");
		printf("  ");
		for(REG int i = 1; i <= n ; ++i) printf("%-4d",i);
		printf("\n");
		for(REG int i = 1; i <= n ; ++i){
			printf("%-2d",i);
			for(REG int j = 1; j <= n ; ++j)
				if(dp[i][j][0] < 0x7f7f7f7f) printf("%-4lld",dp[i][j][0]);
				else printf("inf ");
			printf("\n");
		}
		printf("right:\n");
		printf("  ");
		for(REG int i = 1; i <= n ; ++i) printf("%-4d",i);
		printf("\n");
		for(REG int i = 1; i <= n ; ++i){
			printf("%-2d",i);
			for(REG int j = 1; j <= n ; ++j)
				if(dp[i][j][1] < 0x7f7f7f7f) printf("%-4lld",dp[i][j][1]);
				else printf("inf ");
			printf("\n");
		}
		system("pause");*/
	}
		
			
	printf("%lld",min(dp[1][n][0],dp[1][n][1]));		
	
	return 0;
}
