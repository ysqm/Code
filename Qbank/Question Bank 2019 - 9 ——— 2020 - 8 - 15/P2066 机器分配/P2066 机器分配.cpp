# include <cstdio>
# include <iostream>
# include <cstdlib>
using namespace std;
long long val[20][20],dp[20][20];
int n,m;
void printd(int i,int j){
	if(i==0) return;
	for(int k=j;k>=0;k--){
		if(dp[i-1][j-k]+val[i][k]==dp[i][j]){
			printd(i-1,j-k);
			cout<<i<<" "<<k<<endl;
			break;
		}
	}
	return;
}
int main(){
	cin.sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>val[i][j];
	for(int i=1;i<=m;i++)
		dp[1][i]=val[1][i];
	for(int i=2;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=j;k++){
				if(dp[i-1][j-k]+val[i][k]>dp[i][j]){
					dp[i][j]=dp[i-1][j-k]+val[i][k];
				}
			}
		}
		//for(int i=1;i<=n;i++){
		//	for(int j=1;j<=m;j++)
		//		cout<<dp[i][j]<<" ";
		//	cout<<endl;
		//}
		//system("pause");	
	}
	cout<<dp[n][m]<<endl;
	printd(n,m);
	return 0;
}
