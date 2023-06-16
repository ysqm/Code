# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define LL long long

inline int Min(const int x,const int y){return x < y ? x : y;}

LL ans;
int n,k;

int main()
{
    scanf("%d%d",&n,&k);
    
    ans = (LL)n*k;

    n = Min(n,k);

    for(reg int l = 1,r; l <= n ; l=r+1)
    {
        r = Min(n,k/(k/l));
        ans -= (k/l)*(LL)(l+r)*(LL)(r-l+1)>>1;
    }

    printf("%lld",ans);

    return 0;
}
