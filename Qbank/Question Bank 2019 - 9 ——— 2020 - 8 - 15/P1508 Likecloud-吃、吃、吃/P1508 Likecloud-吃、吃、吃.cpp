# include <cstdio>
# include <algorithm>
using namespace std;
int an[210][210],m,n,dp[210][210];
void printd(){
	for(int i=1;i<=m;i++){
		printf("�����%02d�У�",i);
		for(int j=1;j<=n;j++)
			printf("%-4d",dp[i][j]);
		printf("\n");
	}
	system("pause")	;
}//������ 
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&an[i][j]);
	for(int i=1;i<=n;i++)
		dp[1][i]=an[1][i];//dp[1][i]=an[1][n];һ��n�����Ұ��Сʱ��������һ������ 
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(j!=1&&j!=n)
				dp[i][j]=max(max(dp[i-1][j-1],dp[i-1][j+1]),dp[i-1][j])+an[i][j];
				else if(j==1)
					dp[i][j]=max(dp[i-1][j+1],dp[i-1][j])+an[i][j];
					else dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+an[i][j];
		}
		//printd();
	}int k=n/2+1;
	printf("%d",max(max(dp[m][k-1],dp[m][k+1]),dp[m][k]));
}
