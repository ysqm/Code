# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register

int n,a[1005],sum;

inline int Min(const int a,const int b){return a < b ? a : b;}

int main()
{
    scanf("%d",&n);

    for(reg int i = 1; i <= n ; ++i) scanf("%d",a+i);
	
	std::sort(a+1,a+n+1);
	
	for(reg int i = 2; i < n ; ++i)  sum += a[i];
	
	printf("%.2lf",((double)sum)/(n-2));

    return 0;
}
