# include <cstdio>

int a[100042];

int main()
{
	freopen("2.out","r",stdin);
	
	int n = 100026;
	
	for(register int i = 1; i <= n ; ++i) scanf("%d",&a[i]);
	
	for(register int i = 2; i <= n ; ++i)
		if(a[i] < a[i+1]) puts("NO");
} 
