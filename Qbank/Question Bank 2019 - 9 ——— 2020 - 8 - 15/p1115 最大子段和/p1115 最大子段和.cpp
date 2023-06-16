# include <cstdio>
using namespace std;
int n,sma=0;const long long INF=1e18;long long sup=-INF,an[2][200001];
int main(){
	//freopen("select.in","r",stdin);
	//freopen("select.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&an[0][i]);
		an[1][i]=an[1][i-1]+an[0][i];
		sup=an[1][i]-sma>sup?an[1][i]-sma:sup;
		sma=an[1][i]<sma?an[1][i]:sma;
	}
	printf("%lld",sup);
	return 0;
} 
