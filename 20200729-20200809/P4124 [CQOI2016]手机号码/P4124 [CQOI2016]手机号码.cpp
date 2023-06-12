# include <algorithm>
# include <cstring>
# include <cstdio>
# include <cmath>
# define reg register
# define LL long long
using namespace std;

int num[42];
LL n,m,dp[42]/*�ڼ�λ*/[42][42]/*ǰ��������Ϊ��*/[2][2]/*�Ƿ�4��8*/[2]/*�Ƿ�������һ������*/[2]/*�Ƿ�С��n*/;

LL dfs(const int cur,const int a,const int b,const bool Danger_4,const bool Danger_8,const bool Legal,const bool legal)
{//a��ǰһ������
	if(Danger_4 && Danger_8) return 0;
	if(cur == 0) return Legal;
	if(~dp[cur][a][b][Danger_4][Danger_8][Legal][legal]) return dp[cur][a][b][Danger_4][Danger_8][Legal][legal];
	
	LL res = 0;int limit = legal ? 9 : num[cur];
	
	for(reg int i = 0; i <= limit ; ++i) res += dfs(cur-1,i,a,Danger_4 || i == 4,Danger_8 || i == 8,Legal || (i == b && b == a),legal || i < limit);
	
	return dp[cur][a][b][Danger_4][Danger_8][Legal][legal] = res;
}

LL Query(LL x)
{
	if(x < 1e10) return 0;
	
	memset(dp,-1,sizeof(dp));
	
	int len = 0;
	
	while(x)
	{
		num[++len] = x%10;
		x /= 10;
	}
	
	LL res = 0;
	
	for(reg int i = 1; i <= num[len] ; ++i) res += dfs(len-1,i,0,i == 4,i == 8,0,i < num[len]);
	
	return res;
}

int main()
{
	scanf("%lld%lld",&n,&m);
	
	printf("%lld",Query(m)-Query(n-1));
	
	return 0;
} 

