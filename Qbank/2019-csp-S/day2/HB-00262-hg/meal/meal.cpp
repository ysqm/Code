#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MOD=998244353;
int a[105][2005];
int use[2005];
int n,m,ans=-1;
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int o=2;o<=n;o++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int i1=1;i1<=m;i1++)
			{
				memset(use,0,sizeof(use));
				int temp=a[i][i1],sum=1;
				use[i1]++;
				for(int j=i+1;j<=n&&sum<=o/2;j++)
				{
					for(int k=1;k<=m;k++)
					{
						if(use[k]<o/2||sum==1)
						temp+=(a[i][i1]*a[j][k])%MOD,temp%=MOD;
						ans=max(ans,temp);
						if(a[j][k]) sum++,use[k]++;
					}	
				}
			}	
		}		
	}
	printf("%d",ans);
	return 0;		
}
