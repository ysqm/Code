# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;
int N;
int n;
int x[2001];
bool fa[2001][2001];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&N);
	while(N--)
	{
		memset(fa,0,sizeof(fa));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
		bool lian=false;
		for(int i=1;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			fa[a][b]=1;
			fa[b][a]=1;
			fa[a][0]++;
			fa[b][0]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(fa[i][0]==n-1)
			lian=true;
		}
		//if(lian==true)
		{
			sort(x+1,x+1+n);
			for(int i=1;i<=n;i++)
			printf("%d ",x[i]);
			printf("\n");
		}
	}
	return 0;
}
