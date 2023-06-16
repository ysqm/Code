# include <cstdio>
# include <iostream>
using namespace std;
bool road[22][22];
int an[22],dp[2][22],n,now,roa,ans;
int main(){
	cin.sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>an[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cin>>road[i][j];
		}
	}
	for(int i=n;i>0;i--){
		now=0;
		for(int j=n;j>=i;j--){
			if(road[i][j]&&dp[0][j]>now){
				now=dp[0][j];roa=j;
			}
			dp[0][i]=now+an[i];
			dp[1][i]=roa;
		}
	}
	for(int i=1;i<=n;i++){
		if(dp[0][i]>dp[0][ans]){
			ans=i;
		}
	}int j=ans;
	for(;an[j]!=dp[0][j];j=dp[1][j])
			cout<<j<<" ";
	cout<<j<<endl<<dp[0][ans];
	return 0;
}

