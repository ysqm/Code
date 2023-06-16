# include <cstdio>
# include <algorithm>
# include <cmath>
int n,m,dp[100005][33],l,r;
void RMQ(){
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++)
			dp[i][j]=std::max(dp[i][j-1],dp[i+(1<<(j-1))][j-1])/*,printf("%d ",dp[i][j]);
		printf("\n");
		system("pause")*/;
	}
		
	return;	
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&dp[i][0]);
	RMQ();
	while(m--){
		scanf("%d%d",&l,&r);
		int k=log2(r-l+1);
		printf("%d\n",std::max(dp[l][k],dp[r-(1<<k)+1][k]));
	}
	return 0;
}
