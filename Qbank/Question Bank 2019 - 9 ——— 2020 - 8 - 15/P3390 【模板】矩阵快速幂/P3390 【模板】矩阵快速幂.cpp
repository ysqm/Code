# include <cstdio>
# include <cstring>
# define N 105
using namespace std;
int n;long long k;
const long long mod=1e9+7;
struct mic{
	long long  sq[N][N];
} ans,bn;
mic mul(mic a,mic b){
	long long temp;mic c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			temp=0;
			for(int k=1;k<=n;k++) {
				temp+=(a.sq[i][k]%mod)*(b.sq[k][j]%mod);temp%=mod;
			}
			c.sq[i][j]=temp%mod;
		}
	return c;
}
int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lld",&bn.sq[i][j]);
	for(int i=1;i<=n;i++) ans.sq[i][i]=1;
	while(k){
		if(k&1) ans=mul(ans,bn);	
		k>>=1;
		bn=mul(bn,bn);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%lld ",ans.sq[i][j]);
		printf("\n");
	}
	return 0;
}
