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
			cin>>pic[i][j];//�߽���1��ֻҪ���������ܹ��ɱ߳�1����С������ 
			if(pic[i][j]==1) dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
			//��̬�滮���̣���ǰ����������ֻȡ������������,+1����Ϊ��СΪ1 
			ans=max(ans,dp[i][j]); 
		}
	cout<<ans;
	return 0;
}
