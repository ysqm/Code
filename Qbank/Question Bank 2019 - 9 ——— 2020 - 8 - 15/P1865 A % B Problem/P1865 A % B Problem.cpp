# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cmath>
using namespace std;
bool vis[1000010];int ans[1000010];
void zhibiao(int n){
	vis[1]=true;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
	 		ans[i]=ans[i-1]+1; //外层循环以前枚举的肯定是素数 
	 		for(int j=i*2;j<=n;j+=i){	
			 	vis[j]=true;
	 		}
	 	}
	 	else ans[i]=ans[i-1];
	}
	 
}
int main(){
	int n,m,l,r;
	scanf("%d%d",&n,&m);
	zhibiao(m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&l,&r);
		if(l<1||r<1||l>m||r>m) printf("Crossing the line\n");
		else printf("%d\n",ans[r]-ans[l-1]);
	}
	return 0;
}
