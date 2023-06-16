# include <cstdio>
# include <algorithm>
# include <cstdio>
# include <algorithm>
# include <iostream>
# include <cstring>
using namespace std;
using namespace std;
int N,m;
typedef struct{int v,p;} dan;
dan b;int dp[10010];
int main(){
	scanf("%d%d",&N,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&b.v,&b.p);
		for(int j=N;j>=0;j--)
			if(j>b.v) dp[j]=max(dp[j-b.v]+b.v*b.p,dp[j]);	
	}	
	printf("%d",dp[N]);
	return 0;
} 
