# include <cstdio>
# include <iostream>
# include <functional>
# include <algorithm>
# include <cstdlib>
# include <vector>
# include <set> 
using namespace std;
typedef unsigned long long LL;
const LL mod=998244353,N=100000;
inline int re(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=x*10+(c-'0');c=getchar();}
	return x*f;
}
LL sum=0,nsu=0,ans,s[1000];
int a[5*N+42];
LL type,n,k;
LL dfs(int u,int i){
	LL su=0;int j=i;
	for(;j<=n;j++){
		if(a[j]+su>=u) {su+=a[j];
		return su*su+dfs(su,j+1);}
		else {su=su+a[j];}
	}
	if(j==n&&su+a[j]<u)return 100000;
}
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	n=re();type=re();
	for(int i=1;i<=n;i++){
		a[i]=re();s[i]=s[i-1]+a[i];
	}
	ans=dfs(a[1],2)+a[1]*a[1];
	for(int i=2;i<=n;i++){
		ans=min(dfs(s[i],i+1)+s[i]*s[i],ans);
	}
	printf("%llu",ans);
	return 0;
}
