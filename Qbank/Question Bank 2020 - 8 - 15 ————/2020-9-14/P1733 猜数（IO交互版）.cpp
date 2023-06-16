# include <cstdio>

int main()
{
	register int l = 1,r = 1e9,mid,opt;
	while(1)
	{
		mid = (l+r)>>1;
		printf("%d\n",mid);
		fflush(stdout);
		scanf("%d",&opt);
		if(opt == 0) return 0;
		else if(opt == -1) l = mid+1;
		else if(opt == 1) r = mid-1;
	}
}