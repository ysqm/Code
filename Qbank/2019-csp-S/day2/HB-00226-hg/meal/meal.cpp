# include <iostream>
# include <cstdio>
# include <cstring>
# include <cstdlib>
using namespace std;
int re(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+ch-'0';ch=getchar();}
	return s*f;
}
# define mmt(a,b) memset(a,b,sizeof(a))
const int N=1e3+77;
int n,m;
int a[N][N];
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	n=re();m=re();

		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=re();
			}
		}
	if(n==2){
		int ans=0;
		for(int j=1;j<=m;++j){
			for(int k=1;k<=m;++k){
				if(j!=k) ans+=a[1][j]*a[2][k];
			}
		}
		printf("%d",ans);
		return 0;
	}
	
	return 0;
}
