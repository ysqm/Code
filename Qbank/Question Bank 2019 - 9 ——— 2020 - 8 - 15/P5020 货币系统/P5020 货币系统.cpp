# include <cstdio>
# include <algorithm>
# include <iostream>
# include <cstring>
using namespace std;
int T,a[1010],ans,n,m,vis[25010],len;
void printd(){
	for(int i=1;i<=len;i++)
	{	if(i%10==1) printf("\n");
		printf("%-5d",vis[i]);
	}
		
	system("pause");
}
int main(){
	scanf("%d",&T);
	//freopen("testdata.in","r",stdin);
	while(T--){
		ans=0;
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			vis[a[i]]=1;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=a[i];j<=a[n];j++){
				vis[j]+=vis[j-a[i]];
			}
		}
		//printd();
		for(int i=1;i<=n;i++){
			if(vis[a[i]]>1) ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
