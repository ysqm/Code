# include <cstdio>
# include <cstring>
# include <algorithm>
# include <iostream>
using namespace std;
int n,m,pic[105][105],dp[105][105],ans=0;
int main(){
	cin.sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>pic[i][j];//边界是1，只要有数，就能构成边长1的最小正方形 
			if(pic[i][j]==1) dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
			//动态规划方程，当前极大正方形只取决于这三个点,+1是因为最小为1 
			ans=max(ans,dp[i][j]); 
		}
	cout<<ans;
	return 0;
}
