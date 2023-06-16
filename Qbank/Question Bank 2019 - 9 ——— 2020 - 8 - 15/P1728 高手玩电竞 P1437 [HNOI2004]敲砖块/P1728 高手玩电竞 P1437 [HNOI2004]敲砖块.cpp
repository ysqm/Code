# include <cstdio>
# include <algorithm>
using namespace std;
int dp[100][100],a[100][100],N,M;
void printd(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N-i+1;j++)
			printf("%-5d",a[i][j]);
		printf("\n");
	}
	system("pause");	
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N-i+1;j++){
			scanf("%d",&a[i][j]);
			a[i][j]+=a[i-1][j]+a[i-1][j+1]-a[i-2][j+1];
			//printf("%d",a[i][j]);
			//system("pause");
		}
	printd(); 
	return 0;
}
