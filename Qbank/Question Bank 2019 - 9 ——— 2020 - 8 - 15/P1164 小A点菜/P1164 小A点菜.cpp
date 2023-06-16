# include <cstdio>
# include <iostream>
# include <algorithm>
using namespace std;
int N,M,an[10005],sum=0,dp[105];
int main(){
	cin.sync_with_stdio(false);
	cin>>N>>M;int j=1,a;
	while(j<=N)
		cin>>an[j++];
	dp[0]=1;
	for(int i=1;i<=N;i++)
		for(j=M;j>=an[i];j--)
			dp[j]=dp[j]+dp[j-an[i]];
	cout<<dp[M];
	return 0;
} 
