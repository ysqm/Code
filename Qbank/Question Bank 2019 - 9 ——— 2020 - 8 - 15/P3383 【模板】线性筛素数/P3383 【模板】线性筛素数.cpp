# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cmath>
using namespace std;
bool vis[10000010];
void zhibiao(int n){
	vis[1]=true;
	for(int i=2;i<=n;i++)
	 if(!vis[i]) for(int j=i*2;j<=n;j+=i) vis[j]=true;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	zhibiao(n);
	for(int i=0;i<m;i++){
		scanf("%d",&n);
		if(vis[n]) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
