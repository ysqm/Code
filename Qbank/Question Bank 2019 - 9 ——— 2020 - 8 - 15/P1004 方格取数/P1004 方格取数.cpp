# include <cstdio>
# include <algorithm>
using namespace std;
int dp[11][11][11][11],a[11][11];
int main(){
	int n,x,y,b;
	scanf("%d",&n);
	while(scanf("%d%d%d",&x,&y,&b),x!=0&&y!=0&&b!=0){
		a[x][y]=b;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i][j-1][k][l-1]),max(dp[i][j-1][k-1][l],dp[i-1][j][k][l-1]))+a[i][j]+a[k][l];
					if(i==k&&j==l) dp[i][j][k][l]-=a[k][l];
				}
			}
		}
	}
	printf("%d",dp[n][n][n][n]);
	return 0;
} 
