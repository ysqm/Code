# include <cstdio>
long long read()
{
	long long x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
int pan;
long long n,k;
long long l,r,mid;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	n=read();
	k=read();
	r=1;
	for(int i=1;i<n;++i) r*=2;
	r--;
	r*=2;
	r++;
	if(k==l)
	{
		for(int i=1;i<=n;++i) printf("0");
		return 0;
	}
	if(k==r)
	{
		printf("1");
		for(int i=1;i<n;++i) printf("0");
		return 0;
	}
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(mid<=k)
		{
			l=mid;
			if(!pan) printf("1");
			else printf("0");
			pan=1;
		}
		else
		{
			r=mid-1;
			if(!pan) printf("0");
			else printf("1");
			pan=0;
		}
	}
	return 0;
}
