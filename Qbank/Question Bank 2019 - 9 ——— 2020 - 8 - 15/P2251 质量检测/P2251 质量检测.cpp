# include <cstdio>
# define N 1000000
# define reg register

int q[N + 42],a[N + 42],n,m;

int main()
{
	//freopen("P2251_1.in","r",stdin);
	
	scanf("%d%d",&n,&m);
	
	int h = 1,t = 0;
	
	for(int i = 1; i <= n; ++i){
		scanf("%d",&a[i]);
		while(h <= t && a[q[t]] >= a[i]) --t;
		q[++t] = i;
		while(h <= t && q[t] - q[h] >= m) ++h;
		if(i >= m) printf("%d\n",a[q[h]]);
	}
	
	return 0;
}
