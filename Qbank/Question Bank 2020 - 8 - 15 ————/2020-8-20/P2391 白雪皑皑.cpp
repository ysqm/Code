# include <ctime>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg //register
# define LL  long long
# define N 1000000 

int n,m,p,q,Pre[N+5],color[N+5];

int main()
{
    scanf("%d%d%d%d",&n,&m,&p,&q);

    reg int l,r;

    for(reg int i = m; i >= 1 ; --i)
    {
        l = (i*(LL)p+q)%n+1;r = (i*(LL)q+p)%n+1;
        l > r && (l^=r^=l^=r);++r;
        for(reg int j = l; j < r ;)
        {
            if(color[j]) j = Pre[j];
            else
            {
                color[j] = i;
                Pre[j] = r;
                ++j;
            }
        }
    }

    for(reg int i = 1; i <= n ; ++i) printf("%d\n",color[i]);

    return 0;
}
