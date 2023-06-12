# include <cstdio>

int n,ma=-0x3f3f3f3f,mi=0x3f3f3f3f;

int main()
{
    scanf("%d",&n);
    
    for(register int i = 1,x; i <= n ; ++i)
    {
    	scanf("%d",&x);
    	
    	ma = ma < x ? x : ma;
    	mi = mi > x ? x : mi;
	}
	
	printf("%d",ma-mi);
	
    return 0;
}
