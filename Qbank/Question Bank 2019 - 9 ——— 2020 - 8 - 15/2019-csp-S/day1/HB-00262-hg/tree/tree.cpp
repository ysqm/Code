#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<iostream>
using namespace std;
int T;
int tree[2005];
int out[2005],mark;
struct E{
	int u,v;
}Edge[2005*2];
int first[2005],nt[2005];
int main()
{
	
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	int n,x,u,v;
	while(T--)
	{
		memset(first,-1,sizeof(first));
		memset(nt,-1,sizeof(nt));
		memset(out,0,sizeof(out));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&x),tree[x]=i;
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d",&u,&v);
			out[u]++,out[v]++;
			if(out[u]==n-1) mark=u;
			if(out[v]==n-1) mark=v;
		}
		sort(tree+1,tree+1+n);
		for(int i=1;i<=n;i++)	
			printf("%d ",tree[i]);
		printf("\n");
	}
	return 0;
}
