# include <cstdio>
# include <iostream>
# include <functional>
# include <algorithm>
# include <cstdlib>
# include <vector>
# include <set> 
using namespace std;
typedef long long LL;
const LL mod=998244353,N=100,M=2000;
inline int re(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=x*10+(c-'0');c=getchar();}
	return x*f;
}
int k,m,n,t[N+5][M+5],book[M+42];
bool vis[N+42];
LL  ans;
LL dfs(int i,int j,int c,int k){
	
	if(t[i][j]==0||book[j]>k/2) return 0;//||i>n||i<1
	if(c==k) return t[i][j];
	LL sum=0;
	for(int r=1;i+r<=n;r++){
		for(int l=1;l<=m;l++){
			book[l]++;
			sum=(sum+dfs(i+r,l,c+1,k))%mod;
			book[l]--;	
		}
	}
	
	return (t[i][j]*sum)%mod;
}
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	n=re();m=re();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			t[i][j]=re();
			//sum[i][j]=(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+t[i][j])%mod;
		}
	for(int i=2;i<=n;i++)
		for(int r=1;r<=n-i+1;r++)
			for(int l=1;l<=m;l++){
				if(t[r][l]==0)continue;
				book[l]++;
				ans=(ans+dfs(r,l,1,i))%mod;
				book[l]--;
			}
				
	printf("%lld",ans);
	return 0;
}
