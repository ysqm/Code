# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cmath>
using namespace std;
bool vis[10010];
void zhibiao(int n){
	vis[1]=true;
	for(int i=2;i<=n;i++)
		if(!vis[i]) for(int j=i*2;j<=n;j+=i) vis[j]=true;
}
int main(){
	int n,k;bool flag=true;
	scanf("%d%d",&n,&k);
	zhibiao(n);
	for(int i=2;i+k<=n;i++){
		if(!vis[i]&&!vis[i+k]) {
			flag=false;
			printf("%d %d\n",i,i+k);
		}
	}
	if(flag) printf("empty");
	/*for(int i=1;i<=n;i++){
		if(!vis[i]) printf("Y %d\n",i);
		else printf("N %d\n",i);
	}*/
	return 0;
}
