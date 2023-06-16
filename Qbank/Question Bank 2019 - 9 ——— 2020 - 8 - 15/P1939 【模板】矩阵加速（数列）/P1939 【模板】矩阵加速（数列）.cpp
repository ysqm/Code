# include <cstdio>
# include <cstring>
# include <algorithm>
# include <iostream>
# define N 5
using namespace std;
const long long mod=1e9+7;
struct mic{
	long long  sq[N][N];
} ans,base;
mic mul(mic a,mic b){//m*n
	long long temp;mic c;
	memset(c.sq,0,sizeof(c.sq));
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++){
			temp=0;
			for(int k=1;k<=3;k++) {
				temp+=(a.sq[i][k]%mod)*(b.sq[k][j]%mod);temp%=mod;
			}
			c.sq[i][j]=temp%mod;
		}
	return c;
}
//long long ans[3],base[3][3],an[3],b[3][3];
int main(){
	int t;
	long long p;
	scanf("%d",&t);
	while(t--){
		memset(base.sq,0,sizeof(base.sq));memset(ans.sq,0,sizeof(ans.sq));
		//base.sq[2][1]=1;base.sq[3][2]=1;base.sq[1][3]=1;base.sq[3][3]=1;ans.sq[1][1]=1;ans.sq[1][2]=1;ans.sq[1][3]=1;
		base.sq[1][1] = base.sq[1][3] = base.sq[2][1] = base.sq[3][2] = 1;ans.sq[1][1]=1;ans.sq[2][2]=1;ans.sq[3][3]=1;
		//base[2][2]=1;base[2][0]=1;base[1][2]=1;base[0][1]=1;ans[0]=1;ans[1]=1;ans[2]=1;
		scanf("%lld",&p);
		if(p<=3) {
			printf("1\n");continue;
		}
		if(p!=1) {
			while(p){
					if(p&1){
					 	ans=mul(ans,base);
					 	//an[0]=ans[0]*base[0][0]+ans[1]*base[0][1]+ans[2]*base[0][2];
					 	//an[1]=ans[0]*base[1][0]+ans[1]*base[1][1]+ans[2]*base[1][2];
					 	//an[2]=ans[0]*base[2][0]+ans[1]*base[2][1]+ans[2]*base[2][2];
					}
					base=mul(base,base);
					p>>=1;
				}
		}
		printf("%d\n",ans.sq[2][1]);
	}
	return 0;
} 
