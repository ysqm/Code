# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 100000

double f1[N+5],f2[N+5],p;
int n;

int main()
{
    scanf("%d",&n);
    f1[0] = f2[0] = 0;
    for(int i = 1; i <= n ; ++i)
    {
        scanf("%lf",&p);
        f1[i] = (f1[i-1]+1)*p;
        f2[i] = f2[i-1]+(2*f1[i-1]+1)*p;
    }
    printf("%lf",f2[n]);
    return 0;
}
