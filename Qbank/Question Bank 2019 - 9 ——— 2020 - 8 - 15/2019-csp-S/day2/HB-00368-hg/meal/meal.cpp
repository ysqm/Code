#include<cstdio>
typedef long long ll;
const int N=2100,M=998244353;
int a[110][N],b[N],n,m;
ll ans;
void dfs(int p,int q,int k,ll s){
	if(!a[p][q])	return ;
	++b[q];
	s=s*a[p][q]%M;
	bool f=0;
	for(int i=1;i<=m;i++){
		if(b[i]>n/2)	{--b[q];return ;}
		if(k/2<b[i])	f=1;
	}
	if(!f)	ans=(ans+s)%M;
	for(int i=1;i<=n-p;++i)
		for(int j=1;j<=m;++j)
			dfs(p+i,j,k+1,s);
	--b[q];
}
int r(){
	int o=0;char c=getchar();
	while(c<48||c>57)	c=getchar();
	while(c<58&&c>47)	o=(o<<1)+(o<<3)+(c^48),c=getchar();
	return o;
}
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	n=r();m=r();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=r();
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)
			dfs(i,j,1,1);
	printf("%lld",ans);
	return 0;
}
