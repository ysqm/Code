# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register

double ans = 0,a[7],n;

int main()
{
    scanf("%lf%lf%lf%lf%lf%lf%lf",a,a+1,a+2,a+3,a+4,a+5,a+6);

    n = (*(a))+(*(a+1))+(*(a+2))+(*(a+3))+(*(a+4))+(*(a+5))+(*(a+6));

    ans = a[0]/n*a[1]/(n-1)*a[2]/(n-2)*a[3]/(n-3)*a[4]/(n-4)*a[5]/(n-5)*5040;

    printf("%.3lf",ans*a[6]);

    return 0;
}