# include <cstdio>
# include <algorithm>
using namespace std;
const int fx[]={0,-2,-1,1,2,2,1,-1,-2};
const int fy[]={0,1,2,2,1,-1,-2,-2,-1};
long long dp[101][101];
int sx,sy,hx,hy,dx,dy;
bool book[101][101];
int main(){
	scanf("%d%d%d%d",&sx,&sy,&hx,&hy);
	sx++;sy++;hx++;hy++;
	for(int i=0;i<=8;i++){
		dx=hx+fx[i];dy=hy+fy[i];
		if(dx>0&&dy>0) {
			book[dx][dy]=true;
		}
	}
	dp[1][1]=1;
	for(int i=1;i<=sx;i++)
		for(int j=1;j<=sy;j++){
			if(book[i][j]) continue;
			dp[i][j]+=dp[i-1][j]+dp[i][j-1];
		}
	printf("%lld",dp[sx][sy]);
	return 0;
}
