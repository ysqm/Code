# include <cstdio>
# include <algorithm>
# define N 52
using namespace std;
int dp[N][N][N][N],a[N][N],m,n;
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				for(int l=j+1;l<=n;l++)
					dp[i][j][k][l]=max(dp[i-1][j][k][l-1],max(dp[i][j-1][k-1][l],max(dp[i-1][j][k-1][l],dp[i][j-1][k][l-1])))+a[i][j]+a[k][l];	
	printf("%d",dp[m][n-1][m-1][n]);
	return 0;
}
