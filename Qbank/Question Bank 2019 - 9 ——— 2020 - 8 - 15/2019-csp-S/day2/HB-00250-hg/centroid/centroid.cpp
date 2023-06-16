# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cstring>
using namespace std;

int x[500001];


int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int ans=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
		}
		if(n%2==0)
		{
			ans+=n*(n+1)/2;
			ans-=2*(n+1);
			printf("%d",ans);
			break;
		}
		else
		{
			ans+=n*(n+1)/2;
			ans-=n+1+n/2+1;
			printf("%d",ans);
		}
	}
	return 0;
}

