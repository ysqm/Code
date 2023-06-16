# include <cstdio>
# include <algorithm>
int n,M,T,dp[210][210],m[210],t[210];
void printd(){
	for(int i=1;i<=M;i++){
		printf("动规第%02d行：",i);
		for(int j=1;j<=T;j++)
			printf("%-4d",dp[i][j]);
		printf("\n");
	}
	system("pause")	;
}
int main(){
	scanf("%d%d%d",&n,&M,&T);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&m[i],&t[i]);
	for(int i=1;i<=n;i++){
		for(int j=M;m[i]<=j;j--){
			for(int k=T;t[i]<=k;k--){
				dp[j][k]=std::max(dp[j][k],dp[j-m[i]][k-t[i]]+1);
			}
		}
		//printd();
	}
	printf("%d",dp[M][T]);
	return 0;
} 
