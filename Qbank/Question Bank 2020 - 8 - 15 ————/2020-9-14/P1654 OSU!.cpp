# include <cstdio>
# define LL long long
# define N 100000

double p,f1[N+5],f2[N+5],f3[N+5];
int n;

int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n ; ++i)
    {
        scanf("%lf",&p);
        f1[i] = (f1[i-1]+1)*p;
        f2[i] = (f2[i-1]+2*f1[i-1]+1)*p;
        f3[i] = f3[i-1]+(3*f2[i-1]+3*f1[i-1]+1)*p;
        //f3[i] = f3[i-1]*(1-p)+(f3[i-1]+3*f2[i-1]+3*f1[i-1]+1)*p = f3[i-1]+(3*f2[i-1]+3*f1[i-1]+1)*p
    }
    printf("%.1lf",f3[n]);
    return 0;
}
