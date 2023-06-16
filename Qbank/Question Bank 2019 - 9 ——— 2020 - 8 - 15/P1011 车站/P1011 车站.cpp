# include <cstdio>
# define reg register

int a1,n,m,x;
int a[42] = {0,1,1,2,2,3,4,6,9,14,22,35,56,90,145,234,378,611,988,1598,2585};
int b[42] = {0,0,0,0,1,2,4,7,12,20,33,54,88,143,232,376,609,986,1596,2583,4180};

int main()
{
	//freopen("1.txt","w",stdout);
	
	scanf("%d%d%d%d",&a1,&n,&m,&x);
	
	printf("%d",a1*a[x]+b[x]*((m-a1*a[n-1])/b[n-1]));
	
	/*a[2][1] = b[2][1] = c[2][0] = c[1][0] = a[1][0] = 1;
	
	for(reg int i = 3; i <= 25; ++i)
	{
		a[i][1] = a[i-1][1]+a[i-2][1];
		a[i][0] = a[i-1][0]+a[i-2][0];
		b[i][1] = a[i-1][1];
		b[i][0] = a[i-1][0];
		c[i][1] = c[i-1][1]+a[i][1]-b[i][1];
		c[i][0] = c[i-1][0]+a[i][0]-b[i][0];
	}
	
	for(reg int i = 1; i <= 25 ; ++i) printf("%da+%db,%da+%db,%da+%db\n",a[i][0],a[i][1],b[i][0],b[i][1],c[i][0],c[i][1]);
	*/
	return 0;
} 
