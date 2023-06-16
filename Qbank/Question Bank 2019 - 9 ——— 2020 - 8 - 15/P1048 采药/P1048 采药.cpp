# include <cstdio>
# include <algorithm>
using namespace std;
int dp[1010];
int main(){
	int M,s,t,T;
	scanf("%d%d",&T,&M);
	for(int i=1;i<=M;i++){
		scanf("%d%d",&t,&s);
		for(int j=T;j>=t;j--){
			dp[j]=max(dp[j],dp[j-t]+s);
		}
	}
	printf("%d",dp[T]);
	return 0;
} 
