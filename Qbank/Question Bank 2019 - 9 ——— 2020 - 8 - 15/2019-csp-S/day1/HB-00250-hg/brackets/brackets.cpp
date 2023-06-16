# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;
int n;
char x[500001];
int f[500001];
int keep[500001];
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	cin.getline(x,sizeof(x));
	cin.getline(x,sizeof(x));
	for(int i=1;i<=n-1;i++)
	scanf("%d",&f[i]);
	for(int i=0;i<n;i++)
	{
		int left=0;
		int right=0;
		for(int j=i;j<n;j++)
		{
			if(x[j]=='(')left++;
			else right++;
			if(left==right)
			{
				for(int k=j;k<=n;k++)
				keep[k]+=k+1;
			}
		}
	}
	int ans=keep[0];
	for(int i=1;i<n;i++)
	ans^=keep[i];
	printf("%d",ans);
	return 0;
}
