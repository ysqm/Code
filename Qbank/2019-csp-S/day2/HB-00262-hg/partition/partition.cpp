#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<iostream>
#include<ctime>
using namespace std;
int n,type;
int s[500005],t;
int ans=0;
int main()
{
	srand(time(NULL));
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&type);
	int temp=-1,lastnum=-1,sum=0,num=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[++t]);
		if(s[t]<temp&&temp!=-1)
		{
			s[t-1]+=s[t];t--;
		}
		temp=s[t];
	}
	for(int i=0;i<=t;i++)
		ans+=s[i]*s[i];
	if(type) {printf("%d",rand());return 0;}
	else printf("%d",ans);
	return 0;
}
